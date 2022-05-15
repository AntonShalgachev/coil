Push-Location ..

$buildFolder = "build_compilation_test"

if (Test-Path -Path $buildFolder) {
    Remove-Item $buildFolder -Recurse -Force
}
mkdir $buildFolder | Out-Null
Push-Location $buildFolder

Invoke-Expression "cmake -DCOIL_COMPILATION_TESTS=ON .."

Pop-Location

if (Test-Path -Path $buildFolder) {
    Remove-Item $buildFolder -Recurse -Force
}

Pop-Location
