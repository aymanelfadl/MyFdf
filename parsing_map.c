#include "fdf.h"

void	allocate_points(t_vars *var)
{
	t_point **points;
	int i;

	i = 0;
	points = malloc((sizeof(t_point *) * var->map.map_height) + 1);
	if (!points)
		return ;
	while (i < var->map.map_height)
	{
		points[i] = malloc((sizeof(t_point) * var->map.map_width) + 1);
		if (!points[i])
		{
			while (i >= 0)
				free(points[i--]);
			return ;
		}
		i++;
	}
	var->map.map_points = points;
}

void map_dimension(t_vars *var)
{
	int height;
	int max;
	char *line;
	int fd;

    fd = open(var->map.map_name, O_RDONLY);
    if (fd < 0)
        perror("Err In map_dimension_func:");
    var->map.map_height = 0;
	var->map.map_width = 0;
    line = get_next_line(fd);
	while (line)
	{
		if (valide_line(line))
		{
			max = (int)count_points(line, ' ');
			if (var->map.map_width < max)
				var->map.map_width = max;
	        var->map.map_height++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	add_points(t_vars *var, char *line)	
{
	static	int	i; 
	static int j;
	char **points;


	points = ft_split(line, ' ');
	if (!points)
		return ;
	while (j < var->map.map_width && points[j])
	{
		var->map.map_points[i][j].x = i;
		var->map.map_points[i][j].y = j;
		var->map.map_points[i][j].z = ft_atoi(points[j]);
		var->map.map_points[i][j].color = DEFAULT_COLOR;
		j++;
	}
	i++;
}

void add_points_with_color(t_vars *var, char *line)
{

	static	int	i; 
	static int j;
	char **points;
	char **colors;

	points = ft_split(line, ' ');
	if (!points)
		return ;
	while (j < var->map.map_width && points[j])
	{
		colors = ft_split(points[i], ',');
		if (!colors)
			return ;
		var->map.map_points[i][j].x = i;
		var->map.map_points[i][j].y = j;
		var->map.map_points[i][j].z = ft_atoi(colors[0]);
		if (colors[0])
			var->map.map_points[i][j].color = colors[0][1];
		else
			var->map.map_points[i][j].color = DEFAULT_COLOR;
		j++;
	}
	i++;
}

void	set_points(t_vars *var)
{
	int fd;
	char *line;
	
	allocate_points(var);
    fd = open(var->map.map_name, O_RDONLY);
    if (fd < 0)
        perror("Err In set_points_func");
	line = get_next_line(fd);
	while (line)
	{
		// if (valide_line(line) == 1)
			add_points(var,line);
		// else if (valide_line(line) == 2)
		// 	add_points_with_color(var, line);
		free(line);
    	line = get_next_line(fd);
	}
	close(fd);
}
