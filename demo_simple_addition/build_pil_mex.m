function build_pil_mex(fcnName,hwName,enableCRL)
%BUILD_PIL_MEX Build a PIL MEX function.
%
% BUILD_PIL_MEX(fcnName,hwName) creates a PIL MEX function that runs the
% generated C-code on an ARM Cortex-A based hardware.
%
% BUILD_PIL_MEX(fcnName,hwName,true) creates a PIL MEX function with ARM
% Cortex-A CRL enabled.
%
% Example:
%  build_pil_mex('fft','BeagleBone Black')

% Copyright 2015 The MathWorks, Inc.
narginchk(2, 3)
if nargin < 3
    enableCRL = false;
end
if exist(fcnName,'file') ~= 2
    error('arm_cortex_a:examples:FunctionNotFound',...
        'The function %s does not exist.',fcnName);
end

% Create a coder configuration object for PIL verification
cfg = coder.config('lib','ecoder',true);
cfg.VerificationMode = 'PIL';
cfg.CodeExecutionProfiling = 1;
if enableCRL
    % Enable ARM Cortex-A CRL
    cfg.CodeReplacementLibrary = 'ARM Cortex-A';
end

% Select hardware for PIL simulation
hw = coder.hardware(hwName);
cfg.Hardware = hw;
cfg.BuildConfiguration = 'Faster Runs';

% Generate code for the function to be simulated in PIL
inp = single(zeros(1024,1));
codegen('-config ', cfg, '-args', {inp,inp}, fcnName, '-report');

end