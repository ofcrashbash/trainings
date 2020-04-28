#! octave -qf

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%parameters
L1 = 1; %pipe1(pipe4-1) lenght
L2 = 1; %pipe2(pipe2-3) lenght
Lvalve = 0; 
Lpump = 0; 
D1 = 1; 
D2 = 1;
Dvalve = 1; %used for evaluation of flow_rate in valve
Dpump = 1;

p_atm = 1;
rho = 1; %density

lambda = 1; %pipe constant

eta = 1; %valve constant

%pump parameters
s = 1; 
delta_P_ref = 1;
Q_max = 1;

tmax = 10;

Q_critical = 100; %maximal flow_rate in system



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%create object model
o = SimpleHydraulicSystemSimulation(
  L1, L2, Lvalve, Lpump, 
  D1, D2, Dvalve, Dpump,
  p_atm,
  rho, lambda, eta, s, delta_P_ref, Q_max, Q_critical);

  
  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  
%simple standard model usecase run, starting from flow_rate = 0;
Q0 = 0;
dt = 0.1;
[time, Qvalue] = o.solve(Q0, dt, tmax);

figure ("name", "Simulation from flow_rate=0 state")
subplot (2, 1, 1)
plot(time, Qvalue, "-;Q;")
xlabel ("t, time");
ylabel ("Q, Flow Rate");
title ("Flow Rate evolution");

subplot (2, 1, 2)
plot(time, o.p1(Qvalue), "-;p1;", time, o.p2(Qvalue), "-;p2;",
  time, o.p3(Qvalue), "-;p3;", time, o.p4(Qvalue), "-;p4;", 
  time, o.p_atm + o.p4(Qvalue) - o.p3(Qvalue), "-;Pump Pressure;")
xlabel ("t, time");
ylabel ("P, pressure");
title ("Pressure value evolution at control points(p1, p2, p3, p4)");




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  
%different flow_rate plots
figure("name", "different initial flow rate values")

Qrange = [-30, -11.5, -10.45, -2, 0, 1, 2, 4];
dt = 0.1;
for Q0 = Qrange
  [time, Qvalue] = o.solve(Q0, dt, tmax);
  plot(time, Qvalue, strcat(["-;Q0 = ",num2str(Q0) ,";"]))
  hold on
  xlabel ("t, time");
  ylabel ("Q, Flow Rate");
  title ("Flow Rate evolution");
end




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  
%numerical convergence limit
figure("name", "Convergence")
dt_range = logspace(-3, 0, 10);
Q_limit = zeros(size(dt_range));
Q0 = -2;
index = 1;
subplot (2, 1, 1)
for dt = dt_range
  [time, Qvalue] = o.solve(Q0, dt, 4.);
  plot(time, Qvalue)#, strcat(["-;dt = ",num2str(dt) ,";"]))
  hold on
  
  Q_limit(1, index) = Qvalue(1, size(Qvalue, 2));
  ++index;
end

subplot (2, 1, 2)
semilogx(dt_range, Q_limit)
xlabel ("dt, integration step");
ylabel ("Q final, Flow Rate");
title ("Solver convergence");




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%pump not working case
figure("name", "Etreme cases")

s = 0;
o = SimpleHydraulicSystemSimulation(
  L1, L2, Lvalve, Lpump, 
  D1, D2, Dvalve, Dpump,
  p_atm,
  rho, lambda, eta, s, delta_P_ref, Q_max, Q_critical);

Q0 = 20; %some big positive value
dt = 0.01;
[time, Qvalue] = o.solve(Q0, dt, tmax);
subplot(2, 1, 1)
plot(time, Qvalue, "-;Pump not working Q = 20;");
hold on
Q0 = -20; %some big negative value
[time, Qvalue] = o.solve(Q0, dt, tmax);
plot(time, Qvalue, "-;Pump not working Q = -20;");

s = 1;
eta = 10000; %almost closed valve
o = SimpleHydraulicSystemSimulation(
  L1, L2, Lvalve, Lpump, 
  D1, D2, Dvalve, Dpump,
  p_atm,
  rho, lambda, eta, s, delta_P_ref, Q_max, Q_critical);

Q0 = 0;
[time, Qvalue] = o.solve(Q0, dt, tmax);
subplot(2, 1, 2)
plot(time, Qvalue, "-;Almost closed valve;");