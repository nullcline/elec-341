%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Solution to Assignment #1                         %
% Do not change any variable names, only the values %
% Run this script & hand in the resulting MAT-file  %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Dummy variables to use as default values
dummy_tf  = tf(1,[1,1]);   % default transfer function
dummy_vec = [1,1];         % default vector
dummy_num = 1;             % default number

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% ENTER ANSWERS HERE 

% Once you have TESTED YOUR CHANGES
% Un-comment this line to create an output file
SaveFile = nan;

% Student Number
% 8 digit number
StudNum = 38113544;

% Calc 1
C1_tf = tf(numSim,denSim);

% Calc 2
C2_K  = K1;
C2_a  = A1;

% Calc 3
% Used by Simulink only
C3_pw = 0.0001;

% Calc 4
C4_K  = K2;

% Calc 5
C5_p  = -0.45;
C5_tf = tf(numFilter,denFilter);



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% DONT CHANGE ANYTHING IN THIS SECTION

if exist('SaveFile')
  % Create output file %
  if (isempty(StudNum) | (StudNum < 10000000) | (StudNum > 99999999))
    disp(sprintf('\nERROR: Student Number must have 8 digits - try again\n'));
  else
    fname = sprintf('%d.MAT', StudNum);
    save(fname, '-mat', ...
         'C1_tf', ...
         'C2_K', ...
         'C2_a', ...
         'C3_pw', ...
         'C4_K', ...
         'C5_p', ...
         'C5_tf');
    disp(sprintf('\nSaved %s\n', fname));
  end
end

%%% END OF FILE
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
