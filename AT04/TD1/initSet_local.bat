@echo off
@set PARAM=%1
@if "%2" neq "" set PARAM=%1 %2
@set NO_PROXY=
@set NO_PROXY=127.0.0.1
@set HTTP_PROXY=
@set HTTPS_PROXY=
@set PHP_HOME=%PARAM%\xampp-portable-windows-x64-7.3.6-4-VC15\php
@set BEHAT_HOME=%CD%\vendor\bin
@set PATH=%PHP_HOME%;%BEHAT_HOME%;%PATH%;
@cd %PARAM%\xampp-portable-windows-x64-7.3.6-4-VC15\
@setup_xampp.bat