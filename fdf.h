
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


# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 600


// keyscode
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_Q 113
# define KEY_E 101
# define KEY_I 105
# define KEY_Z 122
# define KEY_O 111
# define KEY_P 112
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_SPACE 32


# define KEY_ESC 65307




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
    int max_z;
    int min_z;
}   t_map_range;
/*
    map presentation:
*/
typedef struct s_map
{
	char *map_name;
    int map_height;
    int map_width;
    float map_scale;
    int map_offset_x;
    int map_offset_y;
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
    int view;

} t_vars;


/* Window Functions */
void    window_init(t_vars *vars);
void    set_default_img(t_vars *vars);

/*  Hooks Events    */
int	handle_movement(int keycode, t_vars *vars);
void  zoom_in(t_vars *vars);
void  zoom_out(t_vars *vars);
void hooks_init(t_vars *vars);



/*  Image Functions */
void    img_init(t_vars *vars);
int     step_x(t_point *start_point, t_point *end_point);
int     step_y(t_point *start_point, t_point *end_point);
void    draw_img(t_vars *vars);
float     right_scale(t_vars *vars);
void    set_boundaries(t_vars *vars);
float	calculate_height_factor(t_vars *vars);
void    set_height_boundaries(t_vars *vars);
void     move_to_center(t_vars *vars);
void    apply_scale(t_vars *vars);
void	apply_rotation(t_vars *vars, float angle, char axis);
void	iso_point(t_vars *vars);
void    apply_scale(t_vars *vars);
int	    interpolate_color(int color1, int color2, float fraction);
void    apply_parallel_projection(t_vars *vars);

/* Parsing map Functions */
void	ft_gnl_err(int fd, char *line, char *str);
int     ft_isspace(char c);
int     valid_line(char *line);
int     count_points(char *s, char c);
void    map_dimension(t_vars *var);
void    map_allocatation(t_vars *var);
int     ft_atoi_base(char *str, int base);
void	add_points(t_vars *var);
void	set_color(t_vars *var, int x, int y, char *defualt_color);
void    map_init(t_vars *vars);


/* garbage collector Functions: */
void free_all(t_allocation **head);
void *my_malloc(size_t size, t_allocation **head);
int   clean_mlx_infos(t_vars *vars);

#endif