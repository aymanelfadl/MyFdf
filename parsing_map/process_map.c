#include "fdf.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

char	*valid_line(char *line)
{
	char	*null_position;
	int		i;

	null_position = ft_strchr(line, '\n');
	*null_position = '\0';

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
		perror("Err: Not a Valid Map");
	}
	return (line);
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