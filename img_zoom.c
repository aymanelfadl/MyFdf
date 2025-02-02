#include "fdf.h"

void    zoom_in(t_vars *vars)
{
    int i;
    int j;
    float hight_factor;

    hight_factor = calculate_height_factor(vars);
    i = 0;
    while (i < vars->map.map_height)
    {
        j = 0;
        while (j < vars->map.map_width)
        {
            vars->map.map_points[i][j].x *= 1.1;
            vars->map.map_points[i][j].y *= 1.1;
            vars->map.map_points[i][j].z *= (1.1 * hight_factor);
            j++;
        }
        i++;
    }
}

void    zoom_out(t_vars *vars)
{
    int i;
    int j;
    float hight_factor;

    hight_factor = calculate_height_factor(vars);
    i = 0;
    while (i < vars->map.map_height)
    {
        j = 0;
        while (j < vars->map.map_width)
        {
            vars->map.map_points[i][j].x *= 0.9;
            vars->map.map_points[i][j].y *= 0.9;
            vars->map.map_points[i][j].z *= (0.9 * hight_factor);
            j++;
        }
        i++;
    }
}

void zoom_img(int keycode, t_vars *vars)
{
  mlx_destroy_image(vars->mlx_info.mlx_connection, vars->img.img);
  img_init(vars);
  if (keycode == KEY_I)
    zoom_in(vars);
  else
    zoom_out(vars);
  move_to_center(vars);
  draw_img(vars);
  mlx_put_image_to_window(vars->mlx_info.mlx_connection, vars->mlx_info.mlx_window, vars->img.img, 0, 0);
}
