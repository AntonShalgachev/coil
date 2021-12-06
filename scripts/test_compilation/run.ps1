function Measure-Build {
    param (
        [int]$Count = 1,
        [switch]$UseCoil = $false,
        [switch]$UseSol = $false,
        [switch]$UseObjects = $false
    )

    $buildFolder = "build_temp"

    if (Test-Path -Path $buildFolder) {
        Remove-Item $buildFolder -Recurse -Force
    }
    mkdir $buildFolder | Out-Null
    Push-Location $buildFolder
    
    Write-Host "Measuring Coil=$UseCoil Sol=$UseSol Objects=$UseObjects..."

    $coil = [int]$UseCoil.IsPresent
    $sol = [int]$UseSol.IsPresent
    $objects = [int]$UseObjects.IsPresent
    
    Write-Host "Running CMake..."
    Invoke-Expression "cmake -DCOIL_COMPILATION_PERFORMANCE=1 -DCOIL_COMPILATION_PERFORMANCE_USE_COIL=$coil -DCOIL_COMPILATION_PERFORMANCE_USE_SOL=$sol -DCOIL_COMPILATION_PERFORMANCE_USE_OBJECTS=$objects -GNinja .." | Out-Null
    
    $durations = @()

    for ($i = 1 ; $i -le $Count ; $i++) {
        Write-Host "Building $i/$Count..."
        ninja -t clean | Out-Null
        $result = (Measure-Command { ninja | Out-Host })."TotalSeconds"
        $durations += $result
        Write-Host "Build completed in $result seconds"
    }

    Write-Host

    Pop-Location
    if (Test-Path -Path $buildFolder) {
        Remove-Item $buildFolder -Recurse -Force
    }
    
    return $durations
}

function Write-BuildStatistics {
    param (
        $Name,
        $Durations
    )
    
    Write-Host "$Name compilation:"
    $Durations | Measure-Object -Average -Maximum -Minimum | Select-Object Average, Maximum, Minimum | Out-Host
}

if ($null -eq $env:vsinstalldir) {
    Write-Error "Visual Studio environment isn't set up"
    Exit 1
}

Push-Location ../..

$BuildCounts = 20

$base = Measure-Build -Count $BuildCounts
$coil = Measure-Build -Count $BuildCounts -UseCoil
$coilWithObjects = Measure-Build -Count $BuildCounts -UseObjects -UseCoil
$sol = Measure-Build -Count $BuildCounts -UseSol
$solWithObjects = Measure-Build -Count $BuildCounts -UseObjects -UseSol

Write-BuildStatistics "Base" $base
Write-BuildStatistics "Coil" $coil
Write-BuildStatistics "Coil with objects" $coilWithObjects
Write-BuildStatistics "Sol" $sol
Write-BuildStatistics "Sol with objects" $solWithObjects

Pop-Location
