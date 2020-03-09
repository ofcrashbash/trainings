model SimpleRocketModel
  parameter String name = "Apollo 13";
  Real mass(start = 1038.358);
  Real altitude(start = 59404);
  Real velocity(start = -2003);
  Real acceleration;
  Real thrust;
  Real gravity;
  parameter Real massLossRate=0.000277;
  CelestialBody moon;

equation
  (thrust - mass*gravity)/mass = acceleration;
  der(mass) = -massLossRate*abs(thrust);
  der(altitude) = velocity;
  der(velocity) = acceleration;

end SimpleRocketModel;
