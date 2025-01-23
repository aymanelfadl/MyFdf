
#ifndef FDF_H
#define FDF_H

# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include "getNextLine/get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <math.h>


#ifndef DEFAULT_COLOR
    #define DEFAULT_COLOR 0xFFFFFF
#endif

/*
    point presentation:
*/
typedef struct s_point
{
    int x;
    int y;
    int z;
    int color;

} t_point;

/*
    map presentation:
*/

typedef struct s_map
{
	char *map_name;
    int map_height;
    int map_width;
    t_point **map_points;
} t_map;

/*
	all My variables
*/

typedef struct  s_vars
{
	t_map map;

} t_vars;

/* Parsing map Functions */
int     ft_isspace(char c);
int     valid_line(char *line);
int     count_points(char *s, char c);
void    map_dimension(t_vars *var);


// /*
//     image presentation:
// */
// typedef struct	s_img {
// 	void	*img;  // mlx_new_image(mlx_connection, width, height)
// 	char	*addr; // img.addr now points to the start of your image data like this:
//                     // [Byte1][Byte2][Byte3][Byte4][Byte5][Byte6]...
//                     //  ^ img.addr points here
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// } t_img;


#endif