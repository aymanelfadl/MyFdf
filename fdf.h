
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


#define DEFAULT_COLOR 0xFFFFFF
#define WINDOW_WIDTH 4480
#define WINDOW_HEIGHT 2520



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
    float x;
    float y;
    float z;
    int color;
    int valid_point;
} t_point;


/*
    map range presentation:
*/
typedef struct s_map_range
{
    int max_x;
    int min_x;
    int max_y;
    int min_y;
}   t_map_range;
/*
    map presentation:
*/
typedef struct s_map
{
	char *map_name;
    int map_height;
    int map_width;
    int map_scale;
    t_point **map_points;
    t_map_range map_range;
} t_map;



typedef struct s_mlx_info
{
    void *mlx_connection;
    void *mlx_window;
    int     mlx_window_height;
    int     mlx_window_width;
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


/*  Image Functions */
void    draw_img(t_vars *vars);
int     right_scale(t_vars *vars);
void set_boundaries(t_vars *vars);
void     move_to_center(t_vars *vars);
void    apply_scale(t_vars *vars);
void	apply_rotation(t_vars *vars, float angle, char axis);
void	iso_point(t_vars *vars);


/* Parsing map Functions */
void	ft_gnl_err(int fd, char *line, char *str);
int     ft_isspace(char c);
int     valid_line(char *line);
int     count_points(char *s, char c);
void    map_dimension(t_vars *var);
void    map_allocatation(t_vars *var);
int     ft_atoi_base(char *str, int base);
void	add_points(t_vars *var);
void	set_color(t_vars *var, char *colors, int x, int y);


/* garbage collector Functions: */
void free_all(t_allocation **head);
void *my_malloc(size_t size, t_allocation **head);

#endif
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

