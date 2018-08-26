/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:20:45 by khou              #+#    #+#             */
/*   Updated: 2018/08/26 15:57:06 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

int		ft_printf(const char * format, ...)
{
	va_list	ap;

	va_start(ap, format);
//	while ((char *)format)
//	{
//		ft_putstr(format);
//	}
	va_end(ap);
	return (0);
}
