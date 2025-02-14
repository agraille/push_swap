/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:42:09 by agraille          #+#    #+#             */
/*   Updated: 2025/02/14 08:04:01 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra_rb(t_stack *cur, char c)
{
	int	tmp;
	int	i;

	if (cur->top < 1)
		return ;
	i = cur->top;
	tmp = cur->data[cur->top];
	while (i > 0)
	{
		cur->data[i] = cur->data[i - 1];
		i--;
	}
	cur->data[0] = tmp;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->top < 1 || b->top < 1)
		return ;
	ra_rb(a, 0);
	ra_rb(b, 0);
	write(1, "rr\n", 3);
}

void	rra_rrb(t_stack *cur, char c)
{
	int	tmp;
	int	i;

	if (cur->top < 1)
		return ;
	i = 0;
	tmp = cur->data[0];
	while (i < cur->top)
	{
		cur->data[i] = cur->data[i + 1];
		++i;
	}
	cur->data[cur->top] = tmp;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->top < 1 || b->top < 1)
		return ;
	rra_rrb(a, 0);
	rra_rrb(b, 0);
	write(1, "rrr\n", 4);
}

int	ft_abs(int cost_a, int cost_b)
{
	int	result;

	if (cost_a >= 0 && cost_b >= 0)
	{
		if (cost_a > cost_b)
			result = cost_a;
		else
			result = cost_b;
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		if (-cost_a > -cost_b)
			result = -cost_a;
		else
			result = -cost_b;
	}
	else
	{
		if (cost_a < 0)
			cost_a = -cost_a;
		if (cost_b < 0)
			cost_b = -cost_b;
		result = cost_a + cost_b;
	}
	return (result);
}
