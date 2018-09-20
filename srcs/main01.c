/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 11:19:19 by khou              #+#    #+#             */
/*   Updated: 2018/09/20 11:07:03 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
//#define TEST1 "pr: {%+d} {%+.d}\n",  0,0
//#define TEST2 "ft: {%+d} {%+.d}\n",  0,0

wchar_t 	*a = "ææç";

//#define TEST1 "pr: {%S}\n", a 
//#define TEST2 "ft: {%S}\n", a

//#define TEST1 "pr: {%-5lu}\n", (unsigned long)-20
//#define TEST2 "ft: {%-5lu}\n", (unsigned long)-20

//#define TEST1 "pr: {%%  %}\n", "this"
//#define TEST2 "ft: {%%  %}\n", "this"

#define TEST1 "pr: {%zX, %zX}", 0, ULLONG_MAX)
#define TEST2 "ft: {%zX, %zX}", 0, ULLONG_MAX)



int	main(int argc, char **argv)
{
//printf(TEST1);
	printf("ret: %d\n", printf(TEST1));
//ft_printf(TEST2);
	printf("ft_: %d\n", ft_printf(TEST2));
	return (0);
}
