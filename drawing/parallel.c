#include "../fdf.h"

void apply_front_view(t_point *p)
{
    p->x = p->x;
    p->y = p->y;
}

void apply_right_side_view(t_point *p)
{
    p->x = p->z;
    p->y = p->y;
}

void apply_left_side_view(t_point *p)
{
    p->x = -p->z;
    p->y = p->y;
}

void apply_top_view(t_point *p)
{
    p->x = p->x;
    p->y = p->z;
}

void apply_bottom_view(t_point *p)
{
    p->x = p->x;
    p->y = -p->z;
}

void apply_back_view(t_point *p)
{
    p->x = -p->x;
    p->y = p->y;
}

void parallel_points(t_point *p, int view)
{
    if (view == 0)
        apply_front_view(p);    // Front
    else if (view == 1)
        apply_right_side_view(p);  // Right
    else if (view == 2)
        apply_left_side_view(p);   // Left
    else if (view == 3)
        apply_top_view(p);      // Up/Top
    else if (view == 4)
        apply_bottom_view(p);   // Down/Bottom
    else if (view == 5)
        apply_back_view(p);     // Back
}

void apply_parallel_projection(t_vars *vars)
{
    int x;
    int y;

    y = 0;
    while (y < vars->map.map_height)
    {
        x = 0;
        while (x < vars->map.map_width)
        {
            parallel_points(&vars->map.map_points[y][x], vars->view);
            x++;
        }
        y++;
    }
}