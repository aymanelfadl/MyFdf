#include <stdio.h> 
#include "../libft/libft.h"
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
    char *d = NULL;
    int fd = open("../maps/test_maps/20-60.fdf", O_RDWR);
    d = get_next_line(fd);
    while (d != NULL)
    {
        printf("%s",d);
        d = get_next_line(fd);
    }
    close(fd);
    fd = open("../maps/test_maps/20-60.fdf", O_RDWR);
    d = get_next_line(fd);
    while (d != NULL)
    {
        printf("---\n%s",d);
        d = get_next_line(fd);
    }
    close(fd);
    return 0;
    }