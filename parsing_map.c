#include "fdf.h"


// void ft_free(t_vars *vars)
// {

// 	if (&vars->map && vars->map.map_points)
// 		free
// }


void	allocate_points(t_vars *var)
{
	int i;

	i = 0;
	var->map.map_points = malloc(sizeof(t_point *) * var->map.map_height);
	if (!var->map.map_points)
	{
		perror("Error allocating map points");
		exit(EXIT_FAILURE);
	}
	while (i < var->map.map_height)
	{
		var->map.map_points[i] = malloc(sizeof(t_point) * var->map.map_width);
		if (!var->map.map_points[i])
		{
			while (--i >= 0)
				free(var->map.map_points[i]);
			free(var->map.map_points);
			perror("Error allocating map row");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	map_dimension(t_vars *var)
{
	char	*line;
	int		fd;
	int		max_width;

	fd = open(var->map.map_name, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file in map_dimension");
		exit(EXIT_FAILURE);
	}

	var->map.map_height = 0;
	var->map.map_width = 0;

	line = get_next_line(fd);
	while (line)
	{
		if (line[0] && valide_line(line))
		{
			max_width = count_points(line, ' ');
			if (max_width > var->map.map_width)
				var->map.map_width = max_width; 
			var->map.map_height++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	add_points(t_vars *var, char *line, int i)
{
	int		j;
	char	**points;

	j = 0;
	points = my_split(line, ' ');
	if (!points)
		return ;
	while (points[j] && j < var->map.map_width)
	{
		var->map.map_points[i][j].x = i;
		var->map.map_points[i][j].y = j;
		var->map.map_points[i][j].z = to_number(points[j]);
		var->map.map_points[i][j].color = DEFAULT_COLOR;
		free(points[j]);
		j++;
	}
	free(points);
}

void	set_points(t_vars *var)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	allocate_points(var); 

	fd = open(var->map.map_name, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file in set_points");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		if (valide_line(line))
		{
			add_points(var, line, i);
			i++;
		}
		free(line);
		line = get_next_line(fd);
		ft_printf("line::%s",line);
	}
	close(fd);
}
