Push-Location ..
$workingDir = (Get-Location).Path
Pop-Location

$exe = "$workingDir\out\build\Clang-Debug\tests\runtime\cmake_tests.exe"

if (-Not (Test-Path -Path $exe)) {
    Write-Error "'$exe' doesn't exist. Build the `Clang-Debug` configuration first"
    return
}

OpenCppCoverage.exe --sources $workingDir\include --sources $workingDir\src --excluded_sources $workingDir\src\StdLib.cpp --export_type html:coverage --excluded_line_regex ".*@NOCOVERAGE.*" -- $exe
