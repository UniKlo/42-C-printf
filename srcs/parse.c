/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 00:48:14 by khou              #+#    #+#             */
/*   Updated: 2018/09/14 13:46:41 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	establish(t_print *all, t_block *blk)
{
	blk->left_align = false;
	blk->sign = false;
	blk->prepend_space = false;
	blk->prepend_zero = false;
	blk->alt_form = false;
	blk->width = 0;
	blk->precision = -1;
	blk->length[0] = '\0';//for char for len
	blk->length[1] = '\0';//
	blk->length[2] = '\0';//
	blk->specifier = 0;
	blk->len = 0;
	blk->ap = &all->ap;
	blk->fd = &all->fd;
	blk->ret = &all->ret;
}

t_fun_tbl	dispatch_table(char c)
{
	t_fun_tbl	f[123];

//	f['s'] = &p_s;
//	f['S'] = &ft_printf_ls;
//	f['p'] = &ft_printf_p;
	f['d'] = &p_di;
//	f['D'] = &ft_printf_uoxb;
	f['i'] = &p_di;
/*	f['o'] = &ft_printf_uoxb;
	f['O'] = &ft_printf_uoxb;
	f['u'] = &ft_printf_uoxb;
	f['U'] = &ft_printf_uoxb;
	f['x'] = &ft_printf_uoxb;
	f['X'] = &ft_printf_uoxb;*/
/*	f['c'] = &ft_printf_c;
	f['C'] = &ft_printf_c;
	f['b'] = &ft_printf_diuoxb;
	f['B'] = &ft_printf_diuoxb;*/
	return (f[(int)c]);
}

static void	sort(t_print *all, int *i)
{
	t_block		blk;
	t_fun_tbl		f;

	establish(all, &blk);
	grab_flag(&blk, all->format, i);//check the whole fmt. 
//	blk.t = va_arg(*blk->ap, union u_type);//grab the value into union
	f = dispatch_table(blk.specifier);
	if (f != NULL)
		f(&blk);
//	else
//		ft_printf_c(p, &(p->t), ap[0]);
/*    printf("#+-0' '\n%i%i%i%i %i\n", blk.alt_form,
           blk.show_sign,
           blk.left_align,
           blk.prepend_zero,
           blk.prepend_space);*/
//	blk.specifier = all->format[i];
//	if (blk.specifier == 'd')
//		fmt_decimal(all, &blk);
}

static void spell(t_print *all, int beg, int i)
{
    write(all->fd, all->format + beg, i - beg);
	all->ret += i - beg;//total = diff btw % and non block
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
//			printf("%d", all->ret);
			sort(all, &i);//send from %, the address of i, i need to be updated
			//		printf("format index i is at: %i\n", i);
			beg = i + 1;//step over specifier
		}
    }
//	printf("format index i is at: %i\n", i);
	spell(all, beg, i);
//  printf("all->ret is: %i\n", all->ret);
}
