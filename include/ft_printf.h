/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:37:31 by mgendrot          #+#    #+#             */
/*   Updated: 2024/10/30 14:04:11 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include "libft.h"

# ifndef FD
#  define FD 1
# endif 

# ifdef NULL_STR
#  define NULL_STR "(null)"
# endif

int	ft_print_c_fd(char c, int fd);
int	ft_print_d_fd(int n, int fd);
int	ft_print_p_fd(uintptr_t ptr, int fd);
int	ft_print_pct_fd(int fd);
int	ft_print_s_fd(char *s, int fd);
int	ft_print_u_fd(unsigned int n, int fd);
int	ft_print_x_fd(unsigned int n, int format, int fd);

int	ft_printf(const char *str, ...);


#endif


