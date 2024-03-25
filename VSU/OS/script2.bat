@echo off
set "directory=%~1"
set "txt_files_count=0"

for /r "%directory%" %%F in (*.txt) do (
    set /a txt_files_count+=1
    echo %%F
)

echo Total number of .txt files in directory %directory%: %txt_files_count%