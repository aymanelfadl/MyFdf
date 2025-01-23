#include "fdf.h"


void	map_dimension(t_vars *var)
{
	char	*line;
	int		fd;
	int		max_width;

	fd = open(var->map.map_name, O_RDONLY);
	if (fd < 0)
	{
		perror("Err: Can't Open File In Map Dimension.");
		exit(EXIT_FAILURE);
	}
	var->map.map_height = 0;
	var->map.map_width = 0;
	line = get_next_line(fd);
	while (line);
	{
		if (valid_line(line))
		{
			max_width = count_points(line, ' ');
			if (max_width > var->map.map_width)
				var->map.map_width = max_width; 
			var->map.map_height++;
		}
		free(line);
		get_next_line(line);
	}
}
