
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 18:43:39 by khou              #+#    #+#             */
/*   Updated: 2018/09/09 19:03:21 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int length(t_block *blk, char *blk_fmt)
{
	int x;

	x = 0;
	if (blk_fmt[x] == 'h' && blk_fmt[x + 1] == 'h' && (x = x + 2))
		ft_strcpy(blk->length, "hh\0");
	else if (blk_fmt[x] == 'h' && (x = x + 1))
		ft_strcpy(blk->length, "h\0");
	else if (blk_fmt[x] == 'l' && blk_fmt[x + 1] == 'l' && (x = x + 2))
		ft_strcpy(blk->length, "ll\0");
	else if (blk_fmt[x] == 'l' && (x = x + 1))
		ft_strcpy(blk->length, "l\0");
	else if (blk_fmt[x] == 'z' && (x = x + 1))
		ft_strcpy(blk->length, "z\0");
	else if (blk_fmt[x] == 'j' && (x = x + 1))
		ft_strcpy(blk->length, "j\0");
	return (x - 1);
}

static int	width(t_block *blk, char *blk_fmt)
{
	int x;

	x = 0;
	blk->width = ft_atoi(blk_fmt);
	while (ft_isdigit(blk_fmt[++x]));
	return (x - 1);
}

static int	precision(t_block *blk, char *blk_fmt)
{
	int x;

	x = 0;
	if (ft_isdigit(blk_fmt[x]))
	{
		blk->precision = ft_atoi(blk_fmt);//read all the nbr
		while (ft_isdigit(blk_fmt[++x]));//exit on the last digit
	}
	else
		blk->precision = 0;
	
	return (x);
}

 void	is_flag(t_block *blk, char c)
{
	char	flag;

//	if (!(flag = *ft_strchr("#+-0 ", c)))
	if (!ft_strchr("#+-0 ", c))
		return;
	flag = *ft_strchr("#+-0 ", c);
	blk->alt_form == 1 || flag == '#' ? blk->alt_form = true : false;
	blk->show_sign == 1 || flag == '+' ? blk->show_sign = true : false;
	blk->left_align == 1 || flag == '-' ? blk->left_align = true : false;
	blk->prepend_zero == 1 || flag == '0' ? blk->prepend_zero = true : false;
	blk->prepend_space == 1 || flag == ' ' ? blk->prepend_space = true : false;
}

static int	specifier(t_block *blk, char c)//work, 1: why static 2.can combine?
{

	if ((c == 's' || c == 'S'|| c == 'p' || c == 'd' || c == 'D' || c == 'i' 
		 || c == 'o' || c == 'O' || c == 'u' || c == 'U'|| c == 'x' || c == 'X'
		 || c == 'c' || c == 'C' ||  c == 'u' || c == 'U' 
		 //|| c == '%' || c == 'n' || c == 'e' || c == 'g' || c == 'G'
		 ) && (blk->specifier = c))
		return (1);
	printf("invalid directive\n");//not valid char
	return (0);
}

void	grab_flag(t_block *blk, char *blk_fmt, int *i)
{
	while (blk_fmt[++*i] && !(specifier(blk, blk_fmt[*i])))// more cpu	
//	while (blk_fmt[++*i] && !(ft_isalpha(blk_fmt[*i])))//check one by one
	{
		//printf("%c\n", blk_fmt[*i]);
		is_flag(blk, blk_fmt[*i]);
		if (blk_fmt[*i] == '.')
			*i += precision(blk, blk_fmt + *i + 1);//dont read number twice?
//				precision(blk, blk_fmt + *i + 1);
		else if (ft_isdigit(blk_fmt[*i]))
			*i += width(blk, blk_fmt + *i);
		if (ft_strchr("hlzj", (blk_fmt[*i])))
			*i += length(blk, blk_fmt + *i);
		//Color
	}
	specifier(blk, blk_fmt[*i]);
	printf("specifier is: %c\n", blk->specifier);
	printf("precision is: %d\n", blk->precision);
	printf("width is: %d\n", blk->width);
	printf("format index is at: %i\n", *i);
/*	printf("#+-0' '\n%i%i%i%i %i\n", blk->alt_form,
		   blk->show_sign,
		   blk->left_align,
		   blk->prepend_zero,
		   blk->prepend_space);*/

}
