/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:12:49 by khou              #+#    #+#             */
/*   Updated: 2018/09/08 19:20:39 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -------------------------- External Headers ---------------------------------
*/

# include "../libft/libft.h"
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>
# include <stdbool.h>

/*
** ----------------------------- Union  Type  ----------------------------------
*/
union						u_type
{
	int						di;
	short int				hdi;
	signed char				hhdi;
	long int				ldi;
	long long int			lldi;
	intmax_t				jdi;
	unsigned int			uox;
	unsigned short int		huox;
	unsigned char			hhuox;
	unsigned long int		luox;
	unsigned long long int	lluox;
	uintmax_t				juox;
	size_t					zdiuox;
//	wint_t					lc;
	unsigned 				charc;
//	wchar_t					lc;
	char					*s;
	wchar_t					*ls;
//	void					p;
};

/*
** ------------------------- Structure Definition ------------------------------
*/
typedef struct				s_print
{
	char		*format;
	va_list		ap;
	int			ret;
	int			fd;

}							t_print;

typedef struct              s_block
{
	bool	alt_form;
	bool	left_align;
	bool	prepend_space;
	bool	prepend_zero;
	bool	show_sign;
	char	length[3];
    char        specifier;
	int 	len;
	int		precision;
	int		width;
//    va_list		*ap;
    int			*ret;
    int			*fd;
union u_type	t;
}                           t_block;

typedef void	(*t_fun_tbl)(t_block *blk, union u_type *t, va_list ap);

/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/
int                     ft_printf(const char *format, ...);
void		parse(t_print *all);
void		grab_flag(t_block *blk,char *format, int *i);
void		fmt_decimal(t_print *all, t_block *blk);
void		p_s(t_block *blk, union u_type *t, va_list ap)
#endif
