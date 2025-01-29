#include "../fdf.h"
#include <math.h>
#include <stdio.h>

static void rotate_x_axis(float *y, float *z, float angle)
{
    float temp;

    temp = *y;
    *y = temp * cos(angle) - *z * sin(angle);
    *z = temp * sin(angle) + *z * cos(angle);
}

static void rotate_y_axis(float *x, float *z, float angle)
{
    float temp;
    
    temp = *x;
    *x = temp * cos(angle) + *z * sin(angle);
    *z = -temp * sin(angle) + *z * cos(angle);
}

static void rotate_z_axis(float *x, float *y, float angle)
{
    float temp;
    
    temp = *x;
    *x = temp * cos(angle) - *y * sin(angle);
    *y = temp * sin(angle) + *y * cos(angle);
}

void rotate_point(t_point *point, float angle, char axis)
{
    float x = (float) point->x;
    float y = (float) point->y;
    float z = (float) point->z;

    x = (float) point->x;
    y = (float) point->y;
    z = (float) point->z;
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

void apply_rotation(t_vars *vars, float angle, char axis)
{
    int i;
    int j;

    i = -1;
    while (++i < vars->map.map_height)
    {
        j = -1;
        while (++j < vars->map.map_width)
            rotate_point(&vars->map.map_points[i][j], angle, axis);
    }
}