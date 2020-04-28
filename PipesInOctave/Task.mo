model Task
  Modelica.Fluid.Pipes.StaticPipe pipe3(allowFlowReversal = true,diameter = 1, length = 1)  annotation(
    Placement(visible = true, transformation(origin = {20, -22}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  Modelica.Fluid.Pipes.StaticPipe pipe4(allowFlowReversal = true,diameter = 1, length = 1)  annotation(
    Placement(visible = true, transformation(origin = {-38, 60}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Fluid.Valves.ValveLinear valveLinear(dp_nominal = 0, m_flow_nominal = 1)  annotation(
    Placement(visible = true, transformation(origin = {-48, 20}, extent = {{10, 10}, {-10, -10}}, rotation = -90)));
  Modelica.Fluid.Sources.FixedBoundary boundary(T = 0, p = 1, use_T = true, use_p = true)  annotation(
    Placement(visible = true, transformation(origin = {-82, -22}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant const(k = 1)  annotation(
    Placement(visible = true, transformation(origin = {-80, 20}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant const1(k = 1)  annotation(
    Placement(visible = true, transformation(origin = {66, 70}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  Modelica.Fluid.Machines.PrescribedPump pump1(N_nominal = 1)  annotation(
    Placement(visible = true, transformation(origin = {18, 60}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  connect(pipe3.port_b, valveLinear.port_a) annotation(
    Line(points = {{10, -22}, {-48, -22}, {-48, 10}}, color = {0, 127, 255}));
  connect(boundary.ports[1], valveLinear.port_a) annotation(
    Line(points = {{-72, -22}, {-48, -22}, {-48, 10}}, color = {0, 127, 255}));
  connect(valveLinear.port_b, pipe4.port_a) annotation(
    Line(points = {{-48, 30}, {-48, 60}}, color = {0, 127, 255}));
  connect(valveLinear.opening, const.y) annotation(
    Line(points = {{-56, 20}, {-69, 20}}, color = {0, 0, 127}));
  connect(pipe4.port_b, pump1.port_a) annotation(
    Line(points = {{-28, 60}, {8, 60}, {8, 60}, {8, 60}}, color = {0, 127, 255}));
  connect(pump1.port_b, pipe3.port_a) annotation(
    Line(points = {{28, 60}, {30, 60}, {30, -22}, {30, -22}}, color = {0, 127, 255}));
  connect(pump1.N_in, const1.y) annotation(
    Line(points = {{18, 70}, {55, 70}}, color = {0, 0, 127}));
  annotation(
    uses(Modelica(version = "3.2.3")));
end Task;
