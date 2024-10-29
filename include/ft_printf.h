/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:37:31 by mgendrot          #+#    #+#             */
/*   Updated: 2024/10/29 12:21:49 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

# ifndef FD
#  define FD 1
# endif 

void	ft_putnbr_base_fd(int nbr, char *base, int fd);
int		ft_printptr_fd(void *ptr, int fd);
int		ft_puthex_fd(unsigned long num, int fd);

#endif