@echo off
@echo *** COMPILING ***
cls
c:\rnd\asm\asm51 %1.src
pause
c:\rnd\asm\rl51 %1.obj
c:\rnd\asm\oh %1

@echo
@echo Next Step?
@echo 1 ...AVSIM51
@echo 2 ...GALEP
@echo 3 ...EXIT
choice My choice: /c123
if ERRORLEVEL 3 goto EXIT
if ERRORLEVEL 2 goto GALEP
if ERRORLEVEL 1 goto AVSIM51
goto exit
:AVSIM51 
copy *.hex c:\rnd\asm /y
cd\
cd rnd
cd asm
avsim51
goto exit
:GALEP 
c:\rnd\galep\galep2 %1.hex -c0
:EXIT
%1
