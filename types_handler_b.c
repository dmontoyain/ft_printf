/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_handler_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:10:43 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/25 22:30:59 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ox_type(va_list ap, t_pf *data, char w)
{
	int		width;
	char	*res;
	int		len;

	width = 0;
	if ((w == 'x' || w == 'X') && data->flags[4] == 1)
		data->flags[4] = 2;
	res = uitoa_base(uint_modifiers(ap, data), getbase(w));
	undet_behavior(data, &res);
	if (w == 'X')
		str_touppercase(res);
	if (data->flags[5] >= (len = ft_strlen(res)))
		res = precision_adjust(res, data, len);
	width = data->flags[3] - ft_strlen(res);
	if (width > 0)
		ufield_width(width, res, data, w);
	else
	{
		if (data->flags[4] != 0 && (ft_atoi(res) > 0 || w == 'o' || w == 'O'))
			prefixtype(w);
		ft_putstr(res);
		data->len += ft_strlen(res) + data->flags[4];
	}
	free(res);
}

void	b_type(va_list ap, t_pf *data)
{
	int		width;
	char	*b;
	int		len;

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
