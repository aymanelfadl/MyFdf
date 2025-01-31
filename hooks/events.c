#include "../fdf.h"

void move_img(int keycode, t_vars *vars)
{
  mlx_destroy_image(vars->mlx_info.mlx_connection, vars->img.img);
  img_init(vars);
  if (keycode == KEY_UP)
    move_up(vars);
  else if (keycode == KEY_DOWN)
    move_down(vars);
  else if (keycode == KEY_LEFT)
    move_left(vars);
  else 
    move_right(vars);
  draw_img(vars);
  mlx_put_image_to_window(vars->mlx_info.mlx_connection, vars->mlx_info.mlx_window, vars->img.img, 0, 0);
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

int	handle_movement(int keycode, t_vars *vars)
{
    if (keycode == KEY_ESC)
		  clean_mlx_infos(vars);
    else if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT || keycode == KEY_RIGHT)
      move_img(keycode, vars);
    else if (keycode == KEY_I || keycode == KEY_O)
      zoom_img(keycode, vars);
    return (0);
}
