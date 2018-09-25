/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_lengh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:12:46 by khou              #+#    #+#             */
/*   Updated: 2018/09/24 16:14:50 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	signed_lengh(t_block *blk, t_write *act)
{
	act->sign = '+';
	if (blk->length[0] == '\0')
		blk->s_data = (int)va_arg(*blk->ap, int);
	else if (blk->length[0] == 'h' && blk->length[1] == 'h')
		blk->s_data = (char)va_arg(*blk->ap, int);
	else if (blk->length[0] == 'h')
		blk->s_data = (short int)va_arg(*blk->ap, int);
	else if (blk->length[0] == 'l' && blk->length[1] == 'l')
		blk->s_data = va_arg(*blk->ap, long long int);
	else if (blk->length[0] == 'l')
		blk->s_data = va_arg(*blk->ap, long int);
	else if (blk->length[0] == 'j')
		blk->s_data = va_arg(*blk->ap, intmax_t);
	else if (blk->length[0] == 'z')
		blk->s_data = va_arg(*blk->ap, size_t);
	if (blk->s_data < 0)
	{
		act->sign = '-';
		act->nbr = -blk->s_data;
	}
	else
		act->nbr = blk->s_data;
	(!(blk->sign) && blk->s_data >= 0) ? act->sign = '\0' : 0;
}

void	unsigned_lengh(t_block *blk, t_write *act)
{
	act->sign = '+';
	if (blk->length[0] == '\0')
		blk->un_data = (unsigned int)va_arg(*blk->ap, unsigned int);
	else if (blk->length[0] == 'h' && blk->length[1] == 'h')
		blk->un_data = (unsigned char)va_arg(*blk->ap, unsigned int);
	else if (blk->length[0] == 'h')
		blk->un_data =\
			(unsigned short int)va_arg(*blk->ap, unsigned int);
	else if (blk->length[0] == 'l' && blk->length[1] == 'l')
		blk->un_data = va_arg(*blk->ap, unsigned long long int);
	else if (blk->length[0] == 'l')
		blk->un_data = va_arg(*blk->ap, unsigned long int);
	else if (blk->length[0] == 'j')
		blk->un_data = va_arg(*blk->ap, uintmax_t);
	else if (blk->length[0] == 'z')
		blk->un_data = va_arg(*blk->ap, size_t);
	act->nbr = blk->un_data;
	!(blk->sign) ? act->sign = '\0' : 0;
}
