#include <stdio.h> 
#include "../libft/libft.h"
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
    char *d = NULL;
    int fd = open("../maps/test_maps/42.fdf", O_RDWR);
    d = get_next_line(fd);
    while (d != NULL)
    {
        ft_printf("%s",d);
        free(d);
        d = get_next_line(fd);
    }
    return 0;
    }