/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:36:08 by agraille          #+#    #+#             */
/*   Updated: 2025/02/14 08:03:56 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	cal_cost_bis(t_stack *b, int value_a, int i)
{
	while (i >= 0)
	{
		if (i == b->top && value_a > b->data[i] && value_a < b->data[0])
			break ;
		if (i < b->top && value_a > b->data[i] && value_a < b->data[i + 1])
			break ;
		if (i == b->top && value_a < b->data[i] && value_a > b->data[0])
		{
			i--;
			continue ;
		}
		if (i < b->top && value_a < b->data[i] && value_a > b->data[i + 1]
			&& b->data[i + 1] != b->b_min)
			break ;
		i--;
	}
	return (i);
}

int	cal_cost_b(t_stack *b, int value_a)
{
	int	cost;
	int	i;

	i = b->top;
	if (value_a > b->b_max || value_a < b->b_min)
	{
		while (i >= 0 && b->data[i] != b->b_max)
			i--;
	}
	else
		i = cal_cost_bis(b, value_a, i);
	if (i >= b->top / 2)
	{
		cost = b->top - i;
	}
	else
	{
		cost = -(i + 1);
	}
	return (cost);
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->data[i] < a->data[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_double(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->top)
	{
		j = i + 1;
		while (j <= a->top)
		{
			if (a->data[i] == a->data[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_free(t_stack *a, t_stack *b, int *tmp)
{
	free(tmp);
	free(a->data);
	free(b->data);
	free(a);
	free(b);
}
