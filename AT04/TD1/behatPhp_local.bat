@echo off
@set PARAM=%CD%
rem set PARAM=P:\RESSOURCES INFO2\SEMESTRE_4\M4103C_ProgrammationWebClientRiche\behatPhp
rem set PARAM=P:\RESSOURCES_MMI2\SEMESTRE_4\UE2\DeveloppementObjetS4\behatPhp
@cmd /V:ON /K "%PARAM%\initSet_local.bat" %PARAM%
@cd %PARAM%