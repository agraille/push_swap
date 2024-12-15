/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:05:59 by agraille          #+#    #+#             */
/*   Updated: 2024/12/15 22:35:26 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int	*data;
	int	top;
	int	b_min;
	int	b_max;
	int	a_min;
	int	a_max;
}	t_stack;

typedef struct s_result
{
	int	value;
	int	error;
	int	k;
}	t_result;

t_stack		*ft_init_stack(int capacity);
void		sa_sb(t_stack *cur, char a);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra_rb(t_stack *cur, char c);
void		rr(t_stack *a, t_stack *b);
void		rra_rrb(t_stack *cur, char c);
void		rrr(t_stack *a, t_stack *b);
void		push_swap(t_stack *a, t_stack *b, int *temp);
int			*ft_splitoi(char const **argv, char c, int capacity);
int			ft_abs(int cost_a, int cost_b);
int			is_sorted(t_stack *a);
void		ft_free(t_stack *a, t_stack *b, int *tmp);
int			check_double(t_stack *a);
int			cal_cost_b(t_stack *b, int value_a);
void		sort_five(t_stack *a, t_stack *b);
void		sort_three(t_stack *a);
void		push_min_cost(t_stack *a, t_stack *b, int i);
void		start_swap(t_stack *a, t_stack *b);
#endif
