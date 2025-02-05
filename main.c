/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelfadl <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:42:14 by aelfadl           #+#    #+#             */
/*   Updated: 2025/02/03 11:42:15 by aelfadl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void init_vars(t_vars *vars)
{
    if (!vars)
        return; // Exit if the pointer is NULL

    // Initialize t_map
    vars->map.map_name = NULL;
    vars->map.map_height = 0;
    vars->map.map_width = 0;
    vars->map.map_scale = 1.0f;
    vars->map.map_offset_x = 0;
    vars->map.map_offset_y = 0;
    vars->map.map_points = NULL;
    vars->map.map_range.max_x = INT_MIN;
    vars->map.map_range.min_x = INT_MAX;
    vars->map.map_range.max_y = INT_MIN;
    vars->map.map_range.min_y = INT_MAX;
    vars->map.map_range.max_z = INT_MIN;
    vars->map.map_range.min_z = INT_MAX;

    // Initialize t_img
    vars->img.img = NULL;
    vars->img.addr = NULL;
    vars->img.bits_per_pixel = 0;
    vars->img.line_length = 0;
    vars->img.endian = 0;

    // Initialize t_mlx_info
    vars->mlx_info.mlx_connection = NULL;
    vars->mlx_info.mlx_window = NULL;
    vars->mlx_info.mlx_window_height = 0;
    vars->mlx_info.mlx_window_width = 0;

    // Initialize t_allocation (memory tracking)
    vars->head = NULL;

    // Initialize view
    vars->view = 0; // Default view (you can set this to any default value)
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc == 2)
	{
		init_vars(&vars);
		vars.map.map_name = argv[1];
		map_init(&vars);
		window_init(&vars);
		set_default_img(&vars);
		draw_img(&vars);
		mlx_put_image_to_window(vars.mlx_info.mlx_connection,
			vars.mlx_info.mlx_window, vars.img.img, 0, 0);
		hooks_init(&vars);
		mlx_loop(vars.mlx_info.mlx_connection);
		if (vars.head)
			free_all(&vars.head);
		return (0);
	}
	ft_printf("Err: ./fdf <map_name.fdf>\n");
}
