close all; clear; clc;

% a = 30030; b = 257;
% [r1, s1, t1] = extendedEuclidean(a, b);

syms n
eqn = n * log(n) == 128^2;
soln = solve(eqn, n);