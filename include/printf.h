/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:12:49 by khou              #+#    #+#             */
/*   Updated: 2018/08/29 02:24:36 by khou             ###   ########.fr       */
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



/*
** -----------------------------------------------------------------------------
** -------------------------------- Sources ------------------------------------
** -----------------------------------------------------------------------------
*/
int                     ft_printf(const char *format, ...);
void		parse(t_print *all);

#endif
