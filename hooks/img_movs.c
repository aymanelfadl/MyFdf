#include "../fdf.h"


void  move_up(t_vars *vars)
{
  int i;
  int j;
  
  i = 0;
  while (i < vars->map.map_height)
  {
      j = 0;
      while (j < vars->map.map_width)
      {
        vars->map.map_points[i][j].y -= 20;
        j++;
      }
      i++;
  }
}
void  move_down(t_vars *vars)
{
  int i;
  int j;
  
  i = 0;
  while (i < vars->map.map_height)
  {
      j = 0;
      while (j < vars->map.map_width)
      {
        vars->map.map_points[i][j].y += 20;
        j++;
      }
      i++;
  }
}

void  move_right(t_vars *vars)
{
  int i;
  int j;
  
  i = 0;
  while (i < vars->map.map_height)
  {
      j = 0;
      while (j < vars->map.map_width)
      {
        vars->map.map_points[i][j].x += 20;
        j++;
      }
      i++;
  }
}
void  move_left(t_vars *vars)
{
  int i;
  int j;
  
  i = 0;
  while (i < vars->map.map_height)
  {
      j = 0;
      while (j < vars->map.map_width)
      {
        vars->map.map_points[i][j].x -= 20;
        j++;
      }
      i++;
  }
}