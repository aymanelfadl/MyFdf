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
	while (line != NULL)
	{
		if (!valid_line(line))
			ft_gnl_err(fd, line, "Err: Not a Valid Map.");
		max_width = count_points(line, ' ');
		if (max_width > var->map.map_width)
			var->map.map_width = max_width; 
		var->map.map_height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
