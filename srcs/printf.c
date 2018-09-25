/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:20:45 by khou              #+#    #+#             */
/*   Updated: 2018/09/24 15:29:17 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int		ft_printf(const char *format, ...)
{
	t_print		all;

	all.ret = 0;
	all.fd = 1;
	all.format = (char *)format;
	va_start(all.ap, format);
	parse(&all);
	va_end(all.ap);
	return (all.ret);
}
