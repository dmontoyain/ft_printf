/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:02:38 by dmontoya          #+#    #+#             */
/*   Updated: 2017/12/01 17:45:36 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	percent_type(t_pf *data)
{
	char	*p;
	int		width;

	p = "1";
	undet_behavior(data, &p);
	width = data->flags[3] - 1;
	if (width > 0)
		data->len += data->flags[3];
	else
		data->len += 1;
	if (data->flags[2] >= 45)
		ft_putchar('%');
	min_width(data, width, p);
	if (data->flags[2] < 45)
		ft_putchar('%');
}

void	wchar_type(va_list ap, t_pf *data)
{
	int			width;
	wchar_t		c;
	char		*res;

	data->type = 'C';
	c = va_arg(ap, wchar_t);
	ft_unicode_conv(c, (res = ft_strnew(ft_wcharlen(c))));
	undet_behavior(data, &res);
	width = data->flags[3] - 1;
	if (width > 0)
		ufield_width(width, res, data, 'C');
	else
	{
		if (c == 0)
		{
			ft_putchar('\0');
			data->len++;
		}
		else
		{
			data->len += ft_strlen(res);
			ft_putstr(res);
		}
	}
	free(res);
}

void	c_type(va_list ap, t_pf *data)
{
	unsigned char	c;
	int				width;

	width = data->flags[3] - 1;
	if (data->type == 'C' || (data->mod[0] == 'l' && data->type == 'c'))
		return (wchar_type(ap, data));
	if (width > 0)
		data->len += data->flags[3];
	else
		data->len += 1;
	if (data->type != 'Z')
		c = va_arg(ap, int);
	else
		c = data->type;
	if (data->flags[2] >= 45)
		ft_putchar(c);
	min_width(data, width, &data->type);
	if (data->flags[2] < 45)
		ft_putchar(c);
}

void	di_type(va_list ap, t_pf *data)
{
	int		width;
	int		len;
	char	*res;

	res = ft_imaxtoa(sint_modifiers(ap, data));
	undet_behavior(data, &res);
	if (data->flags[5] >= (len = ft_strlen(res)))
		res = precision_adjust(res, data, len);
	if (res[0] != '-' && data->flags[7] == 1 && data->flags[2] >= 45)
		res = ft_strjoin(" ", res);
	if ((width = data->flags[3] - ft_strlen(res)) > 0)
		ifield_width(width, res, data, 'd');
	else
	{
		if (res[0] != '-' && data->flags[7] == 1)
			res = ft_strjoin(" ", res);
		if (data->flags[2] == 43 && res[0] != '-')
		{
			data->len++;
			ft_putchar('+');
		}
		ft_putstr(res);
		data->len += ft_strlen(res);
	}
	free(res);
}

void	u_type(va_list ap, t_pf *d)
{
	int		width;
	char	*res;
	int		len;

	res = ft_uimaxtoa(uint_modifiers(ap, d));
	len = ft_strlen(res);
	if (d->flags[5] > len)
		res = precision_adjust(res, d, len);
	undet_behavior(d, &res);
	if (d->flags[7] == 1 && d->flags[2] >= 45)
		res = ft_strjoin(" ", res);
	width = d->flags[3] - ft_strlen(res);
	if (width > 0)
		ufield_width(width, res, d, 'u');
	else
	{
		if (d->flags[7] == 1)
			res = ft_strjoin(" ", res);
		d->len += ft_strlen(res);
		ft_putstr(res);
	}
	free(res);
}
