/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_diouxb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:07:13 by khou              #+#    #+#             */
/*   Updated: 2018/09/12 22:27:43 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	signed_lengh(t_block *blk)
{
	if (blk->length[0] == '\0')
		blk->data.s_signed = va_arg(*blk->ap, int);
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
}
void	establish_write(t_write *act)
{
	act->sign='\0';
	act->nbr = 0;
	act->length = 0;
	act->space = 0;
	act->zero = 0;
}

int	bigger(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

void	write_blk(t_block *blk, t_write *act)
{
	blk->sign ? act->space-- : 0;
	act->space < 0 ? act->space = 0: 0;
	*blk->ret += act->zero + act->space + act->length;
	blk->sign || blk->data.s_signed < 0 ? *blk->ret += 1 : 0;
	if (blk->left_align)
	{
		blk->sign || blk->data.s_signed < 0 ? write(1, &act->sign, 1) : 0;
		while (act->zero-- > 0)
			write(*blk->fd, "0", 1);
		ft_putnbr(act->nbr);
		while (act->space-- >0)
			write(*blk->fd, " ", 1);
	}
	else
	{
		while (act->space-- >0)
			write(*blk->fd, " ", 1);
		blk->sign || blk->data.s_signed < 0 ? write(1, &act->sign, 1) : 0;
	//	printf("!!!!!!!!!!!!\n");
	//	while (1);
		while (act->zero-- > 0)
			write(*blk->fd, "0", 1);
		ft_putnbr(act->nbr);
	}
}

void		p_di(t_block *blk)
{
	intmax_t	tmp;
	t_write act;

	establish_write(&act);
	signed_lengh(blk);//got val in blk 
	tmp = blk->data.s_signed;
	if (tmp < 0)
	{ 
		act.sign = '-';
		act.nbr = -blk->data.s_signed;
	}
	else
	{
		act.sign = '+'; 
		act.nbr = blk->data.s_signed;
	}
	tmp = act.nbr;
	while (tmp)
	{
		tmp /= 10;
		act.length++;
	}
	act.space = blk->width - bigger(blk->precision, act.length);// +, -, 0
	act.space < 0 ? act.space = 0: 0;
	act.zero = (blk->precision - act.length);
	act.zero < 0 ? act.zero = 0: 0;// +, -, 0
	write_blk(blk, &act);
}
