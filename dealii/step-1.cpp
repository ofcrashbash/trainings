#include "step-1.hpp"

void grid_generator(Triangulation<1, 1>& triangulation, string grid_type)
{
    auto grid_type_map = map<string, unsigned>
    {
        {"hyper_cube", 0},
    };

    if (grid_type_map.count(grid_type))
        switch(grid_type_map.at(grid_type))
        {
            case 0:
                GridGenerator::hyper_cube(triangulation);
                break;
        }
    else 
        throw MyException("unknown grid type: " + grid_type);
}

void grid_generator(Triangulation<1, 2>& triangulation, string grid_type)
{
    auto grid_type_map = map<string, unsigned>
    {
        {"hyper_cube", 3},
        {"subdivided_hyper_cube", 4},
        {"hyper_sphere", 12}
    };

    if (grid_type_map.count(grid_type))
        switch(grid_type_map.at(grid_type))
        {
            case 3:
                GridGenerator::hyper_cube(triangulation);
                break;
            case 4:
                GridGenerator::subdivided_hyper_cube(triangulation, 3);
                break;
            case 12:
                GridGenerator::hyper_sphere(triangulation);
                break;
        }
    else
        throw MyException("unknown grid type: " + grid_type);
}

const PolarManifold<2, 2> g_polar_manifold;
const SphericalManifold<2, 2> g_manifold2d;//NOTE work around
TransfiniteInterpolationManifold<2, 2> g_inner_manifold;

void grid_generator(Triangulation<2, 2>& triangulation, string grid_type)
{
    auto grid_type_map = map<string, unsigned>
    {
        {"hyper_cube_slit", 0}, 
        {"half_hyper_ball", 1}, 
        {"hyper_shell", 2},
        {"hyper_cube", 3},
        {"subdivided_hyper_cube", 4},
        {"simplex", 5},
        {"cheese", 6},
        {"plate_with_a_hole", 7},
        {"parallelogram", 8},
        {"enclosed_hyper_cube", 10},
        {"hyper_ball", 11},
        {"quarter_hyper_ball", 13},
        {"truncated_cone", 15},
        {"hyper_cross", 16},
        {"hyper_L", 17},
        {"hyper_cube_with_cylindrical_hole", 19},
    };

    if (grid_type_map.count(grid_type))
        switch(grid_type_map.at(grid_type))
        {
            case 0:
                GridGenerator::hyper_cube_slit(triangulation);
                break;
            case 1:
                GridGenerator::half_hyper_ball(triangulation);
                break;
            case 2:
                GridGenerator::hyper_shell(triangulation, Point<triangulation.dimension>(), 1, 2, 6);
                break;
            case 3:
                GridGenerator::hyper_cube(triangulation);
                break;
            case 4:
                GridGenerator::subdivided_hyper_cube(triangulation, 3);
                break;
            case 5:
                {
                    vector<Point<2>> vertices{Point<2>(-1, 0), Point<2>(1, 0), Point<2>(0, 1)};
                    GridGenerator::simplex(triangulation, vertices);
                }
                break;
            case 6:
                GridGenerator::cheese(triangulation, vector<unsigned>{2, 3});
                break;
            case 7:
                GridGenerator::plate_with_a_hole(triangulation);
                break;
            case 8:
                {
                    Point<2> points[2] = {Point<2>(3, 2), Point<2>(2, 3)};
                    GridGenerator::parallelogram(triangulation, points);
                }
                break;
            case 10:
                GridGenerator::enclosed_hyper_cube(triangulation, 0, 1, 0.1);
                break;
            case 11:
                {
                    GridGenerator::hyper_ball(triangulation, Point<triangulation.dimension>());
                    
                    triangulation.set_all_manifold_ids(1);
                    triangulation.set_all_manifold_ids_on_boundary(0);
                    triangulation.set_manifold(0, g_polar_manifold);
                    g_inner_manifold.initialize(triangulation);
                    triangulation.set_manifold(1, g_inner_manifold);
                }
                break;
            case 13:
                GridGenerator::quarter_hyper_ball(triangulation);
                break;
            case 14:
                GridGenerator::cylinder(triangulation);
                break;
            case 15:
                GridGenerator::truncated_cone(triangulation);
                break;
            case 16:
                GridGenerator::hyper_cross(triangulation, vector<unsigned>{3, 4, 5, 6});
                break;
            case 17:
                GridGenerator::hyper_L(triangulation);
                break;
            case 19:
                GridGenerator::hyper_cube_with_cylindrical_hole(triangulation);
                break;
            //case 20: pointer error
            //    GridGenerator::concentric_hyper_shells(triangulation, Point<triangulation.dimension>());
            //    break;
        }
    else 
        throw MyException("unknown grid type: " + grid_type);
}

void grid_generator(Triangulation<2, 3>& triangulation, string grid_type)
{
    auto grid_type_map = map<string, unsigned>
    {
        {"hyper_cube", 3},
        {"subdivided_hyper_cube", 4},
        {"cheese", 6},
        {"hyper_sphere", 12},
        {"hyper_cross", 16}
    };

    if (grid_type_map.count(grid_type))
        switch(grid_type_map.at(grid_type))
        {
            case 3:
                GridGenerator::hyper_cube(triangulation);
                break;
            case 4:
                GridGenerator::subdivided_hyper_cube(triangulation, 3);
                break;
            case 6:
                GridGenerator::cheese(triangulation, vector<unsigned>{2, 3});
                break;
            case 12:
                GridGenerator::hyper_sphere(triangulation);
                break;
            case 16:
                GridGenerator::hyper_cross(triangulation, vector<unsigned>{3, 4, 5, 6});
                break;
        }
    else 
        throw MyException("unknown grid type: " + grid_type);
}

void grid_generator(Triangulation<3, 3>& triangulation, string grid_type)
{
    auto grid_type_map = map<string, unsigned>
    {
        {"hyper_cube_slit", 0}, 
        {"half_hyper_ball", 1}, 
        {"hyper_shell", 2},
        {"hyper_cube", 3},
        {"subdivided_hyper_cube", 4},
        {"simplex", 5},
        {"cheese", 6},
        {"plate_with_a_hole", 7},
        {"parallelepiped", 9},
        {"enclosed_hyper_cube", 10},
        {"hyper_ball", 11},
        {"quarter_hyper_ball", 13},
        {"cylinder", 14},
        {"truncated_cone", 15},
        {"hyper_cross", 16},
        {"hyper_L", 17},
        {"cylinder_shell", 18},
        {"hyper_cube_with_cylindrical_hole", 19},
        {"concentric_hyper_shells", 20},
        {"moebius", 21}
    };

    if (grid_type_map.count(grid_type))
        switch(grid_type_map.at(grid_type))
        {
            case 0:
                GridGenerator::hyper_cube_slit(triangulation);
                break;
            case 1:
                GridGenerator::half_hyper_ball(triangulation);
                break;
            case 2:
                GridGenerator::hyper_shell(triangulation, Point<triangulation.dimension>(), 1, 2, 6);
                break;
            case 3:
                GridGenerator::hyper_cube(triangulation);
                break;
            case 4:
                GridGenerator::subdivided_hyper_cube(triangulation, 3);
                break;
            case 5:
                {
                    vector<Point<3>> vertices{Point<3>(-1, 0, 0), Point<3>(1, 0, 0), Point<3>(0, 1, 0), Point<3>(0, 0, 1)};
                    GridGenerator::simplex(triangulation, vertices);
                }
                break;
            case 6:
                GridGenerator::cheese(triangulation, vector<unsigned>{2, 3, 4});
                break;
            case 7:
                GridGenerator::plate_with_a_hole(triangulation);
                break;
            case 9:
                {
                    Point<3> points[3] = {Point<3>(1, 0, 0), Point<3>(0, 1, 0), Point<3>(0, 0, 1)};
                    GridGenerator::parallelepiped(triangulation, points);
                }
                break;
            case 10:
                GridGenerator::enclosed_hyper_cube(triangulation, -1, 1, 0.1);
                break;
            case 11:
                GridGenerator::hyper_ball(triangulation, Point<triangulation.dimension>(), 1, true);
                break;
            case 13:
                GridGenerator::quarter_hyper_ball(triangulation);
                break;
            case 14:
                GridGenerator::cylinder(triangulation);
                break;
            case 15:
                GridGenerator::truncated_cone(triangulation);
                break;
            case 16:
                GridGenerator::hyper_cross(triangulation, vector<unsigned>{3, 4, 5, 6, 7, 8});
                break;
            case 17:
                GridGenerator::hyper_L(triangulation);
                break;
            case 18:
                GridGenerator::cylinder_shell(triangulation, 2, 0.5, 1);
                break;
            case 19:
                GridGenerator::hyper_cube_with_cylindrical_hole(triangulation);
                break;
            case 20:
                GridGenerator::concentric_hyper_shells(triangulation, Point<triangulation.dimension>());
                break;
            case 21:
                GridGenerator::moebius(triangulation, 10, 1, 2, 0.3);
                break;
        }
    else
        throw MyException("unknown grid type: " + grid_type);
}


Triangulation<2> hyper_cube_grid(unsigned n_ref)
{
    Triangulation<2> triangulation;
    GridGenerator::hyper_cube(triangulation);
    triangulation.refine_global(n_ref);
    return triangulation;
}

Triangulation<2> hyper_cube_slit()
{
    Triangulation<2> triangulation;
    GridGenerator::hyper_cube_slit(triangulation, 0, 1, false);
    triangulation.refine_global(4);
    return triangulation;
}

Triangulation<2> half_hyper_ball()
{
    Triangulation<2> triangulation;
    GridGenerator::half_hyper_ball(triangulation, Point<2>(0, 0), 1.0);
    triangulation.refine_global(4);
    return triangulation;
}

Triangulation<2> hyper_shell()
{
    Triangulation<2> triangulation;
    GridGenerator::hyper_shell(triangulation, Point<2>(0, 0), 0.1, 1, 6, true);
    triangulation.refine_global();

    for(auto& cell: triangulation.active_cell_iterators())
    {
        auto dist = (cell->center()).distance(Point<2>(0, 0));
        auto threshold = ((double) rand() / (RAND_MAX));
        if(dist > threshold)
        {
            cell->set_refine_flag();
        }
    }
    triangulation.execute_coarsening_and_refinement();
    return triangulation;
}
