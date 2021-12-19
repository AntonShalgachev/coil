Push-Location ..

$buildFolder = "build_compilation_test"

if (Test-Path -Path $buildFolder) {
    Remove-Item $buildFolder -Recurse -Force
}
mkdir $buildFolder | Out-Null
Push-Location $buildFolder

Invoke-Expression "cmake -DCMAKE_TESTS=1 -DRUN_CMAKE_COMPILATION_TEST=1 .."

Pop-Location

if (Test-Path -Path $buildFolder) {
    Remove-Item $buildFolder -Recurse -Force
}

Pop-Location