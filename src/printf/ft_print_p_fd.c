/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:28:04 by mgendrot          #+#    #+#             */
/*   Updated: 2024/10/30 14:06:32 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_ptr(uintptr_t ptr, int fd)
{
	int		count;

	count = 0;
	if (ptr >= 16)
	{
		count += ft_put_ptr(ptr / 16, fd);
		count += ft_put_ptr(ptr % 16, fd);
	}
	else
		count += ft_print_c("0123456789abcdef"[ptr], fd);
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_print_p_fd(uintptr_t ptr, int fd)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_printf("(nil)"));
	count += ft_print_s("0x");
	if (count < 0)
		return (-1);
	count += ft_put_ptr(ptr, fd);
	if (count < 0)
		return (-1);
	return (count);
}
