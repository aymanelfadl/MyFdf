#include "../fdf.h"

// void	reset_shape(int keycode, t_vars *vars, int *total_offset_x, int *total_offset_y)
// {
// 	if (keycode == KEY_SPACE)
// 	{
// 		*total_offset_x = 0;
// 		*total_offset_y = 0;
// 		vars->map.map_range. = 1.1;
// 		calculate_scale(vars->map);
// 		parse_map(vars);
// 		iso_point(vars);
// 	}
// }

// void	change_projection(t_vars *vars)
// {
// 	vars->map->scale.projection = (vars->map->scale.projection + 1) % 3;
// 	calculate_scale(vars->map);
// 	parse_map(vars);
// 	if (vars->map->scale.projection == 0)
// 		apply_rotation(vars, 1.57, 'y');
// 	else if (vars->map->scale.projection == 1)
// 	{
// 		calculate_scale(vars->map);
// 		parse_map(vars);
// 		move_map(vars);
// 	}
// 	else if (vars->map->scale.projection == 2)
// 		apply_rotation(vars, 1.57, 'x');
// }

int	handle_movement(int keycode, t_vars *vars)
{
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(vars->mlx_info.mlx_connection, vars->mlx_info.mlx_window);
        exit(0);
    }
	// else if (keycode == KEY_DOWN)
	// 	total_offset_y += 20;
	// else if (keycode == KEY_LEFT)
	// 	total_offset_x -= 20;
	// else if (keycode == KEY_RIGHT)
	// 	total_offset_x += 20;
	// // else if (keycode == KEY_SPACE)
	// 	// reset_shape(keycode, vars, &total_offset_x, &total_offset_y);
	// // else if (keycode == KEY_P)
	// 	// change_projection(vars);
	// if (keycode >= KEY_LEFT && keycode <= KEY_DOWN)
	// {
	// 	vars->map.map_range.max_x = total_offset_x;
	// 	vars->map.map_range. = total_offset_y;
	// 	move_to_center(vars);
	// 	draw_new_image(vars);
	// }
   
    return (0);
}

// int	zoom_in_and_out(int keycode, t_vars *vars)
// {
// 	float	zoom_factor;

// 	zoom_factor = 1.0;
// 	if (keycode == KEY_Z)
// 		zoom_factor = 1.1;
// 	else if (keycode == KEY_O)
// 		zoom_factor = 0.9;
// 	update_zoom(vars, zoom_factor);
// 	draw_new_image(vars);
// 	return (0);
// }

// void	iso_point(t_vars *vars)
// {
// 	apply_rotation(vars, 0.785398, 'z');
// 	apply_rotation(vars, 0.955316618, 'x');
// }