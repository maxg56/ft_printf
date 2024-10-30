/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:47:35 by mgendrot          #+#    #+#             */
/*   Updated: 2024/10/30 14:07:18 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define NULL_STR "(null)"

int	ft_print_s_fd(char *s, int fd)
{
	if (!s)
		return (write(fd, NULL_STR, ft_strlen(NULL_STR)));
	return (write(fd, s, ft_strlen(s)));
}
