/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:36:19 by agraille          #+#    #+#             */
/*   Updated: 2024/12/12 12:34:16 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_init_stack(int capacity)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->top = -1;
	new->data = malloc(sizeof(int *) * capacity);
	if (!new->data)
		return (free(new), NULL);
	return (new);
}

void	sa_sb(t_stack *cur, char a)
{
	int	tmp;
	int	i;

	if (cur->top == -1 || cur->top < 1)
		return ;
	i = cur->top;
	tmp = cur->data[cur->top];
	cur->data[i] = cur->data[i - 1];
	cur->data[i - 1] = tmp;
	if (a == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
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
	write(1, "ss\n", 3);
	return ;
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->top == -1)
		return ;
	a->data[++a->top] = b->data[b->top];
	b->top--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->top == -1)
		return ;
	b->data[++b->top] = a->data[a->top];
	a->top--;
	if (b->top == 0)
	{
		b->b_min = b->data[b->top];
		b->b_max = b->data[b->top];
	}
	else
	{
		if (b->data[b->top] < b->b_min)
			b->b_min = b->data[b->top];
		if (b->data[b->top] > b->b_max)
			b->b_max = b->data[b->top];
	}
	write(1, "pb\n", 3);
}
