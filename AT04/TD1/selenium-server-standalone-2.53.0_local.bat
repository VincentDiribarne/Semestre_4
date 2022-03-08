echo off
rem set PARAM=P:\RESSOURCES INFO2\SEMESTRE_4\M4103C_ProgrammationWebClientRiche\behatPhp
rem set PARAM=P:\RESSOURCES_MMI2\SEMESTRE_4\UE2\DeveloppementObjetS4\behatPhp
set PARAM=%CD%
java -jar "%PARAM%\selenium-server-standalone-2.53.0.jar" -Dwebdriver.firefox.bin="%PARAM%\Firefox_35.0.1\firefox.exe" -Dwebdriver.chrome.driver="%PARAM%\chromedriver_win32\chromedriver.exe"
