/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:50:50 by dmontoya          #+#    #+#             */
/*   Updated: 2017/12/01 18:02:31 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		check_type(char t, va_list ap, t_pf *data)
{
	t = check_hmod(data, t);
	data->type = t;
	if (t == '%')
		percent_type(data);
	else if (t == 's' || t == 'S')
		s_type(ap, data);
	else if (t == 'd' || t == 'i' || t == 'D')
		di_type(ap, data);
	else if (t == 'u' || t == 'U')
		u_type(ap, data);
	else if (t == 'c' || t == 'C' || t == 'Z')
		c_type(ap, data);
	else if (t == 'o' || t == 'x' || t == 'X' || t == 'O')
		ox_type(ap, data);
	else if (t == 'b')
		b_type(ap, data);
	else if (t == 'p')
		p_type(ap, data);
	else if (t == 'f' || t == 'F')
		f_type(ap, data);
	else if (t != '\0')
		invalid_end(data);
}

size_t		fontcolor(const char *restrict s, size_t i, size_t j, t_pf *data)
{
	char	*tmp;
	int		x;
	int		start;

	x = 0;
	start = i;
	if (i > j)
	{
		ft_putstr(tmp = ft_strsub(s, j, i - j));
		data->len += ft_strlen(tmp);
		free(tmp);
	}
	tmp = (char *)malloc(sizeof(char) * 10);
	while (s[++i] != '}' && s[i] != '%')
		tmp[x++] = s[i];
	tmp[x] = '\0';
	put_color(tmp);
	free(tmp);
	if (s[i] == '}')
		return (++i);
	return (start);
}

int			checkstring(const char *restrict s, size_t i, t_pf *data)
{
	size_t	j;
	char	*tmp;

	j = i;
	while (s[i] != '\0')
	{
		if (s[i] == '{')
		{
			i = fontcolor(s, i, j, data);
			j = i;
		}
		if ((s[i] == '%') || s[i + 1] == '\0')
		{
			if (s[i + 1] == '\0' && s[i] != '%')
				i++;
			tmp = ft_strsub(s, j, i - j);
			data->len += ft_strlen(tmp);
			ft_putstr(tmp);
			ft_strdel(&tmp);
			return (++i);
		}
		i++;
	}
	return (0);
}

int			check_flags(const char *restrict s, int flag, t_pf *data)
{
	int end;

	if ((end = search_end(s, flag, 0)) == flag)
		return (0);
	if (s[end] == '\0')
		end = search_end(s, flag, 1);
	modifiers(s, flag, end, data);
	data->flags[1] = zero_flag(s, flag, end);
	data->flags[2] = minusplus_flag(s, flag, end);
	data->flags[3] = width_flag(s, flag, end);
	data->flags[4] = hash_flag(s, flag, end);
	data->flags[5] = precision_flag(s, flag, end, 0);
	data->flags[6] = precision_flag(s, flag, end, 1);
	data->flags[0] = end;
	if (s[end] == 'd' || s[end] == 'i' || s[end] == 'D')
		data->flags[7] = blank_space(s, flag, end);
	return (1);
}

int			ft_printf(const char *restrict format, ...)
{
	size_t	i;
	size_t	len;
	t_pf	*data;
	va_list	ap;

	i = -1;
	data = (t_pf*)malloc(25 * sizeof(t_pf));
	data->len = 0;
	va_start(ap, format);
	len = ft_strlen((char *)format);
	while (++i < len)
		if (((i = checkstring(format, i, data)) > 0) && i < len)
		{
			restart_modsflags(data);
			if (check_flags(format, i, data) != 0)
				i = data->flags[0];
			check_type(format[i], ap, data);
		}
	i = data->len;
	va_end(ap);
	free(data);
	return (i);
}
