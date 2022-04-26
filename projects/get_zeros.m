function zeros = get_zeros(p, Kp, Ki, Kd)
    s = tf('s'); 
    
    a = 1;
    b = s*(Kp*p+Ki)/(Kp+Kd*p);
    c = Ki*p/(Kp+Kd*p);

    zeros = roots([a, b, c]);
end