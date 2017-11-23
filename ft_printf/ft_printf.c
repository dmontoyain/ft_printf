/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:50:50 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/22 13:34:46 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
  #include <wchar.h>

int	check_type(const char *restrict s, size_t i, va_list ap, int *flags)
{
	char *mods;

	mods = ft_strnew(2);
	if (i >= 2)
	{
		mods[0] = s[i - 2];
		mods[1] = s[i - 1];
	}
	if (s[i] == '%')
		ft_putchar('%');
	else if (s[i] == 's' || s[i] == 'S')
		s_type(ap, flags, mods, s[i]);
	else if (s[i] == 'd' || s[i] == 'u' || s[i] == 'i' || s[i] == 'D' || s[i] == 'U')
		number_type(mods, s[i], ap, flags);
	else if (s[i] == 'c' || s[i] == 'C')
		number_type(mods, s[i], ap, flags);
	else if (s[i] == 'o' || s[i] == 'x' || s[i] == 'X' || s[i] == 'b' || s[i] == 'O')
		Xox_type(ap, flags, mods, s[i]);
	else if (s[i] == 'p')
		p_type(ap, flags);
	ft_strdel(&mods);
	return (0);
}

int		search_end(const char *restrict s, int i)
{
	while (s[i] != 'c' && s[i] != 'd' && s[i] != 's' && s[i] != 'D'
			&& s[i] != 'S' && s[i] != 'C' && s[i] != 'x' && s[i] != 'X'
			&& s[i] != 'p' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u'
			&& s[i] != 'U' && s[i] != 'O' && s[i] != '\0' && s[i] != 'b')
				i++;
	return (i);
}

int		check_flags(const char * restrict s, int flag, int *flags)
{
	int end;

	empty_flagarray(flags);
	if((end = search_end(s, flag)) == flag)
		return (0);
	flags[0] = end;
	flags[1] = zero_flag(s, flag, end);
	flags[2] = minusplus_flag(s, flag, end);
	flags[3] = width_flag(s, flag, end);
	flags[4] = hash_flag(s, flag, end);
	flags[5] = precision_flag(s, flag, end);
	return (1);
}

int		checkstring(const char * restrict s, size_t i)
{
	size_t j;
	char *tmp;

	j = i;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && i == j)
			return (++i);
		if ((s[i] == '%' && i > j) || s[i + 1] == '\0')
		{
			if (s[i + 1] == '\0')
				i++;
			tmp = ft_strsub(s, j, i - j);
			ft_putstr(tmp);
			ft_strdel(&tmp);
			return (++i);
		}
		i++;
	}
	return (0);
}

int ft_printf(const char * restrict format, ...)
{
	size_t i;
	size_t len;
	int flags[6];
	va_list ap;

	i = -1;
	va_start(ap, format);
	len = ft_strlen((char *) format);
	while (++i < len)
		if (((i = checkstring(format, i)) > 0) && i < len)
		{
			if (check_flags(format, i, flags) != 0)
				i = flags[0];
			check_type(format, i, ap, flags);
		}
	va_end(ap);
	return (0);
}
/*
int main()
{
	//char *str2 = "cumswallower";
//	wchar_t *str = L"hola";

//wchar_t w = 0;
//	char *str2 = "hola";
//	ft_putnbr(sizeof(str2));
//	ft_putnbr(sizeof(w));
//	int i = 565;
//	wchar_t *hex =  L"hola";
	wchar_t str = L'ᴚ';
	//int hex2 = 1112066;
//	printf("%#X", 1 << 21);
//	ft_putnbr(wcslen(str));
//	ft_putnbr(ft_wstrlen(str));
//	ft_putstr("\n");
//	ft_putchar(sizeof(hex2));
//	char c = 'o';
	ft_printf("%b\n", str);
//	ft_printf("int: %lu, this is a dstring: %s\n", hex, str);
//	ft_printf("int: %b,\x1b[35m this is a \x1b[32m string: %15s, i love \x1b[33meveryone\n", hex, str2);
	printf("%x\n", str);
	//ft_printf("%C", hex);
//	printf("%c, %ls", w, str);
	return (0);
}

*/



