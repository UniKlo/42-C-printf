/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 11:19:19 by khou              #+#    #+#             */
/*   Updated: 2018/09/12 22:27:20 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#define TEST1 "pr: {%d}\n", -1000
#define TEST2 "ft: {%d}\n", -1000

int		main(int argc, char **argv)
{
//	printf(TEST1);
	printf("ret: %d\n", printf(TEST1));
//	ft_printf(TEST2);
	printf("ft_: %d\n", ft_printf(TEST2));
 	return (0);
}
