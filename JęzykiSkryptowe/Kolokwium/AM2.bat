@echo off
setlocal
set "search=%~1"
set "replace=%~2"
set "textfile=old.txt"
set "newfile=new.txt"
(for /f "delims=" %%i in (%textfile%) do (
    set "line=%%i"
    setlocal enabledelayedexpansion
    echo(!line:%search%=%replace%!
    endlocal
)) > %newfile%