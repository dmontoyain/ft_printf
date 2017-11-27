/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:50:50 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/25 23:32:36 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		check_type(const char *restrict s, size_t i, va_list ap, t_pf *data)
{
	char	t;

	t = s[i];
	data->type = s[i];
	t = check_hmod(data, (char)s[i]);
	if (t == '%')
		percent_type(data);
	else if (t == 's' || t == 'S')
		s_type(ap, data, t);
	else if (t == 'd' || t == 'u' || t == 'i' || t == 'D' || t == 'U')
		number_type(t, ap, data);
	else if (t == 'c' || t == 'C' || t == 'Z')
		number_type(t, ap, data);
	else if (t == 'o' || t == 'x' || t == 'X' || t == 'O')
		ox_type(ap, data, t);
	else if (t == 'b')
		b_type(ap, data);
	else if (t == 'p')
		p_type(ap, data);
	return (0);
}

int		checkstring(const char *restrict s, size_t i, t_pf *data)
{
	size_t	j;
	char	*tmp;

	j = i;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && i == j)
			return (++i);
		if ((s[i] == '%' && i > j) || s[i + 1] == '\0')
		{
			if (s[i + 1] == '\0' && s[i] != '%')
				i++;
			tmp = ft_strsub(s, j, i - j);
			ft_putstr(tmp);
			data->len += ft_strlen(tmp);
			ft_strdel(&tmp);
			return (++i);
		}
		i++;
	}
	return (0);
}

int		check_flags(const char *restrict s, int flag, t_pf *data)
{
	int end;

	restart_modsflags(data);
	if ((end = search_end(s, flag)) == flag)
		return (0);
	modifiers(s, flag, end, data);
	data->flags[0] = end;
	data->flags[1] = zero_flag(s, flag, end);
	data->flags[2] = minusplus_flag(s, flag, end);
	data->flags[3] = width_flag(s, flag, end);
	data->flags[4] = hash_flag(s, flag, end);
	data->flags[5] = precision_flag(s, flag, end, 0);
	data->flags[6] = precision_flag(s, flag, end, 1);
	if (s[end] == 'd' || s[end] == 'i' || s[end] == 'D')
		data->flags[7] = blank_space(s, flag, end);
	return (1);
}

int		ft_printf(const char *restrict format, ...)
{
	size_t	i;
	size_t	len;
	t_pf	*data;
	va_list	ap;

	i = -1;
	data = (t_pf *)malloc(sizeof(t_pf));
	data->len = 0;
	va_start(ap, format);
	len = ft_strlen((char *)format);
	while (++i < len)
		if (((i = checkstring(format, i, data)) > 0) && i < len)
		{
			if (check_flags(format, i, data) != 0)
				i = data->flags[0];
			check_type(format, i, ap, data);
			//create a check for relevant
		}
	va_end(ap);
	len = data->len;
	free(data);
	return (len);
}
