/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:15:01 by agraille          #+#    #+#             */
/*   Updated: 2025/02/14 08:03:20 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

t_stack	*ft_init_stack(int capacity)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->top = -1;
	new->data = malloc(sizeof(int) * capacity);
	if (!new->data)
		return (free(new), NULL);
	return (new);
}

void	sa_sb(t_stack *cur)
{
	int	tmp;
	int	i;

	if (cur->top == -1 || cur->top < 1)
		return ;
	i = cur->top;
	tmp = cur->data[cur->top];
	cur->data[i] = cur->data[i - 1];
	cur->data[i - 1] = tmp;
}

void	ss(t_stack *a, t_stack *b)
{
	int	tmp;
	int	i;

	if (a->top == -1 || a->top < 1 || b->top == -1 || b->top < 1)
		return ;
	i = a->top;
	tmp = a->data[a->top];
	a->data[i] = a->data[i - 1];
	a->data[i - 1] = tmp;
	i = b->top;
	tmp = b->data[b->top];
	b->data[i] = b->data[i - 1];
	b->data[i - 1] = tmp;
	return ;
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->top == -1)
		return ;
	a->data[++a->top] = b->data[b->top];
	b->top--;
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->top == -1)
		return ;
	b->data[++b->top] = a->data[a->top];
	a->top--;
}
