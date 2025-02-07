/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelfadl <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:45:35 by aelfadl           #+#    #+#             */
/*   Updated: 2025/02/03 11:45:36 by aelfadl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_vars(t_vars *vars)
{
	vars->map.map_name = NULL;
	vars->map.map_height = 0;
	vars->map.map_width = 0;
	vars->map.map_scale = 1;
	vars->map.map_offset_x = 0;
	vars->map.map_offset_y = 0;
	vars->map.map_points = NULL;
	vars->map.map_range.max_x = INT_MIN;
	vars->map.map_range.min_x = INT_MAX;
	vars->map.map_range.max_y = INT_MIN;
	vars->map.map_range.min_y = INT_MAX;
	vars->map.map_range.max_z = INT_MIN;
	vars->map.map_range.min_z = INT_MAX;
	vars->img.img = NULL;
	vars->img.addr = NULL;
	vars->img.bits_per_pixel = 0;
	vars->img.line_length = 0;
	vars->img.endian = 0;
	vars->mlx_info.mlx_connection = NULL;
	vars->mlx_info.mlx_window = NULL;
	vars->mlx_info.mlx_window_height = 0;
	vars->mlx_info.mlx_window_width = 0;
	vars->head = NULL;
	vars->view = 0;
}

void	points_init(t_vars *var)
{
	int	i;
	int	j;

	i = 0;
	while (i < var->map.map_height)
	{
		j = 0;
		while (j < var->map.map_width)
		{
			var->map.map_points[i][j].x = 0;
			var->map.map_points[i][j].y = 0;
			var->map.map_points[i][j].z = 0;
			var->map.map_points[i][j].valid_point = 0;
			j++;
		}
		i++;
	}
}

int	interpolate_color(int color1, int color2, float fraction)
{
	int	red;
	int	green;
	int	blue;

	red = ((1 - fraction) * ((color1 >> 16) & 0xFF)) + (fraction
			* ((color2 >> 16) & 0xFF));
	green = ((1 - fraction) * ((color1 >> 8) & 0xFF)) + (fraction
			* ((color2 >> 8) & 0xFF));
	blue = ((1 - fraction) * (color1 & 0xFF)) + (fraction * (color2 & 0xFF));
	return ((red << 16) | (green << 8) | blue);
}

void	set_color(t_vars *var, int x, int y, char *colors)
{
	char	**color;

	color = ft_split((const char *)colors, ',');
	if (color[1])
	{
		var->map.map_points[x][y].color = ft_atoi_base(color[1] + 2, 16);
		free(color[1]);
	}
	else
	{
		if (ft_atoi(color[0]) <= -20)
			var->map.map_points[x][y].color = 0x001B44;
		else if (ft_atoi(color[0]) <= 0)
			var->map.map_points[x][y].color = 0x0088CC;
		else if (ft_atoi(color[0]) <= 20)
			var->map.map_points[x][y].color = 0x22AA22;
		else if (ft_atoi(color[0]) <= 50)
			var->map.map_points[x][y].color = 0xFFD700;
		else if (ft_atoi(color[0]) <= 100)
			var->map.map_points[x][y].color = 0x8B4513;
		else
			var->map.map_points[x][y].color = 0xFFFFFF;
	}
	free(color[0]);
	free(color);
}
