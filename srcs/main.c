/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:25:32 by agraille          #+#    #+#             */
/*   Updated: 2025/02/14 08:04:28 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_is_int(const char *str)
{
	long	num;
	int		s;

	num = 0;
	s = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	if (*str < '0' || *str > '9')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		if ((*(str + 1) < '0' || *(str + 1) > '9') && *(str + 1) != '\0')
			return (0);
		num = num * 10 + (*str - '0');
		if ((s == 1 && num > INT_MAX) || (s == -1 && num > (long)INT_MAX + 1))
			return (0);
		str++;
	}
	return (1);
}

static int	ft_check_single_arg(const char *arg)
{
	int		i;
	int		count;
	char	*start;

	i = 0;
	count = 0;
	while (arg[i])
	{
		if (arg[i] == ' ')
		{
			i++;
			continue ;
		}
		start = (char *)&arg[i];
		while (arg[i] && arg[i] != ' ')
			i++;
		if (!ft_is_int(start))
			return (0);
		else
			count++;
	}
	return (count);
}

static int	ft_check_args(int argc, char const **argv)
{
	int	i;
	int	count;
	int	is_valid;

	i = 1;
	count = 0;
	is_valid = 0;
	while (i < argc)
	{
		is_valid = ft_check_single_arg(argv[i]);
		if (is_valid == 0)
			return (0);
		count += is_valid;
		i++;
	}
	return (count);
}

static int	init_capacity(const char **argv, int argc)
{
	int	capacity;

	capacity = ft_check_args(argc, argv);
	if (capacity == 0)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return (capacity);
}

int	main(int argc, char const **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		capacity;
	int		*temp;

	if (argc == 1)
		return (-1);
	capacity = init_capacity(argv, argc);
	a = ft_init_stack(capacity);
	if (!a)
		return (-1);
	b = ft_init_stack(capacity);
	if (!b)
		return (free(a), -1);
	temp = ft_splitoi(argv + 1, ' ', capacity);
	if (!temp)
		return (free(a), free(b), -1);
	while (capacity--)
		a->data[++a->top] = temp[capacity];
	push_swap(a, b, temp);
	ft_free(a, b, temp);
	return (0);
}
