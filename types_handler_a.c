/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_handler_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:51:43 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/27 20:30:02 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		wstrtostr(wchar_t *wstr, char *str)
{
	size_t	i;
	size_t	pos;

	i = 0;
	pos = 0;
	while (wstr[i])
	{
		ft_unicode_conv(wstr[i], str + pos);
		pos = pos + ft_wcharlen(wstr[++i]);
	}
}

void		swchar_precision(t_pf *data, wchar_t *wstr)
{
	size_t	precision;
	int		i;

	i = 0;
	precision = 0;
	while (i < data->flags[5])
		precision = precision + ft_wcharlen(wstr[i++]);
	data->flags[5] = precision;
	ft_putnbr(precision);
}

void		swchar_type(va_list ap, t_pf *data)
{
	int		width;
	char	*res;
	wchar_t	*wstr;

	wstr = va_arg(ap, wchar_t *);
	if (wstr == NULL)
	{
		data->len += 6;
		return(ft_putstr("(null)"));
	}
//	if (data->flags[5] > 0)
//		swchar_precision(data, wstr);
	res = ft_strnew(ft_wcstrlen(wstr));
	wstrtostr(wstr, res);
	if (ft_strcmp(res, "(null)") == 0)
	{
		data->len += 6;
		return(ft_putstr("(null)"));
	}
	undet_behavior(data, &res);
	if (data->flags[5] < (int)ft_strlen(res))
		res = ft_strsub(res, 0, data->flags[5]);
	width = data->flags[3] - ft_strlen(res);
	if (width > 0)
		data->len += data->flags[3];
	else
		data->len += ft_strlen(res); //wcstrlen o strlen
	if (width > 0)
		min_width(data, width, res);
	else
		ft_putstr(res);
	free(res);
}

void		determinestrlen(t_pf *data, int width, char *str)
{
	if (width > 0)
		data->len += data->flags[3];
	else
		data->len += ft_strlen(str);
}

void		s_type(va_list ap, t_pf *data, char w)
{
	char	*str;
	int		width;
	int		tmp;

	tmp = 0;
	if ((data->mod[0] == 'l' && w == 's') || w == 'S')
		return (swchar_type(ap, data));
	str = va_arg(ap, char *);
	if (str == NULL)
		if (tmp++ == 0)
			str = ft_strdup("(null)");
	undet_behavior(data, &str);
	if (data->flags[5] > 0 && data->flags[5] < (int)ft_strlen(str))
		if (tmp++ >= 0)
			str = ft_strsub(str, 0, data->flags[5]);
	width = data->flags[3] - ft_strlen(str);
	determinestrlen(data, width, str);
	if ((data->flags[2] >= 45))
		ft_putstr(str);
	min_width(data, width, str);
	if ((data->flags[2] < 45))
		ft_putstr(str);
	if (tmp > 0)
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
		data->len += data->flags[3];
	else
		data->len += ft_strlen(str) + 2;
	if (data->flags[2] >= 45)
	{
		ft_putstr("0x");
		if (str != 0)
			ft_putstr(str);
	}
	while (width-- > 0)
		ft_putchar(' ');
	if (data->flags[2] < 45)
	{
		ft_putstr("0x");
		if (str != 0)
			ft_putstr(str);
	}
	if (str == 0)
		data->len--;
	free(str);
}
