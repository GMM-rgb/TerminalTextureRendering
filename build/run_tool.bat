@echo off
cmake --build "%~dp0" --target TerminalTextRendering_Test
if %errorlevel% neq 0 exit /b %errorlevel%
"%~dp0TerminalTextRendering_Test.exe" %*
