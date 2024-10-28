/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:37:31 by mgendrot          #+#    #+#             */
/*   Updated: 2024/10/28 17:10:11 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

void	ft_putnbr_base_fd(int nbr, char *base, int fd);
void	ft_pintpoin_fd(void *ptr);
void	ft_puthex_fd(unsigned long num, int fd);

#endif