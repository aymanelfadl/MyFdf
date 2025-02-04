/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelfadl <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:45:15 by aelfadl           #+#    #+#             */
/*   Updated: 2025/02/03 11:45:16 by aelfadl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x_axis(float *y, float *z, float angle)
{
	float	temp_y;

	temp_y = *y;
	*y = temp_y * cos(angle) - *z * sin(angle);
	*z = temp_y * sin(angle) + *z * cos(angle);
}

static void	rotate_y_axis(float *x, float *z, float angle)
{
	float	temp_x;

	temp_x = *x;
	*x = temp_x * cos(angle) + *z * sin(angle);
	*z = -temp_x * sin(angle) + *z * cos(angle);
}

static void	rotate_z_axis(float *x, float *y, float angle)
{
	float	temp_x;

	temp_x = *x;
	*x = temp_x * cos(angle) - *y * sin(angle);
	*y = temp_x * sin(angle) + *y * cos(angle);
}

void	rotate_point(t_point *point, float angle, char axis)
{
	float	x;
	float	y;
	float	z;

	x = (float)point->x;
	y = (float)point->y;
	z = (float)point->z;
	if (axis == 'x')
		rotate_x_axis(&y, &z, angle);
	else if (axis == 'y')
		rotate_y_axis(&x, &z, angle);
	else if (axis == 'z')
		rotate_z_axis(&x, &y, angle);
	point->x = x;
	point->y = y;
	point->z = z;
}

void	apply_rotation(t_vars *vars, float angle, char axis)
{
	int	i;
	int	j;

	if (axis != 'x' && axis != 'y' && axis != 'z')
		return ;
	i = -1;
	while (++i < vars->map.map_height)
	{
		j = -1;
		while (++j < vars->map.map_width)
		{
			if (vars->map.map_points[i][j].valid_point)
				rotate_point(&vars->map.map_points[i][j], angle, axis);
		}
	}
}
