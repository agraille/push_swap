/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:49:15 by agraille          #+#    #+#             */
/*   Updated: 2024/12/09 00:11:14 by agraille         ###   ########.fr       */
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
		exit(EXIT_FAILURE);// voir pour gerer la sortie proprement
	i = 0;
	while (start < end)
		tmp[i++] = s[start++];
	tmp[i] = '\0';
	value = ft_atoi(tmp);
	free(tmp);
	return (value);
}

int	*ft_split_int(char const **argv, char c, int capacity)
{
	int		word;
	int		i;
	int		j;
	int		k;
	int		*split;

	j = 0;
	k = 0;
	split = malloc(sizeof(int) * capacity);
	if (!split)
		return (NULL);
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
