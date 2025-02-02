#include "../fdf.h"

void apply_parallel_projection(t_vars *vars)
{
    if (vars->view == 1)
        apply_rotation(vars, -M_PI / 2, 'y');
    else if (vars->view == 2)
        apply_rotation(vars, M_PI / 2, 'y');
    else if (vars->view == 3)
        apply_rotation(vars,  M_PI / 2, 'x');
    else if (vars->view == 4) 
        apply_rotation(vars, -M_PI / 2, 'x');
    else if (vars->view == 5)
        apply_rotation(vars, M_PI, 'y');
}