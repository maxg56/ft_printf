/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:07:12 by mgendrot          #+#    #+#             */
/*   Updated: 2024/10/30 14:02:21 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_d_fd(int n, int fd)
{
	long	ln;

	ln = n;
	if (ln < 0)
		return (write(fd, "-", 1) + ft_print_d(-ln, fd));
	if (ln >= 10)
		return (ft_print_d(ln / 10, fd) + ft_print_d(ln % 10, fd));
	return (ft_print_c(ln + '0', fd));
}
