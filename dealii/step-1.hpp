#pragma once

#include <deal.II/grid/tria.h>
#include <deal.II/grid/tria_accessor.h>
#include <deal.II/grid/tria_iterator.h>
#include <deal.II/grid/grid_generator.h>
#include <deal.II/grid/grid_out.h>
#include <deal.II/grid/manifold_lib.h>

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace dealii;
using namespace std;

vector<string> grids_types_array();

extern const PolarManifold<2, 2> g_polar_manifold;
extern const SphericalManifold<2, 2> g_manifold2d;//NOTE work around
extern TransfiniteInterpolationManifold<2, 2> g_inner_manifold;

struct MyException : public std::exception
{
   string s;
   MyException(string ss) : s(ss) {}
   ~MyException() throw () {} // Updated
   const char* what() const throw() { return s.c_str(); }
};

void grid_generator(Triangulation<1>& triangulation, string grid_type);
void grid_generator(Triangulation<1, 2>& triangulation, string grid_type);
void grid_generator(Triangulation<2>& triangulation, string grid_type);
void grid_generator(Triangulation<2, 3>& triangulation, string grid_type);
void grid_generator(Triangulation<3>& triangulation, string grid_type);

template <int dim = 2, int spacedim = dim>
void save(Triangulation<dim, spacedim> &triangulation, string name)
{
    GridOut grid_out;

    ofstream out(name + ".vtk");
    grid_out.write_vtk(triangulation, out);
    out.close();
    
    cout << "grid written to \"" + name + ".vtk\"" << endl;
}

Triangulation<2> hyper_cube_grid(unsigned n_ref = 0);

Triangulation<2> hyper_cube_slit();

Triangulation<2> half_hyper_ball();

Triangulation<2> hyper_shell();

template <int dim = 2>
ostream& operator<<(ostream &out, const Triangulation<dim>& triangulation)
{   
    out << "Triangulation info" << endl;
    out << "dim: " << triangulation.dimension << endl;
    out << "n_active_cells: " << triangulation.n_active_cells() << endl;
    out << "n_active_faces: " << triangulation.n_active_faces() << endl;
    out << "n_active_lines: " << triangulation.n_active_lines() << endl;
    out << "n_active_quads: " << triangulation.n_active_quads() << endl;
    out << "n_global_active_cells: " << triangulation.n_global_active_cells() << endl;
    out << "n_global_levels: " << triangulation.n_global_levels() << endl;
    out << "n_levels: " << triangulation.n_levels() << endl;

    return out;
}

void step_1_main();