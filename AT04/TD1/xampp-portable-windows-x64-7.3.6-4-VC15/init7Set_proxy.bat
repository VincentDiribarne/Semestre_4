@echo off
set PARAM=%1
if "%2" neq "" set PARAM=%1 %2
set NO_PROXY=127.0.0.1,localhost
set HTTP_PROXY=proxy.univ-lemans.fr:3128
set HTTPS_PROXY=proxy.univ-lemans.fr:3128
set PHP_HOME=%PARAM%\php
set BEHAT_HOME=%CD%\bin
set PATH=%PHP_HOME%;%BEHAT_HOME%;%PATH%;