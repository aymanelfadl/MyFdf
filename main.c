#include "fdf.h"

int main(int argc, char *argv[])
{
    t_vars vars;
   
    if (argc == 2)
    {
        vars.map.map_name = argv[1];
        map_dimension(&vars);
        ft_printf("w::%d\nh::%d\n", vars.map.map_width, vars.map.map_height);
        map_allocatation(&vars);
        add_points(&vars);
        for (int i = 0; i < vars.map.map_height ; i++)
        {
            for (int j = 0; j < vars.map.map_width; j++)
            {
                ft_printf("<x:%d :: y:%d :: z:%d :: color:%d> ", 
                    vars.map.map_points[i][j].x,
                    vars.map.map_points[i][j].y,
                    vars.map.map_points[i][j].z,
                    vars.map.map_points[i][j].color);
            }
            ft_printf("\n");
        }
        // window_init(&vars);
        // if (vars.head)
        //     free_all(&vars.head);
        return 0;
    }
    ft_printf("\n");
}


