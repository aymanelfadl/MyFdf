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
