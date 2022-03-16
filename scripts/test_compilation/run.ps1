param (
    [bool]$keepBuildResults = $false,
    [int]$buildsCount = 10,
    [string[]]$bindingsOptions = @("coil", "manual", ""),
    [bool[]]$clangOptions = @($true, $false),
    [bool[]]$unityBuildOptions = @($true, $false)
)

$outputFolder = 'result'
$outputFile = "$outputFolder/full-build-stats.json"

function IIf($If, $IfTrue, $IfFalse) {
    If ($If) {If ($IfTrue -is "ScriptBlock") {&$IfTrue} Else {$IfTrue}}
    Else {If ($IfFalse -is "ScriptBlock") {&$IfFalse} Else {$IfFalse}}
}

function Get-ConfigurationName([string]$Bindings, [bool]$UseClang, [bool]$UseUnityBuild) {
    $compilerName = $(If ($UseClang) {"Clang"} Else {"MSVC"})
    $bindingsName = $(IIf $Bindings $Bindings "-")
    $unityBuildName = $(IIf $UseUnityBuild "Unity" "-");
    return "$compilerName $bindingsName $unityBuildName"
}

function Measure-SingleBuild {
    param (
        [switch]$KeepBuildResults = $false,
        [int]$Count = 1,
        [string]$BindingsType = "",
        [switch]$UseClang = $false,
        [switch]$UseUnityBuild = $false
    )
    $configurationName = Get-ConfigurationName $BindingsType $UseClang $UseUnityBuild
    Write-Host "Measuring configuration [$configurationName]"
    $buildFolder = "build_temp/$configurationName"

    if (Test-Path -Path $buildFolder) {
        Remove-Item $buildFolder -Recurse -Force
    }
    mkdir $buildFolder | Out-Null
    Push-Location $buildFolder

    $coil = [int]($BindingsType -eq "coil")
    $manual = [int]($BindingsType -eq "manual")
    $unityBuild = [int]$UseUnityBuild.IsPresent
    
    Write-Host "Running CMake..."
    if ($UseClang) {
        $env:CC="clang-cl"
        $env:CXX="clang-cl"
    } else {
        $env:CC=""
        $env:CXX=""
    }
    Invoke-Expression "cmake -DCOIL_EXAMPLES=OFF -DCOIL_COMPILE_TIME=1 -DCOIL_COMPILE_TIME_WITH_COIL=$coil -DCOIL_COMPILE_TIME_WITH_MANUAL=$manual -DCMAKE_UNITY_BUILD=$unityBuild -GNinja ../.." | Out-Null

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
    if (-not $KeepBuildResults -and (Test-Path -Path $buildFolder)) {
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

function Main {
    if ($null -eq $env:vsinstalldir) {
        Write-Error "Visual Studio environment isn't set up"
        Exit 1
    }
    
    Push-Location ../..
    
    $results = @()
    foreach ($useClang in $clangOptions) {
        foreach ($useUnityBuild in $unityBuildOptions) {
            foreach ($bindingsOption in $bindingsOptions) {
                $configurationName = Get-ConfigurationName $bindingsOption $useClang $useUnityBuild
                $result = Measure-SingleBuild -KeepBuildResults:$keepBuildResults -Count $buildsCount -BindingsType $bindingsOption -UseClang:$useClang -UseUnityBuild:$useUnityBuild
    
                $results += [PSCustomObject]@{
                    Name = "[$configurationName]"
                    Durations = $result
                }
            }
        }
    }

    if (-Not (Test-Path -Path $outputFolder)) {
        mkdir $outputFolder | Out-Null
    }

    $outputStats = @()
    
    foreach ($configuration in $results) {
        $name = $configuration.Name
        $durations = $configuration.Durations
    
        Write-Host "${name}:"
        $stats = Measure-BuildResults $durations
        $stats | Out-Host
        
        $stats | Add-Member "Name" $configuration.Name

        $outputStats += $stats
    }
    
    Pop-Location

    $outputStats | ConvertTo-Json | Out-File $outputFile -Encoding Utf8
}

Main
