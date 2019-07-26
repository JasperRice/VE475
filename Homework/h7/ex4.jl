P = 1;
for j = 1:39
    global P;
    P *= 1 - j / 1000;
end
P = 1 - P;
print(P)
