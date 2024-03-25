@echo off
setlocal enabledelayedexpansion

set "baseDir=C:\lab3"

set /p "direction=Enter scientific direction:" 
set /p "journal=Enter journal name:" 

set "articlesDir=%baseDir%\Articles"
set "criteriaDir=%baseDir%\Criteria"

echo Searching for documents with criteria:
echo.

for /D %%a in ("%articlesDir%\*") do (
    	set "articleDir=%%a"

   	set /p articleDirection=< "!articleDir!\Direction.txt"
   	set /p articleJournal=< "!articleDir!\Journal.txt"
	

    	if "!articleDirection!" equ "%direction%" (
       		if "!articleJournal!" equ "%journal%" (
            		echo Found matching document in: !articleDir!

            		echo Direction: !articleDirection!
            		echo Journal: !articleJournal!

            		for %%f in ("!articleDir!\*.txt") do (
               			echo %%~nxf: 
                		type "%%f"
                		echo.
            		)
            		echo.
        	)
    	)
)

echo Script completed.
pause

