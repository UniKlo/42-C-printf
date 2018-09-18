/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:11:14 by khou              #+#    #+#             */
/*   Updated: 2018/09/18 00:58:54 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		p_s(t_block *blk)
{
	char	*s;
	t_write		act;
	establish_write(&act);
	s =va_arg(*blk->ap, char*);//store the str in s
	blk->precision == -1 ? act.length = ft_strlen(s) : blk->precision;
	if (blk->precision > 0)
	{
		if ((blk->precision > (int)ft_strlen(s)) && ft_strlen(s) > 0)
			act.length = ft_strlen(s);
		else
			act.length =blk->precision;
	}
//	printf("%d", act.length);
	if (blk->width && ft_strlen(s) > 0)
		act.space = blk->width - bigger(blk->precision, act.length);
	else
		act.space = blk->width;
//	printf("%d", *blk->ret);
	*blk->ret =  *blk->ret + act.space;
//!blk->precision 
//	printf("%d\n", *blk->ret);
	if (blk->left_align)
    {
		*blk->ret += ft_putstr(s, act.length);
		while (act.space-- >0)
		{
            blk->prepend_zero ? write(*blk->fd, "0", 1) : write(*blk->fd, " ", 1);

        }
	}
    else
    {
		while (act.space-- >0)
		{
            blk->prepend_zero ? write(*blk->fd, "0", 1) : write(*blk->fd, " ", 1);

        }
		*blk->ret += ft_putstr(s, act.length);
	}
}
