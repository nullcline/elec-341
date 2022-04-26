%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Solution to Project #3                            %
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
% Enter your student number & Un-comment to create output file
StudNum = 38113544;

% Part 2
% ======
% 2nd Order Approximation
P2_ampTF = tf(num_p2, den_p2);

% Part 3
% ======
% Mechanical Admittance of Gripper
P3_Ym    = xfer;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% DONT CHANGE ANYTHING IN THIS SECTION

if exist('StudNum')
  if checkSN(StudNum)
    % Create output file %
    fname = sprintf('3-%d.MAT', StudNum);
    save(fname, '-mat', ...
         'P2_ampTF', ...
         'P3_Ym');
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
