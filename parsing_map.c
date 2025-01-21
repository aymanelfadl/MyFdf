#include "fdf.h"

static size_t	count_points(char *s, char c)
{
	size_t	nwords;

	nwords = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			nwords++;
			while (*s && *s != c)
				s++;
		}
	}
	return (nwords);
}

void	get_points(t_vars *var)
{
	t_point **points;
	int i;

	i = 0;
	points = malloc((sizeof(t_point *) * var->map.map_height) + 1);
	if (!points)
		return ;
	while (i < var->map.map_height)
	{
		points[i] = malloc(sizeof(t_point) + 1);
		if (!points[i])
		{
			while (i >= 0)
				free(points[i--]);
			return ;
		}
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
        perror("err");
    var->map.map_height = 0;
	var->map.map_width = 0;
    while ((line = get_next_line(fd)) != NULL)
	{
		max = (int)count_points(line, ' ');
		if (var->map.map_width < max)
			var->map.map_width = max;
        var->map.map_height++;
		free(line);
	}
	get_points(var);

}

