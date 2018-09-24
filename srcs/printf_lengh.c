/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_lengh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:12:46 by khou              #+#    #+#             */
/*   Updated: 2018/09/24 12:13:15 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void    signed_lengh(t_block *blk, t_write *act)
{
//  static char     *len = "\0";
    act->sign = '+';
    if (blk->length[0] == '\0')
        blk->data.s_signed = (int)va_arg(*blk->ap, int);
    else if (blk->length[0] == 'h' && blk->length[1] == 'h')
        blk->data.s_signed = (char)va_arg(*blk->ap, int);
    else if (blk->length[0] == 'h')
        blk->data.s_signed = (short int)va_arg(*blk->ap, int);
    else if (blk->length[0] == 'l' && blk->length[1] == 'l')
        blk->data.s_signed = va_arg(*blk->ap, long long int);
    else if (blk->length[0] == 'l')
        blk->data.s_signed = va_arg(*blk->ap, long int);
    else if (blk->length[0] == 'j')
        blk->data.s_signed = va_arg(*blk->ap, intmax_t);
    else if (blk->length[0] == 'z')
        blk->data.s_signed = va_arg(*blk->ap, size_t);
    if (blk->data.s_signed < 0)
    {
        act->sign = '-';
        act->nbr = -blk->data.s_signed;
    }
    else
        act->nbr = blk->data.un_signed;
    (!(blk->sign) && blk->data.s_signed >= 0) ? act->sign = '\0' : 0;
}

void    unsigned_lengh(t_block *blk, t_write *act)
{
    act->sign = '+';
    if (blk->length[0] == '\0')
        blk->data.un_signed = (unsigned int)va_arg(*blk->ap, unsigned int);
    else if (blk->length[0] == 'h' && blk->length[1] == 'h')
        blk->data.un_signed = (unsigned char)va_arg(*blk->ap, unsigned int);
    else if (blk->length[0] == 'h')
        blk->data.un_signed = (unsigned short int)va_arg(*blk->ap, unsigned int);
    else if (blk->length[0] == 'l' && blk->length[1] == 'l')
        blk->data.un_signed = va_arg(*blk->ap, unsigned long long int);
    else if (blk->length[0] == 'l')
        blk->data.un_signed = va_arg(*blk->ap, unsigned long int);
    else if (blk->length[0] == 'j')
        blk->data.un_signed = va_arg(*blk->ap, uintmax_t);
    else if (blk->length[0] == 'z')
        blk->data.un_signed = va_arg(*blk->ap, size_t);
    act->nbr = blk->data.un_signed;
    !(blk->sign) ? act->sign = '\0' : 0;
}
