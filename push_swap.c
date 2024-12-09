/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:19:54 by agraille          #+#    #+#             */
/*   Updated: 2024/12/09 12:41:17 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pivot(t_stack *stack)
{
	int	*sorted;
	int	pivot;
	int	i;
	int	j;
	int	tmp;

	sorted = malloc(sizeof(int) * (stack->top + 1));
	if (!sorted)
		return (0);
	i = -1;
	while (++i <= stack->top)
		sorted[i] = stack->data[i];
	i = 0;
	while (i <= stack->top)
	{
		j = 0;
		while (j < stack->top - i)
		{
			if (sorted[j] > sorted[j + 1])
			{
				tmp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	pivot = sorted[stack->top / 2];
	free(sorted);
	return (pivot);
}


int	is_sorted(t_stack *stack)
{
	for (int i = stack->top; i > 0; i--)
	{
		if (stack->data[i] > stack->data[i - 1])
			return (0);
	}
	return (1);
}

void	push_swap(t_stack *a, t_stack *b)
{
	int	pivot;

	pivot = find_pivot(a);
	// while (!is_sorted(a))
	int i = 5000;
	while (i--)
	{
		if (a->data[a->top] <= pivot)
			pb(a, b);
		if (a->data[a->top] > a->data[a->top - 1])
		{
			sa_sb(a, 'a');
			rra_rrb(a, 'a');
		}
		else
			rra_rrb(a, 'a');
		while (b->data[b->top] < b->data[b->top -1])
		{
			if ((b->data[b->top] < b->data[0]))
				ra_rb(b, 'b');
			else
				sa_sb(b, 'b');
		}
	}
	while (b->top != -1)
		pa(a, b);
}

