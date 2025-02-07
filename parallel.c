/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelfadl <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:44:47 by aelfadl           #+#    #+#             */
/*   Updated: 2025/02/03 11:44:49 by aelfadl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_parallel_projection(t_vars *vars)
{
	if (vars->view == 1)
		apply_rotation(vars, -M_PI / 2, 'y');
	else if (vars->view == 2)
		apply_rotation(vars, M_PI / 2, 'y');
	else if (vars->view == 3)
		apply_rotation(vars, M_PI / 2, 'x');
	else if (vars->view == 4)
		apply_rotation(vars, -M_PI / 2, 'x');
	else if (vars->view == 5)
		apply_rotation(vars, M_PI, 'y');
}

void	parallel_projection(t_vars *vars)
{
	static int	view;

	mlx_destroy_image(vars->mlx_info.mlx_connection, vars->img.img);
	img_init(vars);
	if (vars->head)
		free_all(&vars->head);
	map_init(vars);
	scale_init(vars);
	vars->view = ++view % 5;
	apply_parallel_projection(vars);
	move_to_center(vars);
	draw_img(vars);
	mlx_put_image_to_window(vars->mlx_info.mlx_connection,
		vars->mlx_info.mlx_window, vars->img.img, 0, 0);
}
