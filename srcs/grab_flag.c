/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 18:43:39 by khou              #+#    #+#             */
/*   Updated: 2018/09/15 15:17:25 by khou             ###   ########.fr       */
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
//	printf("blk-width: %d\n", blk->width);
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
//		printf("blk->precision: %d\n", blk->precision);
	}
	else
		blk->precision = -5;
	
	return (x);
}

static int	is_flag(t_block *blk, char c)
{
	if (!ft_strchr("#+-0 ", c))
		return (0);
	blk->alt_form == 1 || c == '#' ? blk->alt_form = true : false;
	blk->sign == 1 || c == '+' ? blk->sign = true : false;
	blk->left_align == 1 || c == '-' ? blk->left_align = true : false;
	blk->prepend_zero == 1 || c == '0' ? blk->prepend_zero = true : false;
//	c == '0' ? blk->prepend_zero = true : false;
//	printf("pre zero: %d\n", blk->prepend_zero);
	blk->prepend_space == 1 || c == ' ' ? blk->prepend_space = true : false;
	return (1);
}

static void	valid_flag(t_block *blk)
{
	blk->sign == 1 ? blk->prepend_space = false : 0;
	blk->precision > 0 ? blk->prepend_zero = false : 0;
//	printf("valid precision: %d\n", blk->precision);
//	printf("valid zero: %d\n", blk->prepend_zero);
}


static int	specifier(t_block *blk, char c)//work, 1: why static 2.can combine?
{

	if ((c == 's' || c == 'S'|| c == 'p' || c == 'd' || c == 'D' || c == 'i' 
		 || c == 'o' || c == 'O' || c == 'u' || c == 'U'|| c == 'x' || c == 'X'
		 || c == 'c' || c == 'C'
		 //|| c == '%' || c == 'n' || c == 'e' || c == 'g' || c == 'G'
		 ) && (blk->specifier = c))
		return (1);
	printf("invalid directive from spe: %c\n", c);//not valid char
	return (0);
}

void	grab_flag(t_block *blk, char *blk_fmt, int *i)
{
	while (blk_fmt[++*i] && !ft_strchr("sSpdDioOuUxXcC%", blk_fmt[*i]))
	{
		//printf("%c\n", blk_fmt[*i]);
		if (is_flag(blk, blk_fmt[*i]));//better to check it one by one
		else if (blk_fmt[*i] == '.')//check it in chunk
			*i += precision(blk, blk_fmt + *i + 1);
		else if (!blk->width && ft_isdigit(blk_fmt[*i]))
			*i += width(blk, blk_fmt + *i);
		else if (ft_strchr("hlzj", (blk_fmt[*i])))
			*i += length(blk, blk_fmt + *i);
		//Color
//		else
		//		printf("invalid directive from flag: %c\n", blk_fmt[*i]);//not valid char
	}
//	printf("out zero: %d\n", blk->prepend_zero);
	valid_flag(blk);
	specifier(blk, blk_fmt[*i]);
//	printf("\n#+-0 :\n%d%d%d%d%d\n", blk->alt_form, blk->sign, blk->left_align, blk->prepend_zero, blk->prepend_space);
}
