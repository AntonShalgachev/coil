function IIf($If, $IfTrue, $IfFalse) {
    If ($If) {If ($IfTrue -is "ScriptBlock") {&$IfTrue} Else {$IfTrue}}
    Else {If ($IfFalse -is "ScriptBlock") {&$IfFalse} Else {$IfFalse}}
}

function Get-ConfigurationName([bool]$UseCoil, [bool]$UseClang, [bool]$UseUnityBuild) {
    $compilerName = $(If ($UseClang) {"Clang"} Else {"MSVC"})
    $coilName = $(IIf $UseCoil "Coil" "-")
    $unityBuildName = $(IIf $UseUnityBuild "Unity" "-");
    return "$compilerName $coilName $unityBuildName"
}

function Measure-SingleBuild {
    param (
        [int]$Count = 1,
        [switch]$UseCoil = $false,
        [switch]$UseClang = $false,
        [switch]$UseUnityBuild = $false
    )
    $configurationName = Get-ConfigurationName $UseCoil $UseClang $UseUnityBuild
    Write-Host "Measuring configuration [$configurationName]"
    $buildFolder = "build_temp/$configurationName"

    if (Test-Path -Path $buildFolder) {
        Remove-Item $buildFolder -Recurse -Force
    }
    mkdir $buildFolder | Out-Null
    Push-Location $buildFolder

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
    Invoke-Expression "cmake -DTEST_COMP_PERF=1 -DTEST_COMP_PERF_USE_COIL=$coil -DCMAKE_UNITY_BUILD=$unityBuild -GNinja ../.." | Out-Null

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

Push-Location ../..

$buildCounts = 10
$coilOptions = @($false, $true)
$clangOptions = @($false, $true)
$unityBuildOptions = @($false, $true)

$results = @()
foreach ($useClang in $clangOptions) {
    foreach ($useUnityBuild in $unityBuildOptions) {
        foreach ($useCoil in $coilOptions) {
            $configurationName = Get-ConfigurationName $useCoil $useClang $useUnityBuild
            $result = Measure-SingleBuild -Count $buildCounts -UseCoil:$useCoil -UseClang:$useClang -UseUnityBuild:$useUnityBuild

            $results += [PSCustomObject]@{
                Name = "[$configurationName]"
                Durations = $result
            }
        }
    }
}

foreach ($configuration in $results) {
    $name = $configuration.Name
    $durations = $configuration.Durations

    Write-Host "${name}:"
    Measure-BuildResults $durations | Out-Host
}

Pop-Location
