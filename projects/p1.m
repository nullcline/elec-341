s = tf('s');
student_num = [3 8 1 1 3 5 4 4];
%              a b c d e f g h
student_num = student_num + 10;


K = student_num(3)/5; % (V/rad) gain 

% create transfer functions and get their numerator/denomenator
Gamp = student_num(1) / ( s + student_num(1) );
[numGamp, denGamp] = tfdata(Gamp, 'v');

Gmot = student_num(2) / ( s + student_num(2) );
[numGmot, denGmot] = tfdata(Gmot, 'v');

ZOH = 1/50;    % (sec) zero order hold sampling period
ipMag = pi/4;  % (rad) step function magnitude

simTime = 0.7; % (sec) chosen experimentally just by looking at simulation

% conversion factors
rad2deg = 180/pi; % (deg/rad)
deg2rad = pi/180; % (rad/deg)