/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelfadl <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:43:07 by aelfadl           #+#    #+#             */
/*   Updated: 2025/02/03 11:43:08 by aelfadl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*my_malloc(size_t size, t_allocation **head)
{
	void			*ptr;
	t_allocation	*new_alloc;

	ptr = malloc(size);
	if (!ptr)
		return (ft_printf("Memory allocation failed\n"), NULL);
	new_alloc = (t_allocation *)malloc(sizeof(t_allocation));
	if (!new_alloc)
	{
		free (ptr);
		return (ft_printf("Memory allocation tracking failed\n"), NULL);
	}
	new_alloc->ptr = ptr;
	new_alloc->next = *head;
	*head = new_alloc;
	return (ptr);
}
void map_allocation_error(t_vars *var, int error_type)
{
    free_all(&var->head);
    if (error_type == 1)
        ft_printf("Err: Can't Allocat Height");
    else
        ft_printf("Err: Can't Allocat Width");
    exit(EXIT_FAILURE);
}

void	free_all(t_allocation **head)
{
	t_allocation	*current;
	t_allocation	*next;

	current = *head;
	while (current)
	{
		next = current->next;
		free(current->ptr);
		free(current);
		current = next;
	}
	*head = NULL;
}

void free_points_height(char **points_height)
{
    int j;

    j = -1;
    while (points_height[++j])
        free(points_height[j]);
    free(points_height);
}

int	clean_mlx_infos(t_vars *vars)
{
	mlx_destroy_image(vars->mlx_info.mlx_connection, vars->img.img);
	mlx_destroy_window(vars->mlx_info.mlx_connection,
		vars->mlx_info.mlx_window);
	mlx_destroy_display(vars->mlx_info.mlx_connection);
	free(vars->mlx_info.mlx_connection);
	free_all(&vars->head);
	exit(0);
}
