
#include "fdf.h"

int main(int argc, char *argv[])
{
    t_vars my_var;
    my_var.map.map_name = argv[1];
    map_dimension(&my_var);
    set_points(&my_var);
    ft_printf("h::%d\nw::%d\n",my_var.map.map_height, my_var.map.map_width);
    for(int i = 0 ; i < my_var.map.map_height; i++)
    { 
        for(int j = 0 ; j < my_var.map.map_width; j++)
            ft_printf("[x:%d, y:%d, z:%d, c::%x]    ",my_var.map.map_points[i][j].x,
                                                  my_var.map.map_points[i][j].y,
                                                  my_var.map.map_points[i][j].z,
                                                  my_var.map.map_points[i][j].color);
                ft_printf("\n");
    }

}