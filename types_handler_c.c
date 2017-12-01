/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_handler_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:37:41 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/25 23:06:03 by dmontoya         ###   ########.fr       */
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

void	wchar_type(va_list ap, t_pf *data)
{
	int			width;
	wchar_t		c;
	char		*str;

	c = va_arg(ap, wchar_t);
	str = ft_strnew(ft_wcharlen(c));
	ft_unicode_conv(c, str);
	width = data->flags[3] - 1;
	if (width > 0)
		ifield_width(width, str, data, 'C');
	else
	{
		if (c == 0)
		{
			data->len++;
			ft_putchar('\0');
		}
		else
		{
			data->len += ft_strlen(str);
			ft_putstr(str);
		}
	}
	free(str);
}
