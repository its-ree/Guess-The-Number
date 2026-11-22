@echo off
echo ============================================
echo   Building GuessTheNumber...
echo ============================================

gcc GuessTheNum.c -o GuessTheNum.exe

if %ERRORLEVEL% == 0 (
    echo.
    echo   ✅ Build successful!
    echo   Run with:  .\GuessTheNum.exe
    echo.
) else (
    echo.
    echo   ❌ Build failed. Make sure GCC is installed.
    echo   Install MinGW: https://www.mingw-w64.org/
    echo.
)
pause
