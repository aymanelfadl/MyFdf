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

static void	set_boundaries_helper(t_vars *vars, t_map_range *range, int i,
		int j)
{
	if (vars->map.map_points[i][j].valid_point)
	{
		if (vars->map.map_points[i][j].x < range->min_x)
			range->min_x = vars->map.map_points[i][j].x;
		if (vars->map.map_points[i][j].x > range->max_x)
			range->max_x = vars->map.map_points[i][j].x;
		if (vars->map.map_points[i][j].y < range->min_y)
			range->min_y = vars->map.map_points[i][j].y;
		if (vars->map.map_points[i][j].y > range->max_y)
			range->max_y = vars->map.map_points[i][j].y;
	}
}

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
			set_boundaries_helper(vars, &range, i, j);
	}
	vars->map.map_range = range;
}

static void	move_to_center_helper(t_vars *vars, int center[2], int i, int j)
{
	if (vars->map.map_points[i][j].valid_point)
	{
		vars->map.map_points[i][j].x += center[0] + vars->map.map_offset_x
			- vars->map.map_range.min_x;
		vars->map.map_points[i][j].y += center[1] + vars->map.map_offset_y
			- vars->map.map_range.min_y;
	}
}

void	move_to_center(t_vars *vars)
{
	int	center[2];
	int	i;
	int	j;

	set_boundaries(vars);
	center[0] = (vars->mlx_info.mlx_window_width - (vars->map.map_range.max_x
				- vars->map.map_range.min_x)) / 2;
	center[1] = (vars->mlx_info.mlx_window_height - (vars->map.map_range.max_y
				- vars->map.map_range.min_y)) / 2;
	i = -1;
	while (++i < vars->map.map_height)
	{
		j = -1;
		while (++j < vars->map.map_width)
			move_to_center_helper(vars, center, i, j);
	}
}
