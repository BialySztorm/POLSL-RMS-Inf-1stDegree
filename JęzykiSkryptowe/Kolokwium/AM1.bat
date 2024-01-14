@echo off
setlocal enabledelayedexpansion
set count=0
for %%A in (*.txt) do (
    set /a count+=1
)
title Number of text files: !count!
@pause