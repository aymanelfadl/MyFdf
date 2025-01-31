#include "../fdf.h"

void move_img(int keycode, t_vars *vars)
{
  mlx_destroy_image(vars->mlx_info.mlx_connection, vars->img.img);
  img_init(vars);
  if (keycode == KEY_UP)
    vars->map.map_offset_y -= 20;
  else if (keycode == KEY_DOWN)
    vars->map.map_offset_y += 20;
  else if (keycode == KEY_LEFT)
    vars->map.map_offset_x -= 20;
  else 
    vars->map.map_offset_x += 20;
  move_to_center(vars);
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
void rotate_img(int keycode,t_vars *vars)
{
  mlx_destroy_image(vars->mlx_info.mlx_connection, vars->img.img);
  img_init(vars);
  if (keycode == KEY_W)
    apply_rotation(vars, 0.1, 'x');
  // else if (keycode == KEY_S)
  //   vars->map.map_offset_y += 20;
  // else if (keycode == KEY_D)
  //   vars->map.map_offset_x -= 20;
  // else 
  //   vars->map.map_offset_x += 20;
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
    else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_D || keycode == KEY_S)
      rotate_img(keycode, vars);
    return (0);
}
