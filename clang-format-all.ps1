function Format-Directory {
    param (
        [string]$Path,
        $Filter = {$True}
    )

    $DirInfos = @(Get-Item -Path $Path)
    $DirInfos += Get-ChildItem -Path $Path -Directory -Recurse
    $DirInfos | Where-Object $Filter |
    ForEach-Object {
        Write-Host $_.FullName
        Push-Location $_.FullName
        &clang-format -i *.h *.cpp 2> $null
        Pop-Location
    }
}

Format-Directory src
Format-Directory include
Format-Directory examples
Format-Directory tests {$_.FullName -notlike "*build*" -And $_.FullName -notlike "*generated*" -And $_.FullName -notlike "*scripts*"}
