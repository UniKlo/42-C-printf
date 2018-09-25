/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 00:48:14 by khou              #+#    #+#             */
/*   Updated: 2018/09/24 15:50:54 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static void	establish(t_print *all, t_block *blk)
{
	blk->hash = false;
	blk->left_align = false;
	blk->pad_s = false;
	blk->pad_z = false;
	blk->sign = false;
	blk->width = 0;
	blk->p_dot = -1;
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

	f['s'] = &set_s;
	f['S'] = &set_ls;
	f['p'] = &p_diuox;
	f['d'] = &p_diuox;
	f['D'] = &p_diuox;
	f['i'] = &p_diuox;
	f['o'] = &p_diuox;
	f['O'] = &p_diuox;
	f['u'] = &p_diuox;
	f['U'] = &p_diuox;
	f['x'] = &p_diuox;
	f['X'] = &p_diuox;
	f['c'] = &p_c;
	f['C'] = &p_c;
	f['%'] = &p_c;
	f['Z'] = &undef;
	return (f[(int)c]);
}

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
