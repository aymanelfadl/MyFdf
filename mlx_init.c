#include "fdf.h"

void    map_init(t_vars *vars)
{
    map_dimension(vars);
    map_allocatation(vars);
    add_points(vars);
}
void    window_init(t_vars *vars)
{
    vars->mlx_info.mlx_window_height = WINDOW_HEIGHT;
    vars->mlx_info.mlx_window_width = WINDOW_WIDTH;
    vars->mlx_info.mlx_connection = mlx_init();
    vars->mlx_info.mlx_window = mlx_new_window(vars->mlx_info.mlx_connection, vars->mlx_info.mlx_window_height, vars->mlx_info.mlx_window_width, "FDF PROJECT");
}
void    img_init(t_vars *vars)
{
    vars->img.img =  mlx_new_image(vars->mlx_info.mlx_connection, vars->mlx_info.mlx_window_height, vars->mlx_info.mlx_window_width);
    if (!vars->img.img)
        return ;
    vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
}

void    set_default_img(t_vars *vars)
{
    img_init(vars);
    apply_scale(vars);
    iso_point(vars); 
    move_to_center(vars);
}


void	iso_point(t_vars *vars)
{
	apply_rotation(vars, 0.785398, 'z');
	apply_rotation(vars, 0.955316618, 'x');
}