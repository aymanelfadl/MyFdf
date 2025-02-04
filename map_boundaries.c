/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_boundaries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelfadl <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:43:48 by aelfadl           #+#    #+#             */
/*   Updated: 2025/02/03 11:43:50 by aelfadl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_boundaries(t_vars *vars)
{
	int			i;
	int			j;
	t_map_range	range;

	i = -1;
	range.min_x = vars->map.map_points[0][0].x;
	range.max_x = vars->map.map_points[0][0].x;
	range.min_y = vars->map.map_points[0][0].y;
	range.max_y = vars->map.map_points[0][0].y;
	while (++i < vars->map.map_height)
	{
		j = -1;
		while (++j < vars->map.map_width)
		{
			if (vars->map.map_points[i][j].x < range.min_x)
				range.min_x = vars->map.map_points[i][j].x;
			if (vars->map.map_points[i][j].x > range.max_x)
				range.max_x = vars->map.map_points[i][j].x;
			if (vars->map.map_points[i][j].y < range.min_y)
				range.min_y = vars->map.map_points[i][j].y;
			if (vars->map.map_points[i][j].y > range.max_y)
				range.max_y = vars->map.map_points[i][j].y;
		}
	}
	vars->map.map_range = range;
}

void	move_to_center(t_vars *vars)
{
	int	center_x;
	int	center_y;
	int	i;
	int	j;

	set_boundaries(vars);
	center_x = (vars->mlx_info.mlx_window_width - (vars->map.map_range.max_x
				- vars->map.map_range.min_x)) / 2;
	center_y = (vars->mlx_info.mlx_window_height - (vars->map.map_range.max_y
				- vars->map.map_range.min_y)) / 2;
	i = 0;
	while (i < vars->map.map_height)
	{
		j = 0;
		while (j < vars->map.map_width)
		{
			vars->map.map_points[i][j].x += center_x + vars->map.map_offset_x
				- vars->map.map_range.min_x;
			vars->map.map_points[i][j].y += center_y + vars->map.map_offset_y
				- vars->map.map_range.min_y;
			j++;
		}
		i++;
	}
}

void	set_height_boundaries(t_vars *vars)
{
	int			i;
	int			j;
	t_map_range	range;

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
		height_factor = (float)vars->map.map_width / height_range;
	else if (height_range < vars->map.map_width / 4)
		height_factor = 2.0;
	else
		height_factor = 1.0;
	return (height_factor);
}
