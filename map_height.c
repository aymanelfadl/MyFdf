/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelfadl <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:56:50 by aelfadl           #+#    #+#             */
/*   Updated: 2025/02/07 13:56:51 by aelfadl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_height_boundaries(t_vars *vars)
{
	int			i;
	int			j;
	t_map_range	range;

	i = -1;
	range = vars->map.map_range;
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
