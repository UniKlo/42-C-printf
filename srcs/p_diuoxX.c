/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_diuoxX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:07:13 by khou              #+#    #+#             */
/*   Updated: 2018/09/24 14:32:49 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

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
	char *s;

	s = "\0";
    if (blk->hash)
    {
        blk->specifier == 'x' ? s = "0x" : 0;
        blk->specifier == 'X' ? s = "0X" : 0;
//		printf("act->space1: %d\n", act->space);
//		printf("blk->precision: %d\n", blk->precision);
//		if (act->space - 2 >= 0 && *s && blk->precision != -1)
		if (act->space - 2 >= 0 && *s)
			act->space -= 2;
		if (blk->precision == -1 && act->space > 0 && act->nbr == 0 && 
			(blk->specifier == 'x' || blk->specifier == 'X'))
			act->space += 2;
//		printf("act->space2: %d\n", act->space);
		*s && act->nbr == 0 ? s = "\0" : 0;
	}
	act->space <= 0 && act->sign ? *blk->ret += 1 : 0;
	act->sign && act->space-- > 0 ? *blk->ret += 1 : 0;
	blk->prepend_space && act->sign ? blk->prepend_space = false : 0;
	act->space <= 0 && blk->prepend_space ? *blk->ret += 1 : 0;
	blk->prepend_space && act->space-- > 0 ? *blk->ret += 1 : 0;  
	act->space < 0 ? act->space = 0: 0;
	*blk->ret += act->zero + act->space;
//	printf("act->zero: %d\n", act->zero);
	if (blk->left_align)
	{
		(blk->prepend_space) && write(*blk->fd, " ", 1);
		act->sign || blk->data.s_signed < 0 ? write(1, &act->sign, 1) : 0;
		*blk->ret += ft_putstr(s, ft_strlen(s));
		while (act->zero-- > 0)
			write(*blk->fd, "0", 1);
		*blk->ret += ft_putnbr(act->nbr, blk->specifier);
		while (act->space-- >0)
			write(*blk->fd, " ", 1);
	}
	else
	{
		(blk->prepend_space) && write(*blk->fd, " ", 1);
		blk->prepend_zero && act->sign ? write(1, &act->sign, 1) : 0;
//		printf("act->sign: %c\n", act->sign);
		blk->prepend_zero ? *blk->ret += ft_putstr(s, ft_strlen(s)) : 0;
		while (act->space-- >0)
		{
			blk->prepend_zero ? write(*blk->fd, "0", 1) : write(*blk->fd, " ", 1);

		}
		!blk->prepend_zero ? *blk->ret += ft_putstr(s, ft_strlen(s)) : 0 ;
		!blk->prepend_zero && act->sign ? write(1, &act->sign, 1) : 0;
		//printf("T/F: %d\n", !blk->prepend_zero && act->sign);
		while (act->zero-- > 0)
			write(*blk->fd, "0", 1);
//		printf("T/F: %d\n", blk->precision);
		if ((blk->precision < -1 || blk->precision == 0) && act->nbr == 0)
			return;
		else if (blk->precision == -1 && blk->specifier == 'o' && act->nbr == 0)
			return;
		else
			*blk->ret += ft_putnbr(act->nbr, blk->specifier);
	}
}

void		p_diuoxX(t_block *blk)
{
	uintmax_t	tmp;
	t_write act;

	establish_write(&act);
	if (!ft_strchr("uUxXo", blk->specifier))
		signed_lengh(blk, &act);//got val in blk
	else
		unsigned_lengh(blk, &act);
	tmp = act.nbr;
	while (tmp)
	{
		tmp /= 10;
		act.length++;
	}
    if (blk->hash)
    {
		blk->specifier == 'o' ? act.sign = '0' : 0;
		blk->specifier == 'O' ? act.sign = '0' : 0;
		if (act.nbr == 0 && blk->prepend_space != 0)
		{
			blk->prepend_space = false;
			act.sign = '\0';
		}
//		printf("sign: {%c}\n", act.sign);
	}
	printf("act.length1: %d\n", act.length);
	(blk->specifier != 'o'  && act.nbr == 0) ? act.length++ : act.length;
	act.nbr == 0 ? act.length++ : 0;
    printf("act.length2: %d\n", act.length);
	act.space = blk->width - bigger(blk->precision, act.length);// +, -, 0
	act.space < 0 ? act.space = 0: 0;
//	printf("act.space:  %d\n", act.space);
	act.zero = (blk->precision - act.length);
	act.zero < 0 ? act.zero = 0: 0;// +, -, 0
//	printf("act.zero: %d\n", act.zero);
	if ((blk->precision < -1 || blk->precision == 0) && act.nbr == 0)
		if (act.space > 0 || act.sign)
		{
			if (blk->specifier != 'o' && blk->specifier != 'O')
			{
				act.space++;
//				printf("T/F: %d\n", blk->specifier != 'o');
//				printf("act.space2:  %d\n", act.space);
			}
            write_blk(blk, &act);
		}
        else
			return ;
	else
		write_blk(blk, &act);
}
