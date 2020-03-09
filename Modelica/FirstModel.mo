model FirstModel
  Modelica.Electrical.Analog.Basic.Resistor resistor annotation(
    Placement(visible = true, transformation(origin = {-44, 0}, extent = {{10, -10}, {-10, 10}}, rotation = -90)));
  Modelica.Electrical.Analog.Basic.Inductor inductor annotation(
    Placement(visible = true, transformation(origin = {0, 24}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Electrical.Analog.Basic.Capacitor capacitor annotation(
    Placement(visible = true, transformation(origin = {2, -18}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  Modelica.Electrical.Analog.Basic.Ground ground annotation(
    Placement(visible = true, transformation(origin = {40, -28}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  connect(inductor.p, resistor.n) annotation(
    Line(points = {{-10, 24}, {-45, 24}, {-45, 10}, {-44, 10}}, color = {0, 0, 255}));
  connect(resistor.p, capacitor.n) annotation(
    Line(points = {{-44, -10}, {-45, -10}, {-45, -18}, {-8, -18}}, color = {0, 0, 255}));
  connect(inductor.n, ground.p) annotation(
    Line(points = {{10, 24}, {40, 24}, {40, -18}}, color = {0, 0, 255}));
  connect(inductor.n, capacitor.p) annotation(
    Line(points = {{10, 24}, {40, 24}, {40, -18}, {12, -18}}, color = {0, 0, 255}));

annotation(
    uses(Modelica(version = "3.2.3")));
end FirstModel;
