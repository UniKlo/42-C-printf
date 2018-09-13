/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 11:19:19 by khou              #+#    #+#             */
/*   Updated: 2018/09/12 21:41:29 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#define TEST1 "pr: {%-+4.4lld}\n", (long long int)1000
#define TEST2 "ft: {%-+4.4lld}\n", (long long int)1000

int		main(int argc, char **argv)
{
	printf(TEST1);
	ft_printf(TEST2);
 	return (0);
}
