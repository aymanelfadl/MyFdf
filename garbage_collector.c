#include "fdf.h"

void *my_malloc(size_t size, t_allocation **head) {
    void *ptr = malloc(size);
    if (!ptr) {
        ft_printf("Memory allocation failed\n");
        free_all(head);
        return (NULL);
    }

    t_allocation *new_alloc = (t_allocation *)malloc(sizeof(t_allocation));
    if (!new_alloc) {
        ft_printf("Memory allocation tracking failed\n");
        free(ptr);
        return (NULL);
    }
    new_alloc->ptr = ptr;
    new_alloc->next = *head;
    *head = new_alloc;
    return ptr;
}

void free_all(t_allocation **head) {
    t_allocation *current;
    
    current = *head;
    while (current) {
        t_allocation *next;
        
        next = current->next;
        free(current->ptr);
        free(current);
        current = next;
    }
    *head = NULL;
}

int clean_mlx_infos(t_vars *vars)
{
    mlx_destroy_image (vars->mlx_info.mlx_connection, vars->img.img);
    mlx_destroy_window (vars->mlx_info.mlx_connection, vars->mlx_info.mlx_window);
	mlx_destroy_display (vars->mlx_info.mlx_connection);
	free (vars->mlx_info.mlx_connection);
	free_all (&vars->head);
    exit (0);
}