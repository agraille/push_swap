/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:48:06 by agraille          #+#    #+#             */
/*   Updated: 2025/02/14 08:03:07 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

static int	check_line_bis(char *line)
{
	write(2, "Error\n", 6);
	free(line);
	return (0);
}

static int	check_line(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "sa", 2) == 0)
		sa_sb(a);
	else if (ft_strncmp(line, "rra", 3) == 0)
		rra_rrb(a);
	else if (ft_strncmp(line, "rrb", 3) == 0)
		rra_rrb(b);
	else if (ft_strncmp(line, "rrr", 3) == 0)
		rrr(a, b);
	else if (ft_strncmp(line, "sb", 2) == 0)
		sa_sb(b);
	else if (ft_strncmp(line, "ss", 2) == 0)
		ss(a, b);
	else if (ft_strncmp(line, "pa", 2) == 0)
		pa(a, b);
	else if (ft_strncmp(line, "pb", 2) == 0)
		pb(a, b);
	else if (ft_strncmp(line, "ra", 2) == 0)
		ra_rb(a);
	else if (ft_strncmp(line, "rb", 2) == 0)
		ra_rb(b);
	else if (ft_strncmp(line, "rr", 2) == 0)
		rr(a, b);
	else
		return (check_line_bis(line), 0);
	return (1);
}

void	run_gnl(t_stack *a, t_stack *b)
{
	char	*line;

	if (is_sorted(a))
	{	
		write(1, "OK\n", 3);
		return ;
	}
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (!check_line(line, a, b))
		{
			get_next_line(0);
			return ;
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	if (is_sorted(a) && b->top == -1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return ;
}
