#include "../fdf.h"

void	ft_gnl_err(int fd, char *line, char *str)
{
	free(line);
	line = get_next_line(fd);
	while(line)
	{
		free(line);
		line = get_next_line(fd);
	}
	ft_printf(str);
	exit(EXIT_FAILURE);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int valid_line(char *line)
{
    char *n_line;
    int i;

    n_line = ft_strchr(line, '\n');
    if (n_line)
        *n_line = '\0';
    i = 0;
    while (line[i])
    {
        while (ft_isspace(line[i]) || line[i] == '-')
            i++;
        if (!line[i])
            break;
        if (!ft_isdigit(line[i]) && line[i] != ',' && !ft_strchr("xabcdefABCDEF", line[i]))
            return (0);
        i++;
    }
    return (1);
}

int		count_points(char *s, char c)
{
	size_t	nwords;

	nwords = 0;
	while (*s)
	{
		while (*s == c) 
			s++;
		if (*s)
		{
			nwords++;
			while (*s && *s != c)
				s++;
		}
	}
	return (nwords);
}
int	interpolate_color(int color1, int color2, float fraction)
{
	int	red;
	int	green;
	int	blue;

	red = ((1 - fraction) * ((color1 >> 16) & 0xFF)) + (fraction
			* ((color2 >> 16) & 0xFF));
	green = ((1 - fraction) * ((color1 >> 8) & 0xFF)) + (fraction
			* ((color2 >> 8) & 0xFF));
	blue = ((1 - fraction) * (color1 & 0xFF)) + (fraction * (color2 & 0xFF));
	return ((red << 16) | (green << 8) | blue);
}

void	set_color(t_vars *var, int x, int y, char *colors)
{
	char	**color;
	
	color = ft_split((const char *)colors, ',');
	if (color[1])
	{
		var->map.map_points[x][y].color = ft_atoi_base(color[1] + 2, 16);
		free(color[1]);
	}
	else
	{
		if (ft_atoi(color[0]) <= -20)
			var->map.map_points[x][y].color = 0x001B44; // Deep Blue 
		else if (ft_atoi(color[0]) <= 0)
			var->map.map_points[x][y].color = 0x0088CC; // Cyan Blue 
		else if (ft_atoi(color[0]) <= 20)
			var->map.map_points[x][y].color = 0x22AA22; // Green 
		else if (ft_atoi(color[0]) <= 50)
			var->map.map_points[x][y].color = 0xFFD700; // Yellow
		else if (ft_atoi(color[0]) <= 100)
			var->map.map_points[x][y].color = 0x8B4513; // Brown
		else
			var->map.map_points[x][y].color = 0xFFFFFF; // White
	}
	free(color[0]);
	free(color);
}
