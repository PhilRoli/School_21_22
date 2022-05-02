Zaehler = [1 1];
Nenner = [1 2 5 0];

F = tf(Zaehler, Nenner)

Zaehler1 = 1;
Nenner1 = [1 1 2.5];

F1 = tf(Zaehler1, Nenner1)

% s = tf('s');
% T1 = 0.01;
% T2 = 0.1;
% T3 = 1;
% T4 = 10;
% K1 = 6;

% H1 = K1 * ((1 + s*T1)) / ((1 + s*T2)*(1+s*T3) * ( 1+s*T4))

roots(Nenner)
roots(Nenner1)

[r,p,k] = residue(Zaehler,Nenner)
[r1,p1,k1] = residue(Zaehler1,Nenner1)

% figure(1)
% pzmap(F)

% h1 = gcf
% ax = findall(h1, 'type', 'axes');
% pl = findall(h1, 'type', 'line');
% set(pl(3), 'linewidth', 2, 'color', 'red')
% set(pl(2), 'linewidth', 2, 'color', 'red')
% set(pl(1), 'linewidth', 2, 'color', 'red')
% set(pl(4), 'linewidth', 2, 'color', 'blue')