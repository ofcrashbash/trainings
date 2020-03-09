model SimpleHomeAndEnvironment
  parameter Real val = 0.1;
  Modelica.Thermal.HeatTransfer.Components.HeatCapacitor houseHeatCapacitor(C = 10000)  annotation(
    Placement(visible = true, transformation(origin = {58, 2}, extent = {{-10, 10}, {10, -10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.ThermalConductor Walls(G = 1)  annotation(
    Placement(visible = true, transformation(origin = {-14, 46}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Components.Convection convection annotation(
    Placement(visible = true, transformation(origin = {36, 46}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant convection_coefficient(k = 0.1)  annotation(
    Placement(visible = true, transformation(origin = {14, 66}, extent = {{-6, -6}, {6, 6}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Sources.PrescribedHeatFlow sunHeatFlow annotation(
    Placement(visible = true, transformation(origin = {-18, 2}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant sunHeatFlowValue annotation(
    Placement(visible = true, transformation(origin = {-55, 3}, extent = {{-7, -7}, {7, 7}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Sources.FixedTemperature outerTemperature(T = 281.15)  annotation(
    Placement(visible = true, transformation(origin = {-58, 46}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Thermal.HeatTransfer.Sensors.TemperatureSensor houseTemperature annotation(
    Placement(visible = true, transformation(origin = {76, 46}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  connect(convection_coefficient.y, convection.Gc) annotation(
    Line(points = {{21, 66}, {36, 66}, {36, 56}}, color = {0, 0, 127}));
  connect(Walls.port_b, convection.solid) annotation(
    Line(points = {{-4, 46}, {26, 46}}, color = {191, 0, 0}));
  connect(convection.fluid, houseHeatCapacitor.port) annotation(
    Line(points = {{46, 46}, {58, 46}, {58, 12}}, color = {191, 0, 0}));
  connect(sunHeatFlow.Q_flow, sunHeatFlowValue.y) annotation(
    Line(points = {{-28, 2}, {-47, 2}, {-47, 3}}, color = {0, 0, 127}));
  connect(sunHeatFlow.port, convection.solid) annotation(
    Line(points = {{-8, 2}, {26, 2}, {26, 46}}, color = {191, 0, 0}));
  connect(convection.fluid, houseTemperature.port) annotation(
    Line(points = {{46, 46}, {66, 46}}, color = {191, 0, 0}));
  connect(outerTemperature.port, Walls.port_a) annotation(
    Line(points = {{-48, 46}, {-24, 46}}, color = {191, 0, 0}));
  annotation(
    uses(Modelica(version = "3.2.3")),
    Icon(graphics = {Bitmap(origin = {1, 26}, extent = {{-101, 52}, {99, -86}}, fileName = "modelica://SimpleHomeAndEnvironment/house_environment_icon.jpg")}),
  experiment(StartTime = 0, StopTime = 1000000, Tolerance = 1e-6, Interval = 1000),
  __OpenModelica_commandLineOptions = "--matchingAlgorithm=PFPlusExt --indexReductionMethod=dynamicStateSelection -d=initialization,NLSanalyticJacobian,newInst",
  __OpenModelica_simulationFlags(lv = "LOG_STATS", outputFormat = "csv", s = "euler"),
  Documentation(info = "<html><head></head><body>This is some documentation</body></html>"));
end SimpleHomeAndEnvironment;
