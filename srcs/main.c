/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 11:19:19 by khou              #+#    #+#             */
/*   Updated: 2018/08/29 02:34:02 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

int		main()
{
//	char	*format;

//	format = "String";
	printf("REAL printf\n/*\n");
	printf("number: %d", 5);
	printf("\n*/\n");
    printf("MY ft_printf\n/*\n");
	ft_printf("AB%C\n");
    printf("\n*/\n");
	return (0);
}
