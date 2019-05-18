function [r1, s1, t1] = extendedEuclidean(a, b)
r0 = b; r1 = a;
s0 = 0; s1 = 1;
t0 = 1; t1 = 0;
while r0 ~= 0
    q = floor(r1 / r0);
    [r0, r1] = updateValue(r0, r1, q);
    [s0, s1] = updateValue(s0, s1, q);
    [t0, t1] = updateValue(t0, t1, q);
end
end