/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 11:19:19 by khou              #+#    #+#             */
/*   Updated: 2018/09/18 00:01:06 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
//#define TEST1 "pr: {%5.0d} {%5.d}\n",  0, 0
//#define TEST2 "ft: {%5.0d} {%5.d}\n",  0, 0

/* #define TEST1 "pr: {%s}\n", NULL */
/* #define TEST2 "ft: {%s}\n", NULL */

/* #define TEST1 "pr: {%p}\n", 42 */
/* #define TEST2 "ft: {%p}\n", 42 */

//#define TEST1 "pr: {%s}\n", "this"
//#define TEST2 "ft: {%s}\n", "this"

#define TEST1 "pr: {%-.2s}\n", "this is a string"
#define TEST2 "ft: {%-.2s}\n", "this is a string"



int	main(int argc, char **argv)
{
//printf(TEST1);
	printf("ret: %d\n", printf(TEST1));
//ft_printf(TEST2);
	printf("ft_: %d\n", ft_printf(TEST2));
	return (0);
}
