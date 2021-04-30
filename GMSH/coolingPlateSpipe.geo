// Gmsh project created on Tue Dec 08 10:25:11 2020
r = 0.5;
w = 0.2;
length = 1;


SetFactory("OpenCASCADE");

Mesh.Algorithm = 6; // (1: MeshAdapt, 2: Automatic, 3: Initial mesh only, 5: Delaunay, 6: Frontal-Delaunay, 7: BAMG, 8: Frontal-Delaunay for Quads, 9: Packing of Parallelograms)
Mesh.Algorithm3D = 1; // (1: Delaunay, 3: Initial mesh only, 4: Frontal, 7: MMG3D, 9: R-tree, 10: HXT)
Mesh.OptimizeNetgen = 1;
Mesh.Smoothing = 2;
Mesh.MeshSizeMin = 0.1;
Mesh.MeshSizeMax = 0.1;
Geometry.NumSubEdges = 100; // nicer display of curve


//+Point(1) = {0, 0, 0, 1.0};
//+Point(2) = {length, 0, 0, 1.0};
//+Point(3) = {length, length, 0, 1.0};
//+Point(4) = {length - w, length, 0, 1.0};
//+Point(5) = {0, w, 0, 1.0};
//+Point(6) = {length - w - r, w, 0, 1.0};
//+Point(7) = {length - w, w + r, 0, 1.0};
//+Point(8) = {length - w - r, w + r, 0, 1.0};
//+Line(1) = {6, 5};
//+Line(2) = {1, 5};
//+Line(3) = {1, 2};
//+Line(4) = {2, 3};
//+Line(5) = {3, 4};
//+Line(6) = {4, 7};
//+Circle(7) = {6, 8, 7};
//+Curve Loop(1) = {6, -7, 1, -2, 3, 4, 5};
//+Surface(1) = {1};

//+Extrude {0, 0, w} {  Surface{1}; }
//+Physical Surface(1) = {9, 7, 6, 8, 1, 3, 4};
//+Physical Surface(2) = {5};
//+Physical Surface(3) = {2};
//+Physical Volume(4) = {1};


//+ Box(2) = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5};
//+ Cylinder(3) = {0.75, 0.75, 0.5, 0, 0, 0.5, 0.01};

//+ BooleanDifference(4) = { Volume{2}; Delete; }{ Volume{3}; Delete; };


//+ extrusion through line
Point(20) = {1, 1, 1};
Point(21) = {1, 1.3, 1};
Point(22) = {1, 1.3, 1.3};

Spline(23) = {20, 21, 22};
Wire(24) = {23};

Disk(25) = {0, 0, 0, 0.01};
Rectangle(26) = {0, 0, 0, 0.01, 0.01};

Extrude { Surface{25} } Using Wire {24};

