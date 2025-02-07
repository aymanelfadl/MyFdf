/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelfadl <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:43:20 by aelfadl           #+#    #+#             */
/*   Updated: 2025/02/03 11:43:21 by aelfadl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void map_dimension_helper(t_vars *var, int fd, char *line)
{
    int max_width;

    if (!line)
        ft_gnl_err(fd, line, "Err: Not a Valid Map in Map_Dimension.");
    while (line)
    {
        if (!valid_line(line))
            ft_gnl_err(fd, line, "Err: Not a Valid Map in Map_Dimension.");
        max_width = count_points(line, ' ');
        if (max_width > var->map.map_width)
            var->map.map_width = max_width;
        var->map.map_height++;
        free(line);
        line = get_next_line(fd);
    }
}
void map_dimension(t_vars *var)
{
    char    *line;
    int     fd;

    fd = open(var->map.map_name, O_RDONLY);
    if (fd < 0)
        ft_gnl_err(fd, NULL, "Err: Can't Open Map In map_dimension.");
    line = get_next_line(fd);
    map_dimension_helper(var, fd, line);
    close(fd);
}

void map_allocatation(t_vars *var)
{
    int i;

    i = 0;
    var->head = NULL;
    var->map.map_points = my_malloc((sizeof(t_point *) * var->map.map_height), 
        &var->head);
    if (!var->map.map_points)
        map_allocation_error(var, 1);
    while (i < var->map.map_height)
    {
        var->map.map_points[i] = my_malloc((sizeof(t_point) 
            * var->map.map_width), &var->head);
        if (!var->map.map_points[i])
            map_allocation_error(var, 2);
        i++;
    }
    points_init(var);
}

void get_points(t_vars *var, char *line, int i)
{
    char    **points_height;
    int     j;

    points_height = ft_split(line, ' ');
    if (!points_height)
        return;
    j = -1;
    while (++j < var->map.map_width && points_height[j])
    {
        var->map.map_points[i][j].x = j;
        var->map.map_points[i][j].y = i;
        var->map.map_points[i][j].z = ft_atoi(points_height[j]);
        set_color(var, i, j, points_height[j]);
        var->map.map_points[i][j].valid_point = 1;
    }
    free_points_height(points_height);
}

void add_points(t_vars *var)
{
    int     fd;
    char    *line;
    int     i;

    i = 0;
    fd = open(var->map.map_name, O_RDONLY);
    if (fd < 0)
        ft_gnl_err(fd, NULL, "Err: Can't Open Map In add_points.");
    line = get_next_line(fd);
    while (line)
    {
        if (!valid_line(line))
            ft_gnl_err(fd, NULL, "Err: Not a Valid Map in Add_points.");
        get_points(var, line, i++);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
}
