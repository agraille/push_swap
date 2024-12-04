/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:25:32 by agraille          #+#    #+#             */
/*   Updated: 2024/12/04 17:44:33 by agraille         ###   ########.fr       */
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

int	main(int argc, char const **argv)
{
	t_stack	*pile_a;
	t_stack	*pile_b;

	if (argc == 1)
		return (0);
	pile_a = ft_init_stack(argc - 1);
	pile_b = ft_init_stack(argc - 1);
	while (argc != 1)
	{
		pile_a->data[++pile_a->top] = ft_atoi(argv[argc - 1]);
		pile_b->data[++pile_b->top] = ft_atoi(argv[argc - 1]);
		argc --;
	}
	//check si valide et les doubles
	//check si deja trié
	int i = pile_a->top;
	// while (i >= 0)
	// {
	// 	printf("%d\n",pile_a->data[i]);
	// 	i--;
	// }
	// printf("_\n");
	// printf("a\n");
	ss(pile_a, pile_b);
	i = pile_a->top;
	while (i >= 0)
	{
		printf("PILE A = %d\n",pile_a->data[i]);
		printf("PILE B = %d\n",pile_b->data[i]);
		i--;
	}
	free(pile_a->data);
	free(pile_a);
	free(pile_b->data);
	free(pile_b);
	return (0);
}

