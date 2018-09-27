/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_diuox.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:07:13 by khou              #+#    #+#             */
/*   Updated: 2018/09/26 20:33:48 by khou             ###   ########.fr       */
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
//		printf("blk->p_dot: %d\n", blk->p_dot);
//		if (act->space - 2 >= 0 && *s && blk->p_dot != -1)
		if (act->space - 2 >= 0 && *s)
			act->space -= 2;
		if (blk->p_dot == -1 && act->space > 0 && act->nbr == 0 && 
			(blk->specifier == 'x' || blk->specifier == 'X'))
			act->space += 2;
//		printf("act->space2: %d\n", act->space);
		*s && act->nbr == 0 ? s = "\0" : 0;
	}
	act->space <= 0 && act->sign ? *blk->ret += 1 : 0;
	act->sign && act->space-- > 0 ? *blk->ret += 1 : 0;
	blk->pad_s && act->sign ? blk->pad_s = false : 0;
	act->space <= 0 && blk->pad_s ? *blk->ret += 1 : 0;
	blk->pad_s && act->space-- > 0 ? *blk->ret += 1 : 0;  
	act->space < 0 ? act->space = 0: 0;
	*blk->ret += act->zero + act->space;
//	printf("act->zero: %d\n", act->zero);
	if (blk->left_align)
	{
		(blk->pad_s) && write(*blk->fd, " ", 1);
		act->sign || blk->s_data < 0 ? write(1, &act->sign, 1) : 0;
		*blk->ret += ft_putstr(s, ft_strlen(s));
		while (act->zero-- > 0)
			write(*blk->fd, "0", 1);
		*blk->ret += ft_putnbr(act->nbr, blk->specifier);
		while (act->space-- >0)
			write(*blk->fd, " ", 1);
	}
	else
	{
		(blk->pad_s) && write(*blk->fd, " ", 1);
		blk->pad_z && act->sign ? write(1, &act->sign, 1) : 0;
//		printf("act->sign: %c\n", act->sign);
		blk->pad_z ? *blk->ret += ft_putstr(s, ft_strlen(s)) : 0;
		while (act->space-- >0)
		{
			blk->pad_z ? write(*blk->fd, "0", 1) : write(*blk->fd, " ", 1);

		}
		!blk->pad_z ? *blk->ret += ft_putstr(s, ft_strlen(s)) : 0 ;
		!blk->pad_z && act->sign ? write(1, &act->sign, 1) : 0;
		//printf("T/F: %d\n", !blk->pad_z && act->sign);
		while (act->zero-- > 0)
			write(*blk->fd, "0", 1);
//		printf("T/F: %d\n", blk->p_dot);

		if ((blk->p_dot < -1 || blk->p_dot == 0) && act->nbr == 0)
			return;
		else if (blk->hash && blk->p_dot == -1 && blk->specifier == 'o' && act->nbr == 0)
			return;
//			*blk->ret += ft_putnbr(act->nbr, blk->specifier);
		else
			*blk->ret += ft_putnbr(act->nbr, blk->specifier);
	}
}

void		p_diuox(t_block *blk)
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
//	printf("T/F: %ju\n", tmp);
    if (blk->hash)
    {
		blk->specifier == 'o' ? act.sign = '0' : 0;
		blk->specifier == 'O' ? act.sign = '0' : 0;
//		printf("sign: {%c}\n", act.sign);
	}
//	printf("act.length1: %d\n", act.length);
	act.nbr == 0 ? act.length++ : 0;
//    printf("act.length2: %d\n", act.length);
	act.space = blk->width - bigger(blk->p_dot, act.length);// +, -, 0
	act.space < 0 ? act.space = 0: 0;
//	printf("act.space:  %d\n", act.space);
	act.zero = (blk->p_dot - act.length);
	act.zero < 0 ? act.zero = 0: 0;// +, -, 0
//	printf("act.zero: %d\n", act.zero);
//	printf("T/F: %d\n", (blk->p_dot < -1 || blk->p_dot == 0) && act.nbr == 0);
	if ((blk->p_dot < -1 || blk->p_dot == 0) && act.nbr == 0)
		if (act.space > 0 || act.sign)
		{
			act.space++;
            write_blk(blk, &act);
		}
        else
			return ;
	else
		write_blk(blk, &act);
}
