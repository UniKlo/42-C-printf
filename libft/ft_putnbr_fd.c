/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:33:05 by khou              #+#    #+#             */
/*   Updated: 2018/09/16 02:07:09 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(uintmax_t n, int base, int fd)
{
    if (n / base != 0)
        ft_putnbr_fd(n / base, base, fd);
    if (n % base >= 10)
    {
		ft_putchar_fd(n % base -10 + 'a', fd);
	}
    else
		ft_putchar_fd(n % base + '0', fd);
}
