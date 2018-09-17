/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_diuoxX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:07:13 by khou              #+#    #+#             */
/*   Updated: 2018/09/17 00:30:05 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	signed_lengh(t_block *blk, t_write *act)
{
	act->sign = '+';
	if (!ft_strchr("uUxX", blk->specifier))
	{
		
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
	else
	{
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
	// printf("blk->data.s_signed: %ju\n", blk->data.un_signed);
	// printf("act.nbr: %d\n", act->nbr);
}
void	establish_write(t_write *act)
{
	act->sign='\0';
	act->nbr = 0;
	act->length = 0;
	act->space = 0;
	act->zero = 0;
	act->base = 10;
}

int	bigger(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

void	write_blk(t_block *blk, t_write *act)
{
	act->space <= 0 && act->sign ? *blk->ret += 1 : 0;
	act->sign && act->space-- > 0 ? *blk->ret += 1 : 0;
	blk->prepend_space && act->sign ? blk->prepend_space = false : 0;
//	printf("T/F: %d\n",  act->sign);
//	printf("T/F: %d\n", act->space);

	act->space <= 0 && blk->prepend_space ? *blk->ret += 1 : 0;
	blk->prepend_space && act->space-- > 0 ? *blk->ret += 1 : 0;  
	act->space < 0 ? act->space = 0: 0;
//	printf("before ret: %d\n", *blk->ret);
	*blk->ret += act->zero + act->space;
//	printf("final ret: %d\n", *blk->ret);
//	printf("zero: %d, space: %d, len: %d\n", act->zero, act->space, act->length);
	if (blk->left_align)
	{
		(blk->prepend_space) && write(*blk->fd, " ", 1);
		blk->sign || blk->data.s_signed < 0 ? write(1, &act->sign, 1) : 0;
		while (act->zero-- > 0)
			write(*blk->fd, "0", 1);
		*blk->ret += ft_putnbr(act->nbr, blk->specifier);
//		printf("space: %d", act->space);
		while (act->space-- >0)
			write(*blk->fd, " ", 1);
	}
	else
	{
		(blk->prepend_space) && write(*blk->fd, " ", 1);
		blk->prepend_zero && act->sign ? write(1, &act->sign, 1) : 0;
//		printf("prezero: %d, sign: %d, right?: %d\n", blk->prepend_zero, act->sign, blk->prepend_zero && act->sign); 
		while (act->space-- >0)
		{
			blk->prepend_zero ? write(*blk->fd, "0", 1) : write(*blk->fd, " ", 1);

		}

		!blk->prepend_zero && act->sign ? write(1, &act->sign, 1) : 0;
	//	printf("!!!!!!!!!!!!\n");
	//	while (1);
		while (act->zero-- > 0)
			write(*blk->fd, "0", 1);
		if ((blk->precision < -1 || blk->precision == 0) && act->nbr == 0)
//			*blk->ret= *blk->ret - 1;
			return;
		else
		*blk->ret += ft_putnbr(act->nbr, blk->specifier);
	}
//	printf("ret: %d\n", *blk->ret);
}

void		p_diuoxX(t_block *blk)
{
	uintmax_t	tmp;
	t_write act;

	establish_write(&act);
	signed_lengh(blk, &act);//got val in blk 
	// if (blk->data.s_signed < 0)
	// { 
	// 	act.sign = '-';
	// 	act.nbr = -blk->data.s_signed;
	// }
	// else
	// {
	// 	act.sign = '+'; 
	// 	act.nbr = blk->data.un_signed;
	// }
	// (!(blk->sign) && blk->data.s_signed >= 0) ? act.sign = '\0' : 0;
	// printf("act.sign: %d\n", act.sign);
	// printf("sign_final: %d\n", !(!blk->sign || tmp > 0) && act.sign); 
//	printf("base: %d\n", act.base);
//	printf("specifier: %c\n", blk->precision);
	tmp = act.nbr;
	while (tmp)
	{
		tmp /= 10;
		act.length++;
	}
	// printf("act.nbr: %d\n", act.nbr);
	(act.nbr == 0) ? act.length++ : 0;
	act.space = blk->width - bigger(blk->precision, act.length);// +, -, 0
//	printf("p_di,space: %d\n", act.space);
	act.space < 0 ? act.space = 0: 0;
	act.zero = (blk->precision - act.length);
	act.zero < 0 ? act.zero = 0: 0;// +, -, 0
//	printf("width: %d, precision: %d, len: %d\n", blk->width,blk->precision,act.length);
//	printf("p_di,space: %d", act.space);
	if ((blk->precision < -1 || blk->precision == 0) && act.nbr == 0)
		if (act.space++ > 0)
            write_blk(blk, &act);
        else
			return ;
	else
		write_blk(blk, &act);
}
