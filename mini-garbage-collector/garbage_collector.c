#include "../fdf.h"

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
    t_allocation *current = *head;
    while (current) {
        t_allocation *next = current->next;
        free(current->ptr);
        free(current);
        current = next;
    }
    *head = NULL;
}