model HelloWorld

  Real x(start = 1);
  parameter Real a = -1;
  parameter Boolean b = false;
  parameter Integer i = 1;
  parameter Real r = 1e-10;
  parameter String s = "test";
  constant Real c = 2.71;
  
equation

  der(x) = a*x;
  
end HelloWorld;
