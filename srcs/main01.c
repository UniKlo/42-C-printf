/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 11:19:19 by khou              #+#    #+#             */
/*   Updated: 2018/09/15 14:39:59 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#define TEST1 "pr: {%03.2d}\n", 0
#define TEST2 "ft: {%03.2d}\n", 0

//#define TEST1 "pr: {%+10.5d}\n", 4242
//#define TEST2 "ft: {%+10.5d}\n", 4242
//#define TEST1 "pr: {%+d}\n", 0
//#define TEST2 "ft: {%+d}\n", 0

int	main(int argc, char **argv)
{
//printf(TEST1);
	printf("ret: %d\n", printf(TEST1));
//ft_printf(TEST2);
	printf("ft_: %d\n", ft_printf(TEST2));
	return (0);
}
