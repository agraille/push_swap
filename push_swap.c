/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:19:54 by agraille          #+#    #+#             */
/*   Updated: 2024/12/11 18:04:23 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int is_sorted(t_stack *a)
{
    int i;

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

int	cal_cost_a(t_stack *a, int i)
{
    int	cost;

    if (i >= a->top / 2)
    {
        cost = a->top - i;
    }
    else
    {
        cost = -(a->top - i + 1);
    }
    return (cost);
}

int cal_cost_b(t_stack *b, int value_a)
{
    int	cost;
    int	i;

	i = b->top;
    if (value_a > b->b_max)
    {
	   while (i >= 0 && b->data[i] != b->b_max)
            i--;
    }
	else if (value_a < b->b_min)
	{
		 while (i >=0 && b->data[i] != b->b_max)
            i--;
	}
	else 
	{
		
		while (i >= 0)
        {
            if (i == b->top && value_a > b->data[i] && value_a < b->data[0])
				break ;
			if (value_a > b->data[i] && value_a < b->data[i + 1])
				break ;
			i--;
		}
	}
    if (i >= b->top / 2)
    {
        cost = b->top - i;
    }
    else
    {
        cost = -(b->top - i + 1);
    }
    return (cost);
}

void rotate(t_stack *stack, int *cost, char stack_id)
{
    while (*cost > 0)
    {
        ra_rb(stack, stack_id);
        (*cost)--;
    }
    while (*cost > 0)
    {
        rra_rrb(stack, stack_id);
        (*cost)++;
    }
}

void time_to_move(t_stack *a, t_stack *b, int best_index)
{
    int cost_a;
    int cost_b;
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
    rotate(a, &cost_a, 'a');
    rotate(b, &cost_b, 'b');
    pb(a, b);
}

void push_min_cost(t_stack *a, t_stack *b)
{
    int i;
    int min_cost;
    int best_index = 0;
    int cost_a, cost_b, total_cost;
	
	i = a->top;
	min_cost = INT_MAX;
    while (i >= 0)
    {
        cost_a = cal_cost_a(a, i);
        cost_b = cal_cost_b(b, a->data[i]);
        total_cost = ft_abs(cost_a) + ft_abs(cost_b);
        if (total_cost < min_cost)
        {
            min_cost = total_cost;
            best_index = i;
        }
		i--;
    }
    time_to_move(a, b, best_index);
}

void push_swap(t_stack *a, t_stack *b)
{
    if (is_sorted(a))
        return;
    pb(a, b);
    pb(a, b);
    while (a->top != -1)
    {
        push_min_cost(a, b);
    }
	int i = 0;
	while (b->data[i] != b->b_min)
			ra_rb(b, 'b');
    while (b->top != -1)
    {
	
        pa(a, b);
    }
}
