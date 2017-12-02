/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:47:14 by dmontoya          #+#    #+#             */
/*   Updated: 2017/12/01 21:40:54 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

intmax_t	sint_modifiers(va_list ap, t_pf *data)
{
	if (data->mod[0] == 'l' && data->mod[1] == 'l')
		return (va_arg(ap, long long int));
	if (data->mod[0] == 'h' && data->mod[1] == 'h'
		&& data->type == 'D')
		return (va_arg(ap, unsigned long));
	if (data->mod[0] == 'h' && data->mod[1] == 'h')
		return ((signed char)va_arg(ap, int));
	if (data->mod[0] == 'l' || data->type == 'D')
		return (va_arg(ap, long));
	if (data->mod[0] == 'h')
		return ((short)va_arg(ap, int));
	if (data->mod[0] == 'j')
		return (va_arg(ap, intmax_t));
	if (data->mod[0] == 'z')
		return (va_arg(ap, ssize_t));
	return (va_arg(ap, int));
}

uintmax_t	uint_modifiers(va_list ap, t_pf *data)
{
	int i;

	i = 0;
	if (data->mod[2] != '0')
		i++;
	if (data->mod[i] == 'l' && data->mod[i + 1] == 'l')
		return (va_arg(ap, unsigned long long));
	if (data->mod[i] == 'l' && data->type == 'U')
		return (va_arg(ap, unsigned long long));
	if (data->mod[i] == 'h' && data->mod[i + 1] == 'h'
		&& (data->type == 'O' || data->type == 'U'))
		return (va_arg(ap, unsigned long));
	if (data->mod[i] == 'h' && data->mod[i + 1] == 'h')
		return ((unsigned char)va_arg(ap, int));
	if (data->mod[i] == 'l' || data->type == 'U' || data->type == 'O')
		return (va_arg(ap, unsigned long));
	if (data->mod[i] == 'h')
		return ((unsigned short)va_arg(ap, int));
	if (data->mod[i] == 'j')
		return (va_arg(ap, uintmax_t));
	if (data->mod[i] == 'z')
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned int));
}

int			check_hmod(t_pf *d, char c)
{
	unsigned int	i;
	int				tmp;
	int				h;

	i = 0;
	tmp = 0;
	h = 0;
	while (i < 3)
	{
		if (d->mod[i] == 'l' || d->mod[i] == 'j' || d->mod[i] == 'z')
			tmp++;
		if ((d->mod[i] == 'h' && tmp > 0) || (tmp > 0 && h > 0))
			if (c == 'd')
				return ('u');
		if (d->mod[i] == 'h' && tmp == 0)
			h++;
		i++;
	}
	return (c);
}

void		modifiers(const char *restrict s, int f, int end, t_pf *data)
{
	unsigned int i;

	i = 0;
	while (f < end)
	{
		if (s[f] == 'l' || s[f] == 'h' || s[f] == 'z' || s[f] == 'j')
		{
			while (i < 3 && f < end)
				data->mod[i++] = s[f++];
			return ;
		}
		f++;
	}
}
