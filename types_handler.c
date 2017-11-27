/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:02:38 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/25 21:31:42 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	percent_type(t_pf *data)
{
	char	*p;
	int		width;

	p = "1";
	undet_behavior(data, &p, '%');
	width = data->flags[3] - 1;
	if (width > 0)
		data->len += data->flags[3];
	else
		data->len += 1;
	if (data->flags[2] >= 45)
		ft_putchar('%');
	min_width(data, width);
	if (data->flags[2] < 45)
		ft_putchar('%');
}

void	c_type(va_list ap, t_pf *data, char w)
{
	unsigned char	c;
	int				width;

	width = data->flags[3] - 1;
	if (w == 'C' || (data->mod[0] == 'l' && w == 'c'))
		return (wchar_type(ap, data));
	if (width > 0)
		data->len += data->flags[3];
	else
		data->len += 1;
	if (w != 'Z')
		c = va_arg(ap, int);
	else
		c = w;
	if (data->flags[2] >= 45)
		ft_putchar(c);
	min_width(data, width);
	if (data->flags[2] < 45)
		ft_putchar(c);
}

void	di_type(va_list ap, t_pf *data)
{
	int		width;
	char	*res;
	int		len;

	res = ft_imaxtoa(sint_modifiers(ap, data));
	undet_behavior(data, &res, 'd');
	len = ft_strlen(res);
	if (data->flags[5] >= len)
		res = precision_adjust(res, data, len);
	if (res[0] != '-' && data->flags[7] == 1)
		res = ft_strjoin(" ", res);
	width = data->flags[3] - ft_strlen(res);
	if (width > 0)
		ifield_width(width, res, data, 'd');
	else
	{
		if (data->flags[1] != 1 && data->flags[2] == 43 && res[0] != '-')
		{
			data->len += 1;
			ft_putchar('+');
		}
		ft_putstr(res);
		data->len += ft_strlen(res);
	}
	free(res);
}

void	u_type(va_list ap, t_pf *data)
{
	int		width;
	char	*res;
	int		len;

	res = ft_uimaxtoa(uint_modifiers(ap, data));
	len = ft_strlen(res);
	if (data->flags[5] > len)
		res = precision_adjust(res, data, len);
	width = data->flags[3] - ft_strlen(res);
	if (width > 0)
		ufield_width(width, res, data, 'u');
	else
	{
		data->len += ft_strlen(res);
		ft_putstr(res);
	}
	free(res);
}

void	number_type(char w, va_list ap, t_pf *data)
{
	if (w == 'd' || w == 'i' || w == 'D')
		di_type(ap, data);
	else if (w == 'c' || w == 'C' || w == 'Z')
		c_type(ap, data, w);
	else if (w == 'u' || w == 'U')
		u_type(ap, data);
}
