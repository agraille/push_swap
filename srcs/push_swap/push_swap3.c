/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:18:10 by agraille          #+#    #+#             */
/*   Updated: 2025/02/14 08:03:53 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack *a)
{
	if (a->data[0] < a->data[1] && a->data[1] < a->data[2])
	{
		ra_rb(a, 'a');
		sa_sb(a, 'a');
	}
	else if (a->data[0] < a->data[2] && a->data[2] < a->data[1])
		rra_rrb(a, 'a');
	else if (a->data[1] < a->data[0] && a->data[0] < a->data[2])
		ra_rb(a, 'a');
	else if (a->data[1] < a->data[2] && a->data[2] < a->data[0])
		sa_sb(a, 'a');
	else if (a->data[2] < a->data[0] && a->data[0] < a->data[1])
	{
		rra_rrb(a, 'a');
		sa_sb(a, 'a');
	}
}

static void	a_max_min(t_stack *a)
{
	int	i;

	i = 0;
	while (i <= a->top)
	{
		if (a->data[i] < a->a_min)
			a->a_min = a->data[i];
		if (a->data[i] > a->a_max)
			a->a_max = a->data[i];
		i++;
	}
}

static void	close_five(t_stack *a)
{
	int	i;

	a_max_min(a);
	i = 0;
	while (a->data[i] != a->a_min)
		i++;
	if (i >= a->top / 2)
	{
		while (a->data[a->top] != a->a_min)
			ra_rb(a, 'a');
	}
	else
	{
		while (a->data[a->top] != a->a_min)
			rra_rrb(a, 'a');
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
	sort_three(a);
	while (b->top != -1)
	{
		a_max_min(a);
		if (b->data[b->top] < a->data[a->top] && b->data[b->top] > a->data[0])
			pa(a, b);
		else if (b->data[b->top] > a->a_max && a->data[a->top] == a->a_min)
			pa(a, b);
		else if (b->data[b->top] < a->a_min && a->data[a->top] == a->a_min)
			pa(a, b);
		else
			ra_rb(a, 'a');
	}
	close_five(a);
}

void	start_swap(t_stack *a, t_stack *b)
{
	int	i;

	pb(a, b);
	pb(a, b);
	i = 0;
	while (a->top != -1)
		push_min_cost(a, b, i);
	while (b->data[i] != b->b_min)
		i++;
	if (i >= b->top / 2)
		while (b->data[0] != b->b_min)
			ra_rb(b, 'b');
	else
		while (b->data[0] != b->b_min)
			rra_rrb(b, 'b');
	while (b->top != -1)
		pa(a, b);
}
