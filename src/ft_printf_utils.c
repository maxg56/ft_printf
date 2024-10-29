/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:35:46 by mgendrot          #+#    #+#             */
/*   Updated: 2024/10/29 16:46:11 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", FD);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_printstr(num);
	free(num);
	return (len);
}

int	ft_printpercent_fd(int fd)
{
	write(fd, "%", 1);
	return (1);
}

int	ft_printptr_fd(void *ptr, int fd)
{
	unsigned long	address;
	int				len;

	address = (unsigned long)ptr;
	len = 2;
	write(fd, "0x", 2);
	len += ft_puthex_fd(address, 'x', fd);
	return (len);
}

int	ft_puthex_fd(unsigned long num, int format, int fd)
{
	const char	*hex_chars = "0123456789abcdef";
	int			count ;

	if (format == 'X')
		hex_chars = "0123456789ABCDEF";
	count = 0;
	if (num >= 16)
		count += ft_puthex_fd(num / 16, fd);
	count += write(fd, &hex_chars[num % 16], 1);
	return (count);
}
