SetFactory("OpenCASCADE");

Mesh.MeshSizeMin = 0.1;
Mesh.MeshSizeMax = 0.1;
Geometry.NumSubEdges = 100; // nicer display of curve

L = 1;
H = 1;
W = 1;

Point(1) = {0, 0.1666, 0};
Point(2) = {0.8, 0.1666, 0};
Point(3) = {0.75, 0.333333, 0};
Point(4) = {0.8, 0.5, 0};
Point(5) = {0.2, 0.5, 0};
Point(6) = {0.25, 0.66666, 0};
Point(7) = {0.2, 0.8333, 0};
Point(8) = {1, 0.8333, 0};

Line(9) = {1, 2};
Circle(10) = {2, 3, 4};
Line(11) = {4, 5};
Circle(12) = {5, 6, 7};
Line(13) = {7, 8};
//+Spline(1) = {1:8};
Wire(1) = {9, 10, 11, 12, 13};
Rectangle(1) = {0, 0.1666 - 0.02, 0, 2 * 0.02, 2 * 0.02};
Rotate {{1, 0, 0}, {0, 0, 0}, Pi/2} { Surface{1}; };

Extrude { Surface{1}; } Using Wire {1}
Delete{ Surface{1}; }