/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelfadl <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:42:36 by aelfadl           #+#    #+#             */
/*   Updated: 2025/02/03 11:42:37 by aelfadl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_img(int keycode, t_vars *vars)
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
	mlx_put_image_to_window(vars->mlx_info.mlx_connection,
		vars->mlx_info.mlx_window, vars->img.img, 0, 0);
}

void	rotate_img(int keycode, t_vars *vars)
{
	mlx_destroy_image(vars->mlx_info.mlx_connection, vars->img.img);
	img_init(vars);
	if (keycode == KEY_W)
		apply_rotation(vars, 0.1, 'x');
	else if (keycode == KEY_S)
		apply_rotation(vars, -0.1, 'x');
	else if (keycode == KEY_D)
		apply_rotation(vars, 0.1, 'y');
	else if (keycode == KEY_E)
		apply_rotation(vars, 0.1, 'z');
	else if (keycode == KEY_Q)
		apply_rotation(vars, -0.1, 'z');
	else
		apply_rotation(vars, -0.1, 'y');
	move_to_center(vars);
	draw_img(vars);
	mlx_put_image_to_window(vars->mlx_info.mlx_connection,
		vars->mlx_info.mlx_window, vars->img.img, 0, 0);
}

void	re_render_img(t_vars *vars)
{
	mlx_destroy_image(vars->mlx_info.mlx_connection, vars->img.img);
	if (vars->head)
		free_all(&vars->head);
	map_init(vars);
	vars->map.map_offset_x = 0;
	vars->map.map_offset_y = 0;
	img_init(vars);
	scale_init(vars);
	iso_point(vars);
	move_to_center(vars);
	draw_img(vars);
	mlx_put_image_to_window(vars->mlx_info.mlx_connection,
		vars->mlx_info.mlx_window, vars->img.img, 0, 0);
}

int	handle_movement(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		clean_mlx_infos(vars);
	else if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT
		|| keycode == KEY_RIGHT)
		move_img(keycode, vars);
	else if (keycode == KEY_I || keycode == KEY_O)
		zoom_img(keycode, vars);
	else if (keycode == KEY_E || keycode == KEY_Q || keycode == KEY_W
		|| keycode == KEY_A || keycode == KEY_D || keycode == KEY_S)
		rotate_img(keycode, vars);
	else if (keycode == KEY_SPACE)
		re_render_img(vars);
	else if (keycode == KEY_P)
		parallel_projection(vars);
	return (0);
}

void	hooks_init(t_vars *vars)
{
	mlx_hook(vars->mlx_info.mlx_window, 2, 1L << 0, handle_movement, vars);
	mlx_hook(vars->mlx_info.mlx_window, 17, 0, clean_mlx_infos, vars);
}
