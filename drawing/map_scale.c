#include "../fdf.h"



int step_x(t_point *start_point, t_point *end_point)
{
    if (end_point->x > start_point->x)
        return (1);
    else
        return (-1);
}

int step_y(t_point *start_point, t_point *end_point)
{
    if (end_point->y > start_point->y)
        return (1);
    else
        return (-1);
}

float     right_scale(t_vars *vars)
{
    float x_scale;
    float y_scale;
    float max_projected_width;

    max_projected_width = vars->map.map_height + vars->map.map_width;
    x_scale = vars->mlx_info.mlx_window_height / max_projected_width;
    y_scale = vars->mlx_info.mlx_window_width  / max_projected_width;

    if (x_scale < y_scale)
        return (x_scale);
    else
        return (y_scale);
}

void set_height_boundaries(t_vars *vars)
{
    int i;
    int j;
    t_map_range range;

    i = -1;   
    range.min_z = vars->map.map_points[0][0].z;
    range.max_z = vars->map.map_points[0][0].z;
    while (++i < vars->map.map_height)
    {
        j = -1;
        while (++j < vars->map.map_width)
        {
            if (vars->map.map_points[i][j].z < range.min_z)
                range.min_z = vars->map.map_points[i][j].z;
            if (vars->map.map_points[i][j].z > range.max_z)
                range.max_z = vars->map.map_points[i][j].z;
        }
    }
    vars->map.map_range.max_z = range.max_z;
    vars->map.map_range.min_z = range.min_z;
}

float	calculate_height_factor(t_vars *vars)
{
	float	height_range;
	float	height_factor;

    set_height_boundaries(vars);
	height_range = vars->map.map_range.max_z - vars->map.map_range.min_z;
	if (height_range <= 0)
		return (1.0);
	if (height_range > vars->map.map_width)
		height_factor = (float) vars->map.map_width / height_range;
	else if (height_range <  vars->map.map_width / 4)
		height_factor = 2.0;
	else
		height_factor = 1.0;
	return (height_factor);
}

void    apply_scale(t_vars *vars)
{
    int i;
    int j;
    float hight_factor;

    hight_factor = calculate_height_factor(vars);
    vars->map.map_scale = right_scale(vars);
    i = 0;
    while (i < vars->map.map_height)
    {
        j = 0;
        while (j < vars->map.map_width)
        {
            vars->map.map_points[i][j].x *= vars->map.map_scale;
            vars->map.map_points[i][j].y *= vars->map.map_scale;
            vars->map.map_points[i][j].z *= (vars->map.map_scale * hight_factor);
            j++;
        }
        i++;
    }
}
