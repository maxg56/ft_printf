/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgendrot <mgendrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:33:12 by mgendrot          #+#    #+#             */
/*   Updated: 2024/10/28 17:22:56 by mgendrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int ft_printf(const char *count, ...)
{
	va_list	args;
	
	va_start(args, count);
	printf("%s",va_arg(args, char));

	va_end(args);
}
