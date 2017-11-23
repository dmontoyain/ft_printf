/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_handler_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:51:43 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/16 21:51:47 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void		wstrtostr(wchar_t *wstr, char *str)
{
	size_t	i;
	size_t	pos;

	i = -1;
	pos = 0;
	while (wstr[++i])
	{
		ft_unicode_conv(wstr[i], str + pos);
		pos = pos + ft_wcharlen(wstr[i]);
	}
}

void	swchar_type(va_list ap, int *flags)
{
	int width;
	char *res;
	wchar_t *wstr;

	wstr = va_arg(ap, wchar_t *);
	res = ft_strnew(ft_wcstrlen(wstr));
	wstrtostr(wstr, res);
	width = flags[3] - ft_strlen(res);
	if (width > 0)
		ifield_width(width, res, flags, 'S');
	else
		ft_putstr(res);
}

void	s_type(va_list ap, int *flags, char *mods, char w)
{
	char *str;
	int width;

	if ((mods[1] == 'l' && w == 's') || w == 'S')
		return (swchar_type(ap, flags));
	str = va_arg(ap, char *);
	width = flags[3] - ft_strlen(str);
	if ((flags[2] == 88 || flags[2] == 45))
		ft_putstr(str);
	while (width-- > 0)
			ft_putchar(' ');
	if ((flags[2] != 88 || flags[2] != 45))
		ft_putstr(str);
}

void	p_type(va_list ap, int *flags)
{
	char *str;
	int width;

	str = uitoa_base((uintmax_t)va_arg(ap, void *), 16);
	width = flags[3] - ft_strlen(str) - 2;
	if ((flags[2] == 88 || flags[2] == 45))
	{
		ft_putstr("0x");
		ft_putstr(str);
	}
	while (width-- > 0)
			ft_putchar(' ');
	if ((flags[2] != 88 && flags[2] != 45))
	{
		ft_putstr("0x");
		ft_putstr(str);
	}
}