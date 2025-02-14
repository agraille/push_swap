/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils3_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:33:40 by agraille          #+#    #+#             */
/*   Updated: 2025/02/14 08:03:23 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

void	ra_rb(t_stack *cur)
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
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->top < 1 || b->top < 1)
		return ;
	ra_rb(a);
	ra_rb(b);
}

void	rra_rrb(t_stack *cur)
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
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->top < 1 || b->top < 1)
		return ;
	rra_rrb(a);
	rra_rrb(b);
}
