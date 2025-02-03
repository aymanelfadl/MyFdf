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

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc == 2)
	{
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
