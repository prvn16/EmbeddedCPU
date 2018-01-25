@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2017b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2017b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=simple_addition_pil
set MEX_NAME=simple_addition_pil
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for simple_addition_pil > simple_addition_pil_mex.mki
echo COMPILER=%COMPILER%>> simple_addition_pil_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> simple_addition_pil_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> simple_addition_pil_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> simple_addition_pil_mex.mki
echo LINKER=%LINKER%>> simple_addition_pil_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> simple_addition_pil_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> simple_addition_pil_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> simple_addition_pil_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> simple_addition_pil_mex.mki
echo OMPFLAGS= >> simple_addition_pil_mex.mki
echo OMPLINKFLAGS= >> simple_addition_pil_mex.mki
echo EMC_COMPILER=msvc140>> simple_addition_pil_mex.mki
echo EMC_CONFIG=optim>> simple_addition_pil_mex.mki
"C:\Program Files\MATLAB\R2017b\bin\win64\gmake" -B -f simple_addition_pil_mex.mk
