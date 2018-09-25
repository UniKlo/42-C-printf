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

static void	sort(t_print *all, int *i)
{
	t_block		blk;
	t_fun_tbl	f;

	establish(all, &blk);
	grab_flag(&blk, all->format, i);
	f = dispatch_table(blk.specifier);
	if (f != NULL)
		f(&blk);
}

static void	spell(t_print *all, int beg, int i)
{
	write(all->fd, all->format + beg, i - beg);
	all->ret += i - beg;
}

void		parse(t_print *all)
{
	int		beg;
	int		i;

	beg = 0;
	i = -1;
	while (all->format[++i])
	{
		if (all->format[i] == '%')
		{
			spell(all, beg, i);
			sort(all, &i);
			beg = i + 1;
		}
	}
	spell(all, beg, i);
}

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
