/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:33:05 by khou              #+#    #+#             */
/*   Updated: 2018/09/16 20:18:26 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(uintmax_t n, char b, int fd)
{

	int		base;

	base = 10;
	b == 'o' ? base = 8 : 10;
	b == 'x' || b == 'X' ? base = 16 : 10;
	n / base != 0 ? ft_putnbr_fd(n / base, b, fd) : 0;
	if (n % base >= 10)
	{
		b == 'x' ? ft_putchar_fd(n % base -10 + 'a', fd) : 0;
		b == 'X' ? ft_putchar_fd(n % base -10 + 'A', fd) : 0;
//		i++;
	}
	else
	{
		ft_putchar_fd(n % base + '0', fd);
//	i++;
	}
}
