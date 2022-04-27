a = 13; b = 13; c = 19; d = 10;
e = 18; f = 13; g = 15; h =14;
s = tf('s');
SN = 33908354;
%SHAWN WAS HERE
%Table1 Values
Nominal_voltage = 12; NL_Current = (250+(10*a))*1E-3; 
Terminal_Resistance = 0.2; Terminal_Inductance = 0.5*1E-3;
Rotor_Inertia = (100+b)*1E-7; Speed_Constant = 600+(10*c);

Torque_Constant = 1/(Speed_Constant*pi/30);
Back_EMF = Nominal_voltage-NL_Current*Terminal_Resistance;
NL_speed = Back_EMF/Torque_Constant;
Bm = NL_Current*Torque_Constant/(NL_speed);

%Table2 Values
CF = 100+(10*a);
H = 2*CF/(s+2*CF);

%Table3 Values
JL = (a+b+c)*1E-6; BL = (d+e+f)*1E-6; KL1 = 2*1E-3; KL2 = (3*g)*1E-3;
Jcomb = JL+Rotor_Inertia; Bcomb = BL+Bm;
%Table4 Values
DC_gain = b; wn = (a*b*c*d); zeta = d/10;
num = DC_gain*wn^2;
den = [1 2*zeta*wn wn^2];
Amp_TF = tf(num,den);

Matrix_A = [0 1 0;...
        -KL1*KL2/((KL1+KL2)*Jcomb) -Bcomb/Jcomb Torque_Constant/Jcomb;...
        0 -Torque_Constant/Terminal_Inductance -Terminal_Resistance/Terminal_Inductance];

Matrix_B = [0;0;1/Terminal_Inductance];

Matrix_C = [1 0 0];

Matrix_D = [0];

phi_matrix = inv((s*eye(3)-Matrix_A));
TF_matrix = (Matrix_C*phi_matrix*Matrix_B+Matrix_D);

G = Amp_TF*TF_matrix;
GH = G*H;

%margin(GH);
z1 = 24.45698; z2 = 24.45698;
PID_Dynamics = 2*CF/(z1*z2)*((s+z1)*(s+z2))/(s*(s+2*CF));
[x1,x2,x3,x4] = margin(PID_Dynamics*G*H);

%Part3 
GXO = x4; PX0 = x3;
[p31,p32,p33,p34] = margin(0.683*PID_Dynamics*G*H);
K1 = 0.683;
%figure(1)
%margin(PID_Dynamics*G*H)

Ko = 1/(abs(freqresp(PID_Dynamics*G*H,100)));

%Part4
%{
figure(1)
rla(PID_Dynamics*G*H);
figure(2)
nyqlog(K1*PID_Dynamics*G*H)
%}

%Part5
K_master = x1/2;
Closed_Loop = K_master*PID_Dynamics*G/(1+K_master*PID_Dynamics*G*H);

[values2 time2] = step((Ko*PID_Dynamics*G)/(1+(Ko*PID_Dynamics*G*H)));
[values1 time1] = step(Closed_Loop,time2);
figure(2)
hold on
grid on
plot(time1, values1, 'LineWidth', 3)
plot(time2,values2,'LineWidth', 3)
legend('Kopt', 'K1')
hold off

%Part6
K = K_master;
Kp = (z1+z2)/(z1*z2)-1/(2*CF);
Ki = 1;
Kd = 1/(z1*z2)-Kp/(2*CF);



