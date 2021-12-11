function IIf($If, $IfTrue, $IfFalse) {
    If ($If) {If ($IfTrue -is "ScriptBlock") {&$IfTrue} Else {$IfTrue}}
    Else {If ($IfFalse -is "ScriptBlock") {&$IfFalse} Else {$IfFalse}}
}

function Get-CompilerName([bool]$IsClang) {
    return $(If ($IsClang) {"Clang"} Else {"MSVC"})
}

function Measure-SingleBuild {
    param (
        [int]$Count = 1,
        [switch]$UseCoil = $false,
        [switch]$UseObjects = $false,
        [switch]$UseClang = $false
    )

    $buildFolder = "build_temp"

    if (Test-Path -Path $buildFolder) {
        Remove-Item $buildFolder -Recurse -Force
    }
    mkdir $buildFolder | Out-Null
    Push-Location $buildFolder

    $compilerName = Get-CompilerName $UseClang.IsPresent    
    Write-Host "Measuring with [$compilerName $(IIf $UseCoil "Coil" "-") $(IIf $UseObjects "Objects" "-")]"

    $coil = [int]$UseCoil.IsPresent
    $objects = [int]$UseObjects.IsPresent
    
    Write-Host "Running CMake..."
    if ($UseClang) {
        $env:CC="clang-cl"
        $env:CXX="clang-cl"
    } else {
        $env:CC=""
        $env:CXX=""
    }
    Invoke-Expression "cmake -DTEST_COMP_PERF=1 -DTEST_COMP_PERF_USE_COIL=$coil -DTEST_COMP_PERF_USE_OBJECTS=$objects -GNinja .." | Out-Null

    Write-Host "Building 0/$Count (will be discarded)..."
    ninja | Out-Null
    
    $durations = @()

    for ($i = 1 ; $i -le $Count ; $i++) {
        Write-Host "Building $i/$Count..." -NoNewline
        ninja -t clean | Out-Null
        $result = (Measure-Command { ninja | Out-Null })."TotalSeconds"
        Write-Host " finished in $result seconds"
        $durations += $result
    }

    Write-Host

    Pop-Location
    if (Test-Path -Path $buildFolder) {
        Remove-Item $buildFolder -Recurse -Force
    }
    
    return $durations
}

function Measure-Median($Values) {
    $Values = $Values | Sort-Object

    $Count = $Values.Count
    $MiddleIndex = $Count / 2
    
    if ($Count % 2) {
        return $Values[[math]::Floor($MiddleIndex)]
    }
    
    return 0.5 * ($Values[$MiddleIndex] + $Values[$MiddleIndex - 1])
}

function Measure-BuildResults($Durations) {
    $res = $Durations | Measure-Object -Average -Maximum -Minimum
    $res | Add-Member "Median" $(Measure-Median $Durations)
    return $res | Select-Object Median, Average, Minimum, Maximum
}

function Write-BuildStatistics {
    param (
        $Name,
        $Durations
    )
    
    Write-Host "${Name}:"
    Measure-BuildResults $Durations | Out-Host
}

function Measure-Builds {
    param (
        [int]$Count,
        [bool]$UseClang
    )

    $compilerName = Get-CompilerName $UseClang

    $base = Measure-SingleBuild -Count $Count -UseClang:$UseClang
    $coil = Measure-SingleBuild -Count $Count -UseCoil -UseClang:$UseClang
    $coilWithObjects = Measure-SingleBuild -Count $Count -UseObjects -UseCoil -UseClang:$UseClang

    return @(
        @("Base ($compilerName)", $base),
        @("Coil ($compilerName)", $coil),
        @("Coil with objects ($compilerName)", $coilWithObjects)
    )
}

if ($null -eq $env:vsinstalldir) {
    Write-Error "Visual Studio environment isn't set up"
    Exit 1
}

Push-Location ../..

$BuildCounts = 2

$results = @()
$results += Measure-Builds $BuildCounts -UseClang:$false
$results += Measure-Builds $BuildCounts -UseClang:$true

foreach ($pair in $results) {
    Write-BuildStatistics $pair[0] $pair[1]
}

Pop-Location
