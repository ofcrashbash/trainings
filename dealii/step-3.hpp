#pragma once

#include <deal.II/grid/tria.h>
#include <deal.II/dofs/dof_handler.h>

#include <deal.II/fe/fe_q.h>

#include <deal.II/numerics/matrix_tools.h>

#include <deal.II/lac/vector.h>
#include <deal.II/lac/sparse_matrix.h>

using namespace dealii;

class LaplaceEquationSolver
{
    public:
        LaplaceEquationSolver();
        void run();

    private:
        void make_grid();
        void setup_system();
        void assemble_system();
        void solve();
        void output_results() const;

        Triangulation<2> triangulation;
        FE_Q<2> fe;
        DoFHandler<2> dof_handler;

        SparsityPattern sparsity_pattern;
        SparseMatrix<double> system_matrix;
        Vector<double> solution;
        Vector<double> system_rhs;
};