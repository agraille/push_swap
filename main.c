/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 08:25:32 by agraille          #+#    #+#             */
/*   Updated: 2024/12/04 13:24:03 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_atoi(const char *nptr)
{
	unsigned long long int	result;
	int						sign;

	sign = 1;
	result = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		if (result * 10 / 10 != result)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		nptr++;
	}
	return (result * sign);
}

int	main(int argc, char const **argv)
{
	if (argc == 1)
		return (0);
	//check si valide
	//atoi pour convert en entier et envoyer dans data 
	//check si deja trié
	//envoyer le nombre darg pour la size de capacity
	return (0);
}

