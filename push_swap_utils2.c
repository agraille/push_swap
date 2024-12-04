/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:42:09 by agraille          #+#    #+#             */
/*   Updated: 2024/12/04 19:11:49 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb(t_stack *cur, char c)
{
	int	tmp;
	int	i;
	
	if (cur->top < 1)
		return ; 
	i = cur->top;
	tmp = cur->data[cur->top];
	while (i >= 0)
	{
		cur->data[i] = cur->data[i - 1];
		i--;
	}
	cur->data[i + 1] = tmp;
	if (c == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}
