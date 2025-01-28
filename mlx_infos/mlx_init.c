#include "../fdf.h"


void    imag_init(t_vars *vars)
{
    vars->img.img =  mlx_new_image(vars->mlx_info.mlx_connection, 1000, 1000);
    if (!vars->img.img)
        return ;
    vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
}

void    window_init(t_vars *vars)
{
    vars->mlx_info.mlx_connection = mlx_init();
    vars->mlx_info.mlx_window = mlx_new_window(vars->mlx_info.mlx_connection, 1000, 1000, "my first window");
    // imag_init(vars);
    // draw_img(vars);
    mlx_put_image_to_window(vars->mlx_info.mlx_connection, vars->mlx_info.mlx_window, vars->img.img, 50, 50);
    mlx_loop(vars->mlx_info.mlx_connection);
}