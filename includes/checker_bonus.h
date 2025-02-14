/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:16:57 by agraille          #+#    #+#             */
/*   Updated: 2024/12/16 09:33:31 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_gnl
{
	char			content[BUFFER_SIZE + 1];
	struct s_gnl	*next;
}	t_chain;

typedef struct s_stack
{
	int	*data;
	int	top;
}	t_stack;

typedef struct s_result
{
	int	value;
	int	error;
	int	k;
}	t_result;

t_stack		*ft_init_stack(int capacity);
void		sa_sb(t_stack *cur);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra_rb(t_stack *cur);
void		rr(t_stack *a, t_stack *b);
void		rra_rrb(t_stack *cur);
void		rrr(t_stack *a, t_stack *b);
int			*ft_splitoi(char const **argv, char c, int capacity);
int			is_sorted(t_stack *a);
void		ft_free(t_stack *a, t_stack *b, int *tmp);
int			check_double(t_stack *a, t_stack *b, int *temp);
char		*ft_strchr(char *s, int c);
void		ft_free_chain(t_chain **buffer);
ssize_t		ft_strlen(char *s);
char		*ft_copy(char *line, size_t len, t_chain **buffer, size_t j);
ssize_t		ft_read_and_stock(int fd, t_chain **buffer);
t_chain		*ft_add_node(t_chain **buffer);
void		*ft_memmove(void *dest, const void *src, size_t n);
char		*get_next_line(int fd);
int			ft_strncmp(char *s1, char *s2, size_t n);
void		run_gnl(t_stack *a, t_stack *b);

#endif
