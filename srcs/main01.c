/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 11:19:19 by khou              #+#    #+#             */
/*   Updated: 2018/09/18 10:15:28 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
//#define TEST1 "pr: {%+d} {%+.d}\n",  0,0
//#define TEST2 "ft: {%+d} {%+.d}\n",  0,0

#define TEST1 "pr: {%s}\n", NULL 
#define TEST2 "ft: {%s}\n", NULL

//#define TEST1 "pr: {%#o}\n", 0
//#define TEST2 "ft: {%#o}\n", 0

//#define TEST1 "pr: {%s}\n", "this"
//#define TEST2 "ft: {%s}\n", "this"

//#define TEST1 "pr: {%5.2s}\n", ""
//#define TEST2 "ft: {%5.2s}\n", ""



int	main(int argc, char **argv)
{
//printf(TEST1);
	printf("ret: %d\n", printf(TEST1));
//ft_printf(TEST2);
	printf("ft_: %d\n", ft_printf(TEST2));
	return (0);
}
