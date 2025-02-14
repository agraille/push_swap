/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:19:54 by agraille          #+#    #+#             */
/*   Updated: 2025/02/14 08:03:59 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	cal_cost_a(t_stack *a, int i)
{
	int	cost;

	if (i >= a->top / 2)
	{
		cost = a->top - i;
	}
	else
	{
		cost = -(i + 1);
	}
	return (cost);
}

static void	rotate(t_stack *stack, int cost, char stack_id)
{
	while (cost > 0)
	{
		ra_rb(stack, stack_id);
		cost--;
	}
	while (cost < 0)
	{
		rra_rrb(stack, stack_id);
		cost++;
	}
}

static void	time_to_move(t_stack *a, t_stack *b, int best_index)
{
	int	cost_a;
	int	cost_b;

	cost_a = cal_cost_a(a, best_index);
	cost_b = cal_cost_b(b, a->data[best_index]);
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b);
		cost_a++;
		cost_b++;
	}
	rotate(a, cost_a, 'a');
	rotate(b, cost_b, 'b');
	pb(a, b);
}

void	push_min_cost(t_stack *a, t_stack *b, int i)
{
	int	min_cost;
	int	best_index;
	int	cost_a;
	int	cost_b;
	int	total_cost;

	i = a->top;
	best_index = 0;
	min_cost = INT_MAX;
	while (i >= 0)
	{
		cost_a = cal_cost_a(a, i);
		cost_b = cal_cost_b(b, a->data[i]);
		total_cost = ft_abs(cost_a, cost_b);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			best_index = i;
		}
		i--;
	}
	time_to_move(a, b, best_index);
}

void	push_swap(t_stack *a, t_stack *b, int *temp)
{
	if (!check_double(a))
	{
		ft_free(a, b, temp);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (is_sorted(a))
		return ;
	if (a->top == 2)
	{
		sort_three(a);
		return ;
	}
	if (a->top == 4)
	{
		sort_five(a, b);
		return ;
	}
	start_swap(a, b);
}
