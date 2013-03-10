@echo off
setlocal enableextensions
set "CC=gcc"
set "CCflags=-ansi -Wall"
set "src=src"
set "incl=-Iinclude"
set "lib="

set "objects=main.o"
set "target=noin"

if "%1" equ "-g" set "CCflags=%CCflags% -g"
if "%1" equ "-E" set "CCflags=%CCflags% -E"

del *.o 2> nul
del *.exe 2> nul


%CC% %CCflags% -c main.c %incl%
%CC% -o %target% %objects% %lib%

del *.o 2> nul

IF EXIST %target%.exe (
	echo %target% was built
) ELSE (
	echo %target% was not built

)
endlocal
