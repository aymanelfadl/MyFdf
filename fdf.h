/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelfadl <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:11:54 by aelfadl           #+#    #+#             */
/*   Updated: 2025/01/20 14:11:55 by aelfadl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
#define FDF_H

# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include "libft/libft.h"
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
void    map_dimension(t_vars *var);
void    set_points(t_vars *var);
int     ft_isspace(char c);
void	allocate_points(t_vars *var);
size_t  count_points(char *s, char c);
int     valide_line(char *str);
int     ft_atoi_base(char *str, char *base);
int to_number(char *str);


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