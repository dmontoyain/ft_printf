/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_handler_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:37:41 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/20 14:37:42 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_unicode_conv(wchar_t c, char *str)
{
	if (c <= 0x7F)
				str[0] = (unsigned char)c;
	else if (c <= 0x7FF)
	{
		str[0] = (unsigned char)((c >> 6) | 0xC0);
		str[1] = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c <= 0xFFFF)
	{
		str[0] = (unsigned char)(((c >> 12)) | 0xE0);
		str[1] = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		str[2] = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		str[0] = (unsigned char)(((c >> 18)) | 0xF0);
		str[1] = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
		str[2] = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		str[3] = (unsigned char)((c & 0x3F) | 0x80);
	}
}

void    wchar_type(va_list ap, int *flags)
{
    int width;
	wchar_t c;
	char *str;

	c = va_arg(ap, wchar_t);
	str = ft_strnew(ft_wcharlen(c));
	width = flags[3] - 1;
	if (width > 0)
		ifield_width(width, str, flags, 'C');
	else
		ft_putstr(str);
}