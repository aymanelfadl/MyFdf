
#ifndef FDF_H
#define FDF_H

# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include "getNextLine/get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>


#ifndef DEFAULT_COLOR
    #define DEFAULT_COLOR 0xFFFFFF
#endif


/*
    Allocation information
*/
typedef struct s_allocation
{
    void *ptr;
    struct s_allocation *next;
} t_allocation;


/*
    image presentat:
*/
typedef struct s_img 
{
    void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}   t_img;

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

typedef struct s_mlx_info
{
    void *mlx_connection;
    void *mlx_window;
}   t_mlx_info;

/*
	all My variables
*/
typedef struct  s_vars
{
	t_map map;
    t_img img;
	t_mlx_info mlx_info;
    t_allocation *head;

} t_vars;


/* Window Functions */
void    window_init(t_vars *vars);


/* Parsing map Functions */
void	ft_gnl_err(int fd, char *line, char *str);
int     ft_isspace(char c);
int     valid_line(char *line);
int     count_points(char *s, char c);
void    map_dimension(t_vars *var);
void    map_allocatation(t_vars *var);
int	ft_atoi_base(char *str, int base);
void	add_points(t_vars *var);


/* garbage collector Functions: */
void free_all(t_allocation **head);
void *my_malloc(size_t size, t_allocation **head);

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