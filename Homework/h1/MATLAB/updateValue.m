function [n0, n1] = updateValue(o0, o1, q)
n0 = o1 - q * o0;
n1 = o0;
end