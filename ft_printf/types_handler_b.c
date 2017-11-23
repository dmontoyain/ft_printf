/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_handler_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:10:43 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/16 22:10:51 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	Xox_type(va_list ap, int *flags, char *mod, char w)
{
	int width;
	char *res;
	int len;

	width = 0;
	if ((w == 'x' || w == 'X') && flags[4] == 1)
		flags[4] = 2;
	res = uitoa_base(uint_modifiers(mod, ap), getbase(w));
	if (w == 'X')
		smtouppercase(res);
	len = ft_strlen(res);
	if (flags[5] > len)
		res = precision_adjust(res, flags[5] - len);
	width = flags[3] - ft_strlen(res) - flags[4];
	if (width > 0)
		ufield_width(width, res, flags, w);
	else
	{
		if (flags[4] != 0)
			prefixtype(w);
		ft_putstr(res);
	}
	free(res);
}//fail when int: %#.15o only octal aparentemente

void	b_type(va_list ap, int *flags, char *mod)
{
	int width;
	char *b;
	int len;

	b = imtoa_base(sint_modifiers(mod, ap), 2);
	len = ft_strlen(b);
	if (flags[5] > len)
		b = precision_adjust(b, flags[5] - len);
	width = flags[3] - ft_strlen(b) - flags[4];
	if (width > 0)
		ufield_width(width, b, flags, 'b');
	else
		ft_putstr(b);
	free(b);
}