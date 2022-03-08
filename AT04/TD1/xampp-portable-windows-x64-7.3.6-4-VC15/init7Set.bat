echo off
set PARAM=%1
if "%2" neq "" set PARAM=%1 %2
set NO_PROXY=
set HTTP_PROXY=
set HTTPS_PROXY=
set PHP_HOME=%PARAM%\php
set BEHAT_HOME=%CD%\bin
set PATH=%PHP_HOME%;%BEHAT_HOME%;%PATH%;