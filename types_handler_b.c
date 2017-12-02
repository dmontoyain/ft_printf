/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_handler_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:10:43 by dmontoya          #+#    #+#             */
/*   Updated: 2017/12/01 21:18:02 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ox_type(va_list ap, t_pf *a)
{
	int		width;
	int		len;
	char	*res;

	width = 0;
	res = uitoa_base(uint_modifiers(ap, a), getbase(a->type));
	if (a->type == 'X')
		str_touppercase(res);
	undet_behavior(a, &res);
	if (a->flags[5] >= (len = ft_strlen(res)))
		res = precision_adjust(res, a, len);
	len = ft_strlen(res);
	if ((width = a->flags[3] - len) > 0)
		ufield_width(width, res, a, a->type);
	else
	{
		if (a->flags[4] != 0 &&
			(ft_atoi(res) > 0 || a->type == 'o' || a->type == 'O'))
			prefixtype(a->type);
		ft_putstr(res);
		a->len += len + a->flags[4];
	}
	free(res);
}

void	b_type(va_list ap, t_pf *data)
{
	int		width;
	int		len;
	char	*b;

	b = itoa_base(sint_modifiers(ap, data), 2);
	len = ft_strlen(b);
	if (data->flags[5] > len)
		b = precision_adjust(b, data, len);
	width = data->flags[3] - ft_strlen(b) - data->flags[4];
	if (width > 0)
		ufield_width(width, b, data, 'b');
	else
	{
		data->len = ft_strlen(b);
		ft_putstr(b);
	}
	free(b);
}
