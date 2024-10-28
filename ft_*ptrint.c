/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_*ptrint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:23:57 by mgendrot          #+#    #+#             */
/*   Updated: 2024/10/28 17:09:54 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pintpoi_fd(void *ptr, int fd)
{
	unsigned long	address;

	address = (unsigned long)ptr;
	write(fd, "0x", 2);
	ft_puthex_fd(address, fd);
}
