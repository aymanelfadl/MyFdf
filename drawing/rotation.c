#include "../fdf.h"

static void	rotate_x_axis(float *y, float *z, float angle)
{
	float	temp;

	temp = *y;
	*y = temp * cos(angle) - *z * sin(angle);
	*z = temp * sin(angle) + *z * cos(angle);
}

static void	rotate_y_axis(float *x, float *z, float angle)
{
	float	temp;

	temp = *x;
	*x = temp * cos(angle) + *z * sin(angle);
	*z = -temp * sin(angle) + *z * cos(angle);
}

static void	rotate_z_axis(float *x, float *y, float angle)
{
	float	temp;

	temp = *x;
	*x = temp * cos(angle) - *y * sin(angle);
	*y = temp * sin(angle) + *y * cos(angle);
}

void	rotate_point(t_point *point, float angle, char axis)
{
	float	x;
	float	y;
	float	z;

	x = point->x;
	y = point->y;
	z = point->z;
	if (axis == 'x')
		rotate_x_axis(&y, &z, angle);
	else if (axis == 'y')
		rotate_y_axis(&x, &z, angle);
	else
		rotate_z_axis(&x, &y, angle);
	point->x = x;
	point->y = y;
	point->z = z;
}

void	apply_rotation(t_vars *vars, float angle, char axis)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map.map_height)
	{
		j = 0;
		while (j < vars->map.map_width)
		{
			rotate_point(&vars->map.map_points[i][j], angle, axis);
			j++;
		}
		i++;
	}
    move_to_center(vars);
}