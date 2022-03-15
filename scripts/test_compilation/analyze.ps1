$resFolder = 'out'
$mergedTrace = "$resFolder/merged.json"

if (Test-Path -Path $resFolder) {
    Remove-Item $resFolder -Recurse -Force
}
mkdir $resFolder | Out-Null

$env:CC="clang-cl"
$env:CXX="clang-cl"
Write-Host "Configuring CMake"
cmake -B build -DCOIL_EXAMPLES=OFF -DCOIL_COMPILE_TIME=1 -DCOIL_COMPILE_TIME_WITH_COIL=1 -GNinja ../.. | Out-Null
Push-Location build

$commands = (ninja -t compdb | ConvertFrom-Json)

$pchEntry = ($commands | Where-Object { $_.file -like "*cmake_pch.cxx" })
$entry = ($commands | Where-Object { $_.file -like "*WithBindings0.cpp" })

Write-Host "Compiling $($pchEntry.file)"
Push-Location $pchEntry.directory
Invoke-Expression $pchEntry.command | Out-Null
Pop-Location

Push-Location $entry.directory

for ($i = 1 ; $i -le 10 ; $i++) {
    Write-Host "Compiling $($entry.file)"
    Invoke-Expression $entry.command | Out-Null

    $jsonPath = $entry.output.replace('.cpp.obj', '.cpp.json')
    Copy-Item $jsonPath -Destination "../$resFolder/result$i.json"
}

Pop-Location
Pop-Location

Write-Host "Merging results..."
Invoke-Expression "python merge-trace.py --input $resFolder --output $mergedTrace"

Write-Host "Analyzing results..."
Invoke-Expression "python .\print-trace-stats.py $mergedTrace" | ConvertFrom-Json
