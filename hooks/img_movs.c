#include "../fdf.h"


void  move_up(t_vars *vars)
{
    vars->map.map_offset_y -= 20;
  move_to_center(vars);
}
void  move_down(t_vars *vars)
{
  vars->map.map_offset_y += 20;
  move_to_center(vars);
}

void  move_right(t_vars *vars)
{
  vars->map.map_offset_x += 20;
  move_to_center(vars);
}
void  move_left(t_vars *vars)
{
  vars->map.map_offset_x -= 20;
  move_to_center(vars);
}