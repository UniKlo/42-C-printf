/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:12:49 by khou              #+#    #+#             */
/*   Updated: 2018/09/24 17:48:34 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -------------------------- External Headers ---------------------------------
*/

# include "libft.h"
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>
# include <stdbool.h>
# include <wchar.h>

/*
** ------------------------- Structure Definition ------------------------------
*/
typedef struct	s_print
{
	char		*format;
	va_list		ap;
	int			ret;
	int			fd;

}				t_print;

typedef struct	s_block
{
	bool		hash;
	bool		left_align;
	bool		prepend_space;
	bool		prepend_zero;
	bool		sign;
	int			width;
	int			precision;
	char		length[3];
	char		specifier;
	int			len;
	va_list		*ap;
	int			*ret;
	int			*fd;
	intmax_t	s_data;
	uintmax_t	un_data;

}				t_block;

typedef void	(*t_fun_tbl)(t_block *blk);

typedef struct	s_write
{
	char		sign;
	uintmax_t	nbr;
	int			length;
	int			space;
	int			zero;
	int			base;
}				t_write;
/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/
void			parse(t_print *all);
void			grab_flag(t_block *blk, char *format, int *i);
void			fmt_decimal(t_print *all, t_block *blk);
void			p_diuox(t_block *blk);
void			p_c(t_block *blk);
void			p_s(t_block *blk);
void			p_ls(t_block *blk);
int				bigger(int a, int b);
void			establish_write(t_write *act);
void			undef(t_block *blk);
int				ft_printf(const char *format, ...);
void			signed_lengh(t_block *blk, t_write *act);
void			unsigned_lengh(t_block *blk, t_write *act);

#endif
