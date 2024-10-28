/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:01:20 by mgendrot          #+#    #+#             */
/*   Updated: 2024/10/28 16:18:19 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
		z = i + 1;
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

int	sin_nbr(int nbr, char *base, int fd)
{
	if (nbr == 0)
	{
		ft_putchar_fd(base[0], fd);
		return (0);
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar_fd('-', fd);
		return (nbr);
	}
	return (nbr);
}

void	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	int	size_base;
	int	nbr_final[100];
	int	i;

	i = 0;
	size_base = 0;
	if (check_base(base))
	{
		nbr = sin_nbr(nbr, base, fd);
		if (nbr == 0)
			return (0);
		while (base[size_base])
			size_base++;
		while (nbr)
		{
			nbr_final[i] = nbr % size_base;
			nbr = nbr / size_base;
			i++;
		}
		while (--i >= 0)
			ft_putchar_fd(base[nbr_final[i]], fd);
	}
}
