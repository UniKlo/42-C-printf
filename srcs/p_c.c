/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_c.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:48:19 by khou              #+#    #+#             */
/*   Updated: 2018/09/17 17:50:48 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	p_c(t_block *blk)
{
	char	c;

	blk->specifier == 'c' ? c = va_arg(*blk->ap, int) : 0;
	//c = va_arg(*blk->ap, int);
	blk->specifier == '%' ? c = '%' : 0;
//	printf("ret: %d\n", *blk->ret);
	if (blk->width) 
		*blk->ret += blk->width;
	else 
		*blk->ret += 1;
//	printf("T/F: %d\n", blk->width);
	blk->width ? blk->width -= 1 : 0;
//	printf("ret: %d\n", *blk->ret);

//	blk->specifier == 'c' ? c = va_arg(*blk->ap, int) : 0;
//	printf("ret: %c\n", c);
//5	c == '\0' && !blk->width ? *blk->ret += 1 : 0;
	if (blk->left_align)
    {
		write(1 , &c, 1);
		while (blk->width-- >0)
			write(*blk->fd, " ", 1);
	}
	else
	{
		while (blk->width-- >0)
            write(*blk->fd, " ", 1);
		write(1 , &c, 1);
	}
}
