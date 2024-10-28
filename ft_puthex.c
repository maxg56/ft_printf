/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:03:45 by mgendrot          #+#    #+#             */
/*   Updated: 2024/10/28 17:07:43 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_fd(unsigned long num, int fd)
{
	const char	*hex_chars = "0123456789abcdef";

	if (num >= 16)
		ft_puthex(num / 16);
	ft_putchar_fd(hex_chars[num % 16], fd);
}
