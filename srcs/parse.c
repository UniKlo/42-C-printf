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

void	establish(t_print *all, t_block *blk)
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

void	grab_flag(t_block *blk, char *blk_fmt, int *i)
{
	while (blk_fmt[++*i] && !ft_strchr("sSpdDioOuUxXcC%Z", blk_fmt[*i]))
	{
		//printf("%c\n", blk_fmt[*i]);
		if (is_flag(blk, blk_fmt[*i]));//better to check it one by one
		else if (blk_fmt[*i] == '.')//check it in chunk
			*i += p_dot(blk, blk_fmt + *i + 1);
		else if (!blk->width && ft_isdigit(blk_fmt[*i]))
			*i += width(blk, blk_fmt + *i);
		else if (ft_strchr("hlzj", (blk_fmt[*i])))
			*i += length(blk, blk_fmt + *i);
		//		printf("invalid directive from flag: %c\n", blk_fmt[*i]);//not valid char
	}
//	printf("out zero: %d\n", blk->pad_z);
//	printf("T/F: %d\n", !blk_fmt[++*i]);
	specifier(blk, blk_fmt[*i]);
	valid_all(blk);
//	printf("\n#+-0 :\n%d%d%d%d%d\n", blk->alt_form, blk->sign, blk->left_align, blk->pad_z, blk->pad_s);
//	printf("specifier: %c, lengh: %s\n", blk->specifier, blk->length);
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
