@echo off
set "directory=%1"
set "count=0"
for /f %%A in ('dir /ad /b /ah "%directory%" 2^>nul') do (
    set /a count+=1
)
echo In directory "%directory%" was found %count% hidden folders