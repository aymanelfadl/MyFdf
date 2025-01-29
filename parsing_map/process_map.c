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