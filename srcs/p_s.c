/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:11:14 by khou              #+#    #+#             */
/*   Updated: 2018/09/24 15:25:31 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static int	ft_putwstr(wchar_t *ls, int len)
{
	int		i;

	i = 0;
	while (*ls && i < len)
	{
		if (*ls <= 0x7F)
			i++;
		else if (*ls <= 0x7FF)
			i += 2;
		else if (*ls <= 0xFFFF)
			i += 3;
		else if (*ls <= 0x10FFFF)
			i += 4;
		if (i <= len)
			ft_putchar(*ls++);
	}
	return (i);
}

static int	ls_len(wchar_t *ls)
{
	int	len;

	len = 0;
	while (*ls != L'\0')
	{
		if (*ls <= 0x007F)
			len += 1;
		else if (*ls <= 0x07FF)
			len += 2;
		else if (*ls <= 0xFFFF)
			len += 3;
		else if (*ls <= 0x10FFFF)
			len += 4;
		ls++;
	}
	return (len);
}

void		p_ls(t_block *blk)
{
	wchar_t		*ls;
	t_write		act;

	establish_write(&act);
	ls = va_arg(*blk->ap, wchar_t *);
	if (!ls)
		ls = L"(null)";
	blk->precision == -1 ? act.length = ls_len(ls) : blk->precision;
	if (blk->precision > 0)
	{
		if ((blk->precision > ls_len(ls)) && ls_len(ls) > 0)
			act.length = ls_len(ls);
		else
			act.length = blk->precision;
	}
	if (blk->width && ls_len(ls) > 0)
		act.space = blk->width - bigger(blk->precision, act.length);
	else
		act.space = blk->width;
	*blk->ret = *blk->ret + act.space;
	if (blk->left_align)
	{
		*blk->ret += ft_putwstr(ls, act.length);
		while (act.space-- > 0)
			blk->prepend_zero ?\
				write(*blk->fd, "0", 1) : write(*blk->fd, " ", 1);
	}
	else
	{
		while (act.space-- > 0)
			blk->prepend_zero ?\
				write(*blk->fd, "0", 1) : write(*blk->fd, " ", 1);
		*blk->ret += ft_putwstr(ls, act.length);
	}
}

void		p_s(t_block *blk)
{
	char		*s;
	t_write		act;

	establish_write(&act);
	s = va_arg(*blk->ap, char *);
	if (!s)
		s = "(null)";
	blk->precision == -1 ? act.length = ft_strlen(s) : blk->precision;
	if (blk->precision > 0)
	{
		if ((blk->precision > (int)ft_strlen(s)) && ft_strlen(s) > 0)
			act.length = ft_strlen(s);
		else
			act.length = blk->precision;
	}
	if (blk->width && ft_strlen(s) > 0)
		act.space = blk->width - bigger(blk->precision, act.length);
	else
		act.space = blk->width;
	*blk->ret = *blk->ret + act.space;
	if (blk->left_align)
	{
		*blk->ret += ft_putstr(s, act.length);
		while (act.space-- > 0)
			blk->prepend_zero ?\
				write(*blk->fd, "0", 1) : write(*blk->fd, " ", 1);
	}
	else
	{
		while (act.space-- > 0)
			blk->prepend_zero ?\
				write(*blk->fd, "0", 1) : write(*blk->fd, " ", 1);
		*blk->ret += ft_putstr(s, act.length);
	}
}
