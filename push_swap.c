/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:19:54 by agraille          #+#    #+#             */
/*   Updated: 2024/12/07 08:08:59 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	while (!is_sorted(a))
	{
		if (a->data[a->top] > pivot)
			pb(a, b);
		else
			ra_rb(a, 'a');
	}
	while (b->top != -1)
		pa(a, b);
}

