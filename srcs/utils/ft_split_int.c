/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:49:15 by agraille          #+#    #+#             */
/*   Updated: 2025/02/14 08:03:44 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_atoi( char *nptr)
{
	unsigned long long int	result;
	int						sign;

	sign = 1;
	result = 0;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

static int	ft_copy(int start, const char *s, char c)
{
	char		*tmp;
	int			i;
	int			end;
	t_result	result;

	end = start;
	while (s[end] && s[end] != c)
		end++;
	tmp = malloc(sizeof(char) * (end - start + 1));
	if (!tmp)
	{
		result.error = 1;
		return (result.error);
	}
	i = 0;
	while (start < end)
		tmp[i++] = s[start++];
	tmp[i] = '\0';
	result.value = ft_atoi(tmp);
	free(tmp);
	return (result.value);
}

static int	*ft_split_init(t_result res, int *split, char const **argv, char c)
{
	int			word;
	int			i;
	int			j;

	j = 0;
	while (argv[res.k])
	{
		i = -1;
		word = 1;
		while (argv[res.k][++i])
		{
			if (word == 1 && argv[res.k][i] != c)
			{
				word = 0;
				split[j++] = ft_copy(i, argv[res.k], c);
				if (res.error)
					return (NULL);
			}
			else if (word == 0 && argv[res.k][i] == c)
				word = 1;
		}
		res.k++;
	}
	return (split);
}

int	*ft_splitoi(char const **argv, char c, int capacity)
{
	int			*split;
	t_result	init;

	init.error = 0;
	init.value = 0;
	init.k = 0;
	split = malloc(sizeof(int) * capacity);
	if (!split)
		return (NULL);
	split = ft_split_init(init, split, argv, c);
	if (!split)
	{
		free(split);
		return (NULL);
	}
	return (split);
}
