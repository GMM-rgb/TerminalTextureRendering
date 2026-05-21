FUNCTION WhatOperatingSystem([System.Boolean]$IncludeCorrectivenessValue) {
    <#
    .PARAMETER
        IncludeCorrectivenessValues
    .DESCRIPTION
        Detects what operating system this powershell code is running on.
        Also includes an a boolean outputting option for the informational string if requested.
    .OUTPUTS
        [System.String]
    #>

    New-Variable -Name "DetectedOperatingSystem" -Value $null -Option Private;
    New-Variable -Name "AvailableOperatingSystemChecks" -Value [System.Array] >> ("Windows", "Linux", "MacOS") -Option AllScope;

    $ValidOperatingSystemChecksLength = 0;
    $CurrentOperatingSystemCheck = $null;
    
    FOREACH ($AvailableOperatingSystemChecks IN $AvailableOperatingSystemChecks) {

    }

    RETURN ((New-Object System.String("...")).ToString());
}

Write-Verbose -Verbose -Message (WhatOperatingSystem -IncludeCorrectivenessValue $true);
New-Variable -Name ConfigurationChangeQuery -Value @($null) -Force;
###
$env:EnviormentConfigurationFile ??= Get-ChildItem -Path "./.vscode/c_cpp_properties.json";
$env:ConfigurationFileStringPath ??= New-Object System.String($env:EnviormentConfigurationFile);
###
Write-Output -Debug (New-Object System.String("$env:ConfigurationFileStringPath"));
###
IF ($true && Get-Command -Name (("exec").ToLower())) { EXIT; }
