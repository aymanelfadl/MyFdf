#include "../fdf.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	valid_line(char *line)
{
	char	*n_line;
	int		i;

	n_line = line;
	n_line = ft_strchr(n_line, '\n');
	if (n_line)
		*n_line = '\0';
	i = 0;
	while (line[i])
	{
		while (ft_isspace(line[i]))
			i++;
		if (ft_isdigit(line[i]) || ft_strchr("xabcdef,XABCDEF", line[i]))
		{
			i++;
			continue;
		}
		ft_printf("Err: Not a Valid Map");
		free(line);
		exit(EXIT_FAILURE);	
	}
	if (!line[0])
	{
		return 0;
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