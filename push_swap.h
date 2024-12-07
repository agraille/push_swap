/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:05:59 by agraille          #+#    #+#             */
/*   Updated: 2024/12/07 22:03:26 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*data;
	int	top;
	int	capacity;
}	t_stack;

t_stack		*ft_init_stack(int capacity);
void		sa_sb(t_stack *cur, char a);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra_rb(t_stack *cur, char c);
void		rr(t_stack *a, t_stack *b);
void		rra_rrb(t_stack *cur, char c);
void		rrr(t_stack *a, t_stack *b);
void		push_swap(t_stack *a, t_stack *b);
#endif
