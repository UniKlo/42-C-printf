/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 00:48:14 by khou              #+#    #+#             */
/*   Updated: 2018/09/09 13:49:52 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	establish(t_print *all, t_block *blk)
{
	blk->left_align = false;
	blk->show_sign = false;
	blk->prepend_space = false;
	blk->prepend_zero = false;
	blk->alt_form = false;
	blk->width = 0;
	blk->precision = -1;
	blk->length[0] = '\0';
	blk->length[1] = '\0';
	blk->length[2] = '\0';
	blk->specifier = 0;
	blk->len = 0;
	blk->ap = &all->ap;
	blk->fd = &all->fd;
	blk->ret = &all->ret;
}

t_fun_tbl	dispatch_table(char c)
{
	t_fun_tbl	f[123];

	f['s'] = &p_s;
	/*
	f['S'] = &ft_printf_ls;
	f['p'] = &ft_printf_p;
	f['d'] = &ft_printf_diuoxb;
	f['D'] = &ft_printf_diuoxb;
	f['X'] = &ft_printf_diuoxb;
	f['i'] = &ft_printf_diuoxb;
	f['o'] = &ft_printf_diuoxb;
	f['O'] = &ft_printf_diuoxb;
	f['u'] = &ft_printf_diuoxb;
	f['U'] = &ft_printf_diuoxb;
	f['x'] = &ft_printf_diuoxb;
	f['c'] = &ft_printf_c;
	f['C'] = &ft_printf_c;
	f['b'] = &ft_printf_diuoxb;
	f['B'] = &ft_printf_diuoxb;*/
	return (f[(int)c]);
}

static void	sort(t_print *all, int *i)
{
	t_block		blk;
	fun_tbl		f;

	establish(all, &blk);
	grab_flag(&blk, all->format, i);//check the whole fmt. 
	f = dispatch_table(blk->type);
	if (f != NULL)
		f(all, &(blk->t), ap);
	else
		ft_printf_c(p, &(p->t), ap[0]);
    printf("#+-0' '\n%i%i%i%i %i\n", blk.alt_form,
           blk.show_sign,
           blk.left_align,
           blk.prepend_zero,
           blk.prepend_space);
//	blk.specifier = all->format[i];
//	if (blk.specifier == 'd')
//		fmt_decimal(all, &blk);
}

static void spell(t_print *all, int beg, int i)
{
    write(all->fd, all->format + beg, i - beg);
	all->ret += i - beg;//total = diff of % and non block
}

void	parse(t_print *all)
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
			sort(all, &i);//send from %, the address of i, i need to be updated
			printf("format index i is at: %i\n", i);
			beg = i + 1;//step over specifier
		}
    }
//	printf("format index i is at: %i\n", i);
	spell(all, beg, i);
}
