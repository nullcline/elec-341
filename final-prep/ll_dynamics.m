function D = ll_dynamics(p, z1, z2)
    s = tf('s');
    D = p/(z1*z2)*(s+z1)*(s+z2)/(s*(s+p));
end