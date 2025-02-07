/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelfadl <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:44:00 by aelfadl           #+#    #+#             */
/*   Updated: 2025/02/03 11:44:02 by aelfadl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	step_x(t_point *start_point, t_point *end_point)
{
	if (end_point->x > start_point->x)
		return (1);
	else
		return (-1);
}

int	step_y(t_point *start_point, t_point *end_point)
{
	if (end_point->y > start_point->y)
		return (1);
	else
		return (-1);
}

float	right_scale(t_vars *vars)
{
	float	x_scale;
	float	y_scale;
	float	max_projected_width;

	max_projected_width = vars->map.map_height + vars->map.map_width;
	x_scale = vars->mlx_info.mlx_window_height / max_projected_width;
	y_scale = vars->mlx_info.mlx_window_width / max_projected_width;
	if (x_scale < y_scale)
		return (x_scale);
	else
		return (y_scale);
}

void	scale_init(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map.map_height)
	{
		j = 0;
		while (j < vars->map.map_width)
		{
			vars->map.map_points[i][j].x *= vars->map.map_scale;
			vars->map.map_points[i][j].y *= vars->map.map_scale;
			vars->map.map_points[i][j].z *= vars->map.map_scale;
			j++;
		}
		i++;
	}
}

void	apply_scale(t_vars *vars)
{
	int		i;
	int		j;
	float	hight_factor;

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
			vars->map.map_points[i][j].z *= (vars->map.map_scale
					* hight_factor);
			j++;
		}
		i++;
	}
}
