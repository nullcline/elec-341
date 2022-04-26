%  Function: A1_ExpDataPlot
% 
%  Syntax:
%  [t y] = A1_ExpDataPlot(SN, fignum1, fignum2)
% 
%  SN      = optional, default = prompted
%  fignum1 = optional, default = 1
%  fignum2 = optional, default = fignum1 + 1
% 
%  Returned Variables
%  ------------------
%  t : Time vector of sampled data (msec)
%  y : Sampled data                (V)
%      Data is sampled at 5x the control frequency
%      Sample rate = 1 KHz
%      CF          = 200 Hz
% 
%  Plots an experimentally determined step response.
%  Assume curve came from a data-sheet with no further details.
%  Curve is generatecd based on an 8-digit student number.
%