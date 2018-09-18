/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:11:14 by khou              #+#    #+#             */
/*   Updated: 2018/09/17 20:27:35 by khou             ###   ########.fr       */
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
	if (blk->width)
		act.space = blk->width - bigger(blk->precision, act.length);
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
//	printf("after: %d\n", *blk->ret);

//	*blk->ret += ft_putstr(s, 3);
/* 	if (!t->s && p->pre == -1) */
/* 		t->s = "(null)"; */
/* 	else if (!t->s) */
/* 		t->s = ""; */
/* 	else if (p->pre > -1) */
/* 		t->s = ft_strsub(t->s, 0, p->pre); */
/* 	if (p->left == 1) */
/* 		buf_s(p, t->s, ft_strlen(t->s)); */
/* 	while (++i < (int)(p->min_w - ft_strlen(t->s))) */
/* 	{ */
/* 		if (p->zero == 1) */
/* 			buf_c(p, '0'); */
/* 		else */
/* 			buf_c(p, ' '); */
/* 	} */
/* 	if (p->left != 1) */
/* 		buf_s(p, t->s, ft_strlen(t->s)); */
}
