/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelfadl <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:42:23 by aelfadl           #+#    #+#             */
/*   Updated: 2025/02/03 11:42:24 by aelfadl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_vars *vars, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && y >= 0 && x <= vars->mlx_info.mlx_window_width
		&& y <= vars->mlx_info.mlx_window_height)
	{
		pixel = vars->img.addr + (y * vars->img.line_length + x
				* (vars->img.bits_per_pixel / 8));
		*(unsigned int *)pixel = color;
	}
}

void	ft_lower_slope(t_vars *vars, int *d, t_point *start_point,
		t_point *end_point)
{
	int		i;
	int		p;
	t_point	tmp_point;

	tmp_point = *start_point;
	i = 0;
	p = 2 * d[2] - d[1];
	ft_put_pixel(vars, tmp_point.x, tmp_point.y, tmp_point.color);
	while (i < d[1])
	{
		tmp_point.x += step_x(start_point, end_point);
		if (p < 0)
			p = p + 2 * d[2];
		else
		{
			tmp_point.y += step_y(start_point, end_point);
			p = p + 2 * d[2] - 2 * d[1];
		}
		ft_put_pixel(vars, tmp_point.x, tmp_point.y,
			interpolate_color(start_point->color, end_point->color, ((float)i
					/ d[1])));
		i++;
	}
}

void	ft_higher_slope(t_vars *vars, int *d, t_point *start_point,
		t_point *end_point)
{
	int		i;
	int		p;
	t_point	tmp_point;

	tmp_point = *start_point;
	i = 0;
	p = 2 * d[1] - d[2];
	ft_put_pixel(vars, tmp_point.x, tmp_point.y, tmp_point.color);
	while (i < d[2])
	{
		tmp_point.y += step_y(start_point, end_point);
		if (p < 0)
			p = p + 2 * d[1];
		else
		{
			tmp_point.x += step_x(start_point, end_point);
			p = p + 2 * d[1] - 2 * d[2];
		}
		ft_put_pixel(vars, tmp_point.x, tmp_point.y,
			interpolate_color(start_point->color, end_point->color, ((float)i
					/ d[2])));
		i++;
	}
}

// d[1] == dx AND d[2] == dy just cuase of 42 norms too many args;
void	ft_draw_line(t_vars *vars, t_point *p1, t_point *p2)
{
	int	*d;

	d = my_malloc((sizeof(int) * 2), &vars->head);
	if (!d)
		free_all(&vars->head);
	d[1] = abs((int)p2->x - (int)p1->x);
	d[2] = abs((int)p2->y - (int)p1->y);
	if (d[1] > d[2])
		ft_lower_slope(vars, d, p1, p2);
	else
		ft_higher_slope(vars, d, p1, p2);
}

void	draw_img(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map.map_height)
	{
		j = 0;
		while (j < vars->map.map_width)
		{
			if (vars->map.map_points[i][j].valid_point)
			{
				if (j + 1 < vars->map.map_width && vars->map.map_points[i][j
					+ 1].valid_point)
					ft_draw_line(vars, &vars->map.map_points[i][j],
						&vars->map.map_points[i][j + 1]);
				if (i + 1 < vars->map.map_height && vars->map.map_points[i
						+ 1][j].valid_point)
					ft_draw_line(vars, &vars->map.map_points[i][j],
						&vars->map.map_points[i + 1][j]);
			}
			j++;
		}
		i++;
	}
}
