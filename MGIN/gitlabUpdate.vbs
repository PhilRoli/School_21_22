Set WshShell = CreateObject("WScript.Shell") 
WshShell.Run chr(34) & ".\pushToGitLab.bat" & Chr(34), 0
WshShell.Run chr(34) & ".\pullFromGitLab.bat" & Chr(34), 0
Set WshShell = Nothing