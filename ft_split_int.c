/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:49:15 by agraille          #+#    #+#             */
/*   Updated: 2024/12/08 22:54:35 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi(const char *nptr)
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
		if (result * 10 / 10 != result)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		nptr++;
	}
	return (result * sign);
}

int	*ft_split_int(char const *s, char c)
{
	int		word;
	int		i;
	int		j;
	int		*split;

	i = -1;
	word = 1;
	j = 0;
	split = malloc(sizeof(char *) * (ft_count_word(s, c)));
	if (!split)
		return (NULL);
	while (s[++i])
	{
		if (word == 1 && s[i] != c)
		{
			split[j++] = ft_copy(i, s, c);
			if (split[j - 1] == NULL)
				return (ft_free_split(split));
			word = 0;
		}
		else if (word == 0 && s[i] == c)
			word = 1;
	}
	split[j] = NULL;
	return (split);
}
