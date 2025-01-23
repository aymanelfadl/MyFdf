#include "fdf.h"


int main(int argc, char *argv[])
{
    t_vars vars;
    if (argc == 2)
    {
        vars.map.map_name = argv[1];
        map_dimension(&vars);
        ft_printf("w::%d\nh::%d", vars.map.map_width, vars.map.map_height);
        return 0;
    }
    ft_printf("\n");
}