/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 00:11:25 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/22 00:12:11 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wcharlen(wchar_t c)
{
	int len;
	unsigned int ud;
	
	ud = (unsigned int)c;

	if (ud <= 127)
		len = 1;
	else if (ud <= 2047)
		len = 2;
	else if (ud <= 65535)
		len = 3;
	else
		len = 4;
/*	if (c < 0x7F)
		len = 1;
	else if (c < 0x7FF)
		len = 2;
	else if (c < 0xFFFF)
		len = 3;
	else if (c < 0x10FFFF)
		len = 4;
	else
		len = 0;*/
	return (len);
}
