#include "../fdf.h"

void	map_dimension(t_vars *var)
{
	char	*line;
	int		fd;
	int		max_width;

	fd = open(var->map.map_name, O_RDONLY);
	if (fd < 0)
		ft_gnl_err(fd, NULL, "Err: Can't Open Map In map_dimension.");
	var->map.map_height = 0;
	var->map.map_width = 0;
	line = get_next_line(fd);
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
	close(fd);
}

void	map_allocatation(t_vars *var)
{
	int		i;

	i = 0;
	var->head = NULL;
	var->map.map_points = my_malloc((sizeof(t_point) * var->map.map_height), &var->head);
	if (!var->map.map_points)
	{
		free_all(&var->head);
		ft_printf("Err: Can't Allocat Height");
		exit(EXIT_FAILURE);
	}
	while (i < var->map.map_height)
	{
		var->map.map_points[i] = my_malloc((sizeof(t_point) * var->map.map_width), &var->head);
		if (!var->map.map_points[i])
		{
			free_all(&var->head);
			ft_printf("Err: Can't Allocat Width");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	set_color(t_vars *var, char *colors, int x, int y)
{
	char	**color;

	color = ft_split((const char *)colors, ',');
	if (color[1])
	{
		var->map.map_points[x][y].color = ft_atoi_base(color[1] + 2, 16);
		free(color[1]);
	}
	else
		var->map.map_points[x][y].color = DEFAULT_COLOR;
	free(color[0]);
	free(color);

}


void get_points(t_vars *var, char *line, int i)
{
    char **points_height;
    int j;

    points_height = ft_split(line, ' ');
    if (!points_height)
    {
        ft_printf("Error splitting line: %s\n", line);
        return;
    }
    j = 0;
    while (j < var->map.map_width && points_height[j])
    {
        var->map.map_points[i][j].x = j;
        var->map.map_points[i][j].y = i;
        var->map.map_points[i][j].z = ft_atoi(points_height[j]);
        set_color(var, points_height[j], i, j);
        j++;
    }
	j = 0;
    while (points_height[j])
	{
        free(points_height[j]);
		j++;
	}
    free(points_height);
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
        get_points(var, line, i);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    close(fd);
}
