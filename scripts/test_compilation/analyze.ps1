$outputFolder = 'out'
$metadataFolder = 'result'
$outputTrace = "$metadataFolder/output.json"
$outputMetadata = "$metadataFolder/output.meta.json"

if (Test-Path -Path $outputFolder) {
    Remove-Item $outputFolder -Recurse -Force
}
mkdir $outputFolder | Out-Null

if (-Not (Test-Path -Path $metadataFolder)) {
    mkdir $metadataFolder | Out-Null
}

$env:CC="clang-cl"
$env:CXX="clang-cl"
Write-Host "Configuring CMake"
cmake -B build -DCOIL_EXAMPLES=OFF -DCOIL_COMPILE_TIME=1 -DCOIL_COMPILE_TIME_WITH_COIL=1 -DCOIL_COMPILE_TIME_TRACE=ON -GNinja ../.. | Out-Null
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
    Copy-Item $jsonPath -Destination "../$outputFolder/result$i.json"
}

Pop-Location
Pop-Location

Write-Host "Merging results..."
Invoke-Expression "python merge-trace.py --input $outputFolder --output $outputTrace"

Write-Host "Analyzing results..."
$metadata = (Invoke-Expression "python .\print-trace-stats.py $outputTrace" | ConvertFrom-Json)

$metadata | ConvertTo-Json | Out-File $outputMetadata -Encoding Utf8
$metadata
