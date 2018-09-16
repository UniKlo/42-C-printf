/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 11:19:19 by khou              #+#    #+#             */
/*   Updated: 2018/09/16 02:43:28 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
//#define TEST1 "pr: {%.5d} {%5.0d} {%.d} {%5.d}\n", 0, 0, 0, 0
//#define TEST2 "ft: {%.5d} {%5.0d} {%.d} {%5.d}\n", 0, 0, 0, 0

//#define TEST1 "pr: {%+10.5d}\n", 4242
//#define TEST2 "ft: {%+10.5d}\n", 4242
#define TEST1 "pr: {%u}\n", -1
#define TEST2 "ft: {%u}\n", -1

int	main(int argc, char **argv)
{
//printf(TEST1);
	printf("ret: %d\n", printf(TEST1));
//ft_printf(TEST2);
	printf("ft_: %d\n", ft_printf(TEST2));
	return (0);
}
