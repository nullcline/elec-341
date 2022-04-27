function out = closed_loop(K, D, G, H)
    out = K*D*G/(1+K*D*G*H);
end