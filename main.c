/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:37:27 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/27 15:08:20 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"
#include <stdio.h>

int main()
{
	//char *str2 = NULL;
	//wchar_t *str = L"hola";

	//wchar_t w = 0;
	//char *str2 = "hola";
	//ft_putnbr(sizeof(str2));
	//ft_putnbr(sizeof(w));
	int i;
	int j;
	//wchar_t *hex =  L"hola";
	//wchar_t str = L'ᴚ';
	//int hex2 = 1112066;
	//printf("%#X", 1 << 21);
	//ft_putnbr(wcslen(str));
	//ft_putnbr(ft_wstrlen(str));
	//ft_putstr("\n");
	//ft_putchar(sizeof(hex2));
	//char c = 'o';
	i = ft_printf("my printf: %.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	j = printf("ur printf: %.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("my: %d\n", i);
	printf("ur: %d", j);
//	printf("@moulitest: %e\n", -42.8);
	//ft_printf("int: %b,\x1b[35m this is a \x1b[32m string: %15s, i love \x1b[33meveryone\n", hex, str2);
//	ft_putnbr(printf("%%%\n"));
//	ft_putnbr(i);
	//ft_printf("%C", hex);
	//printf("%c, %ls", w, str);
	return (0);
}
