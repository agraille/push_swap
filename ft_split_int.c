/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:49:15 by agraille          #+#    #+#             */
/*   Updated: 2024/12/12 15:05:21 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	char	*tmp;
	int		i;
	int		end;
	int		value;

	end = start;
	while (s[end] && s[end] != c)
		end++;
	tmp = malloc(sizeof(char) * (end - start + 1));
	if (!tmp)
		return (-1);
	i = 0;
	while (start < end)
		tmp[i++] = s[start++];
	tmp[i] = '\0';
	value = ft_atoi(tmp);
	free(tmp);
	return (value);
}

static int	*ft_split_init(int k, int *split, char const **argv, char c)
{
	int	word;
	int	i;
	int	j;

	j = 0;
	while (argv[k])
	{
		i = 0;
		word = 1;
		while (argv[k][i])
		{
			if (word == 1 && argv[k][i] != c)
			{
				word = 0;
				split[j++] = ft_copy(i, argv[k], c);
			}
			else if (word == 0 && argv[k][i] == c)
				word = 1;
			i++;
		}
		k++;
	}
	return (split);
}

int	*ft_splitoi(char const **argv, char c, int capacity)
{
	int		k;
	int		*split;

	k = 0;
	split = malloc(sizeof(int) * capacity);
	if (!split)
		return (NULL);
	split = ft_split_init(k, split, argv, c);
	return (split);
}
