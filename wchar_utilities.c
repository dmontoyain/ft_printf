/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:52:59 by dmontoya          #+#    #+#             */
/*   Updated: 2017/12/01 17:46:37 by dmontoya         ###   ########.fr       */
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

void	wstrtostr(wchar_t *wstr, char *str)
{
	size_t	i;
	size_t	pos;

	i = 0;
	pos = 0;
	while (wstr[i])
	{
		ft_unicode_conv(wstr[i], str + pos);
		pos = pos + ft_wcharlen(wstr[i++]);
	}
}
