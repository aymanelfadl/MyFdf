#include "fdf.h"

size_t	count_points(char *s, char c)
{
	size_t	nwords;

	nwords = 0;
	while (*s && *s != '\n')
	{
		while (ft_isspace(*s))
			s++;
        if (*s && *s != '\n')
        {
            nwords++;
            while (*s && !ft_isspace(*s) && *s != '\n')
                s++;
        }
	}
	return (nwords);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int valide_line(char *str)
{
	int i = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		if (ft_isdigit(str[i]) || *ft_strchr("xabcdef,XABCDEF", str[i]))
		{
			i++;
			break ;
		}
		return (0);
	}
	return (1);
}