param (
    [bool]$keepBuildResults = $false,
    [int]$buildsCount = 10
)

.\run.ps1 -keepBuildResults $keepBuildResults -buildsCount $buildsCount -coilOptions @($true, $false) -clangOptions @($true) -unityBuildOptions @($false)
