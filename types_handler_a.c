/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_handler_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:51:43 by dmontoya          #+#    #+#             */
/*   Updated: 2017/12/01 18:04:38 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		swchar_precision(t_pf *data, wchar_t *wstr)
{
	size_t	precision;
	int		i;

	i = 0;
	precision = 0;
	while (i < data->flags[5])
		precision = precision + ft_wcharlen(wstr[i++]);
	data->flags[5] = precision;
}

void		swchar_type(va_list ap, t_pf *data)
{
	int		width;
	char	*res;
	wchar_t	*wstr;

	data->type = 's';
	if (!(wstr = va_arg(ap, wchar_t *)))
	{
		data->len += 6;
		return (ft_putstr("(null)"));
	}
	res = ft_strnew(ft_wcstrlen(wstr));
	wstrtostr(wstr, res);
	undet_behavior(data, &res);
	swchar_precision(data, wstr);
	if ((data->flags[5] < (int)ft_strlen(res)) && data->flags[6] == 1)
		res = ft_strsub(res, 0, data->flags[5]);
	width = data->flags[3] - ft_strlen(res);
	if (width > 0)
		ufield_width(width, res, data, 'S');
	else
	{
		data->len += ft_strlen(res);
		ft_putstr(res);
	}
	free(res);
}

void		s_type(va_list ap, t_pf *data)
{
	char	*str;
	int		width;
	char	*tmp;

	if ((data->mod[0] == 'l' && data->type == 's') || data->type == 'S')
		return (swchar_type(ap, data));
	str = va_arg(ap, char *);
	tmp = str;
	if (str == NULL)
		str = ft_strdup("(null)");
	undet_behavior(data, &str);
	if (data->flags[5] > 0 && data->flags[5] < (int)ft_strlen(str))
		str = ft_strsub(str, 0, data->flags[5]);
	width = data->flags[3] - ft_strlen(str);
	if (width > 0)
		ufield_width(width, str, data, 's');
	else
	{
		ft_putstr(str);
		data->len += ft_strlen(str);
	}
	if (tmp == NULL || ft_strcmp(str, tmp) != 0)
		free(str);
}

void		p_type(va_list ap, t_pf *data)
{
	char	*str;
	int		width;

	str = uitoa_base((uintmax_t)va_arg(ap, void *), 16);
	width = data->flags[3] - ft_strlen(str) - 2;
	undet_behavior(data, &str);
	if (data->flags[5] > 0 && data->flags[5] > (int)ft_strlen(str))
		str = precision_adjust(str, data, ft_strlen(str));
	if (width > 0)
		pointer_width(width, str, data);
	else
	{
		data->len += ft_strlen(str) + 2;
		ft_putstr("0x");
		if (str != 0)
			ft_putstr(str);
	}
	if (str == 0)
		data->len--;
	free(str);
}
