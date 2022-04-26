%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Solution to Project #8                            %
% Do not change any variable names, only the values %
% Run this script & hand in the resulting MAT-file  %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Dummy variables to use as default values
dummy_num = 1;             % default number
dummy_vec = [1,1];         % default vector
dummy_mat = [1,1;1,1];     % default matrix
dummy_tf  = tf(1,[1,1]);   % default transfer function

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% ENTER ANSWERS HERE 

% Once you have TESTED YOUR CHANGES
% Enter your student number & Un-comment to create output file
StudNum = 38113544;

% Part 2
% ======
% 2nd Order Approximation
P2_ampTF = P2_ampTF;

% Part 6
% ======
% Proportional Control
P6_GH    = P6_GH;

% Part 8
% ======
% Lead Control
P8_Dcf   = P8_Dcf;
P8_Ku    = P8_Ku;

P8_z     = P8_z;
P8_D     = P8_D;
P8_K     = P8_K;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% DONT CHANGE ANYTHING IN THIS SECTION

if exist('StudNum')
  if checkSN(StudNum)
    % Create output file %
    fname = sprintf('%d.MAT', StudNum);
    save(fname, '-mat', ...
         'P2_ampTF', ...
         'P6_GH', ...
         'P8_Dcf', ...
         'P8_Ku', ...
         'P8_z', ...
         'P8_D', ...
         'P8_K');
    disp(sprintf('\nSaved %s\n', fname));
  end
end

function goodSN = checkSN(SN)
  goodSN = ~(isempty(SN) | (SN < 10000000) | (SN > 99999999));
  if ~goodSN
    disp('Student Number must have 8 digits');
  end
end

%%% END OF FILE
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
