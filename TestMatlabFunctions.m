% Processor-in-the-Loop Verification of MATLAB Functions
% 
% This example shows you how to use Embedded Coder Support Package for ARM Cortex-A Processors for Processor-in-the-Loop (PIL) verification of MATLAB® functions on the QEMU ARM Cortex-A9 emulator.
% 
% Introduction
% In this example you will learn how to generate a PIL MEX function from a simple MATLAB function. When you run the the PIL MEX function, the C-code generated from your MATLAB function runs on the QEMU ARM Cortex-A9 emulator. The results are transferred to MATLAB for numerical verification. During this process, you can profile the code execution. The PIL verification process is a crucial part of the design cycle to ensure that the behavior of the deployment code matches the design.
% 
% Prerequisites
% Start QEMU emulator for ARM Cortex-A9 by executing the following command on the MATLAB command prompt:

pid = codertarget.arm_cortex_a.runQemu
% Task 1 - Create a New Folder and Copy Relevant Files
% The following code will create a folder in your current working folder. The new folder will only contain the files that are relevant for this example. If you do not want to affect the current folder (or if you cannot generate files in this folder), you should change your working folder.

codertarget.arm_cortex_a.demo_setup('simple_addition');
% In this example, we use the simple_addition.m function that simply adds two inputs and returns the result. To see the contents of this function:

type simple_addition
% The %#codegen directive in this function indicates that the MATLAB code is intended for code generation.

% Task 2 - Generate PIL MEX Function
% First, generate a PIL MEX function using the command build_pil_mex followed by the name of followed by the name of the MATLAB file to compile.

build_pil_mex('simple_addition','ARM Cortex-A9 (QEMU)')
% The 'build_pil_mex' function generates a PIL MEX function named 'simple_addition_pil' in the current folder. This allows you to test the MATLAB code and the PIL MEX function and compare the results. To see the contents of the 'build_pil_mex' function:

type build_pil_mex
% The 'build_pil_mex' function creates a coder configuration object and sets the VerificationMode property to 'PIL'. It then attaches an 'ARM Cortex-A9 (QEMU)' hardware object to the coder configuration object. This hardware object signals the 'codegen' command to generate a PIL executable that runs on QEMU ARM Cortex-A9 emulator and a PIL MEX function to run that executable on the emulator.

% Task 3 - Run the PIL MEX Function
% Run the PIL MEX function to compare its behavior to that of the original MATLAB function and to check for run-time errors.

u1 = single(rand(1024,1));
u2 = single(rand(1024,1));
y = simple_addition_pil(u1,u2);
% Task 4 - Verify Generated Code
% To verify the numerical accuracy of the generated code, compare MATLAB results with those of the PIL MEX function:

norm(y - simple_addition(u1,u2))
% Task 5 - Profile Generated Code
% The build_pil_mex function enables code execution profiling by setting CodeExecutionProfiling of the coder configuration object to true. When profiling is enabled, the generated code is instrumented with timing information. The profiling results are transferred to MATLAB when the PIL MEX function is cleared from memory.

% To accumulate profiling results, run simple_addition function 100 times in a loop:

for k=1:100, y = simple_addition_pil(u1,u2); end
% The profiling results are available after clearing the PIL MEX function:

clear simple_addition_pil
% Bring up the profiling report:

report(getCoderExecutionProfile('simple_addition'))
% Task 6 - Use 'ARM Cortex-A' Code Replacement Library (CRL)
% To take advantage of optimized CRL for ARM Cortex-A processors, re-build the PIL MEX function with the 'ARM Cortex-A' CRL:

build_pil_mex('simple_addition','ARM Cortex-A9 (QEMU)',true)
% Run the simple_addition function 100 times in a loop to accumulate profiling results:

for k=1:100, y = simple_addition_pil(u1,u2); end
% The profiling results are available after clearing the PIL MEX function:

clear simple_addition_pil
% Bring up the profiling report:

report(getCoderExecutionProfile('simple_addition'))
% Compare the profiling results to those obtained in Task 5.

% Summary
% This example introduced the workflow for code verification of MATLAB functions using PIL.