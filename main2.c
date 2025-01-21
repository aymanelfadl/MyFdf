
#include "fdf.h"

int main(int argc, char *argv[])
{
    t_vars my_var;
    t_map my_map;
    my_var.map.map_name = argv[1];
    map_dimension(&my_var);
    ft_printf("h::%d\nd::%d\n",my_var.map.map_height, my_var.map.map_width);       
}