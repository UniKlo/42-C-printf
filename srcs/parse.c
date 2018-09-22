/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 00:48:14 by khou              #+#    #+#             */
/*   Updated: 2018/09/22 16:18:03 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static void	establish(t_print *all, t_block *blk)
{
	blk->left_align = false;
	blk->sign = false;
	blk->prepend_space = false;
	blk->prepend_zero = false;
	blk->hash = false;
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

	f['s'] = &p_s;
	f['S'] = &p_ls;
	f['p'] = &p_diuoxX;
	f['d'] = &p_diuoxX;
	f['D'] = &p_diuoxX;
	f['i'] = &p_diuoxX;
	f['o'] = &p_diuoxX;
	f['O'] = &p_diuoxX;
	f['u'] = &p_diuoxX;
	f['U'] = &p_diuoxX;
	f['x'] = &p_diuoxX;
	f['X'] = &p_diuoxX;
	f['c'] = &p_c;
	f['C'] = &p_c;
	f['%'] = &p_c;
	f['Z'] = &undef;
/* 	f['b'] = &ft_printf_diuoxb; */
/* 	f['B'] = &ft_printf_diuoxb; */
	return (f[(int)c]);
}

static void	sort(t_print *all, int *i)
{
	t_block		blk;
	t_fun_tbl		f;

	establish(all, &blk);
	grab_flag(&blk, all->format, i);//check the whole fmt. 
	f = dispatch_table(blk.specifier);
	if (f != NULL)
		f(&blk);
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
//			while (all->format[i++] == '%');
			spell(all, beg, i);
//			while (all->format[i++] == '%');
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
