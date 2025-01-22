
#include "fdf.h"

static  int  ft_isclean_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == ' ' || base[i] == '\r' || base[i] == '\n'
			|| base[i] == '\f' || base[i] == '\v' || base[i] == '\t'
			|| base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_getindex(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

static void	ft_skip(int *i, int *sin, char *str)
{
	while (str[*i] == ' ' || str[*i] == '\r' || str[*i] == '\n'
		|| str[*i] == '\f' || str[*i] == '\v' || str[*i] == '\t')
		(*i)++;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			(*sin)++;
		(*i)++;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int			len;
	long int	res;
	int			i;
	int			sin;

	i = 0;
	res = 0;
	sin = 1;
	if (ft_isclean_base(base) == 1)
	{
		len = ft_strlen(base);
		if (len >= 2)
		{
			ft_skip(&i, &sin, str);
			while (ft_getindex(str[i], base) != -1)
			{
				res = res * len + ft_getindex(str[i], base);
				i++;
			}
		}
	}
	if (sin % 2 == 0)
		return (-res);
	return (res);
}

int to_number(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (ft_isspace(str[i]) || ft_isdigit(str[i]))
			i++;
		else
		{
			ft_printf("Not A valid Map.");
			exit(EXIT_FAILURE);
		}
	}
	return (ft_atoi(str));
}