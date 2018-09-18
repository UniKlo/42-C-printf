/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 11:19:19 by khou              #+#    #+#             */
/*   Updated: 2018/09/17 17:47:42 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
//#define TEST1 "pr: {%5.0d} {%5.d}\n",  0, 0
//#define TEST2 "ft: {%5.0d} {%5.d}\n",  0, 0

//#define TEST1 "pr: {%#-5x}\n", -100
//#define TEST2 "ft: {%#-5x}\n", -100

#define TEST1 "pr: {%c}\n", 0
#define TEST2 "ft: {%c}\n", 0

int	main(int argc, char **argv)
{
//printf(TEST1);
	printf("ret: %d\n", printf(TEST1));
//ft_printf(TEST2);
	printf("ft_: %d\n", ft_printf(TEST2));
	return (0);
}
