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
        [switch]$UseClang = $false,
        [switch]$UseUnityBuild = $false
    )

    $buildFolder = "build_temp"

    if (Test-Path -Path $buildFolder) {
        Remove-Item $buildFolder -Recurse -Force
    }
    mkdir $buildFolder | Out-Null
    Push-Location $buildFolder

    $compilerName = Get-CompilerName $UseClang.IsPresent    
    Write-Host "Measuring with [$compilerName $(IIf $UseCoil "Coil" "-") $(IIf $UseUnityBuild "Unity" "-")]"

    $coil = [int]$UseCoil.IsPresent
    $unityBuild = [int]$UseUnityBuild.IsPresent
    
    Write-Host "Running CMake..."
    if ($UseClang) {
        $env:CC="clang-cl"
        $env:CXX="clang-cl"
    } else {
        $env:CC=""
        $env:CXX=""
    }
    Invoke-Expression "cmake -DTEST_COMP_PERF=1 -DTEST_COMP_PERF_USE_COIL=$coil -DCMAKE_UNITY_BUILD=$unityBuild -GNinja .." | Out-Null

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
        [bool]$UseClang,
        [bool]$UseUnityBuild
    )

    $compilerName = Get-CompilerName $UseClang

    $base = Measure-SingleBuild -Count $Count -UseClang:$UseClang -UseUnityBuild:$UseUnityBuild
    $coil = Measure-SingleBuild -Count $Count -UseCoil -UseClang:$UseClang -UseUnityBuild:$UseUnityBuild

    return @(
        @("Base ($compilerName)", $base),
        @("Coil ($compilerName)", $coil)
    )
}

if ($null -eq $env:vsinstalldir) {
    Write-Error "Visual Studio environment isn't set up"
    Exit 1
}

Push-Location ../..

$BuildCounts = 2

$results = @()
$results += Measure-Builds $BuildCounts -UseClang:$false -UseUnityBuild:$false
$results += Measure-Builds $BuildCounts -UseClang:$true -UseUnityBuild:$false
$results += Measure-Builds $BuildCounts -UseClang:$false -UseUnityBuild:$true
$results += Measure-Builds $BuildCounts -UseClang:$true -UseUnityBuild:$true

foreach ($pair in $results) {
    Write-BuildStatistics $pair[0] $pair[1]
}

Pop-Location
