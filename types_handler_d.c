/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_handler_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 22:54:52 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/29 16:12:01 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_round(double nb, char *dec, int i)
{
	int value;
	int ctr;

	ctr = 1;
	value = nb;
	value = (nb - (int)nb) * 10;
	if (value >= 5)
	{
		if ((int)nb != 9)
			dec[i] = (int)nb + 49;
		else
		{
			dec[i] = '0';
			if (dec[i - ctr] != '9')
				dec[i - ctr] = dec[i - ctr] + 1;
			else
				dec[i - ctr] = '0';
		}
	}
	else
		dec[i] = (int)nb + 48;
}

char		*ft_dtoa(double nb, int round)
{
	char		*dec;
	int			i;
	char		*whole;
	int			declen;

	if ((declen = round) == 0)
		round = 1;
	whole = ft_itoa(nb);
	if (nb < 0)
		nb = -nb;
	if (nb >= 1)
		nb = nb - (int)nb;
	dec = (char *)malloc(sizeof(char) * (round + 2));
	dec[round + 1] = '\0';
	dec[0] = '.';
	i = 1;
	while (nb != 0 && round-- > 0)
	{
		nb = (nb - (int)nb) * 10;
		if (i == declen)
			ft_round(nb, dec, i++);
		else
			dec[i++] = (int)nb + 48;
	}
	return (whole = ft_strjoin(whole, dec));
}

int			getroundvalue(t_pf *data)
{
	if (data->flags[5] >= 0 && data->flags[6] != 0)
		return (data->flags[5]);
	return (6);
}

void		double_type(va_list ap, t_pf *data)
{
	int			round;
	int			width;
	char		*dec;
	double		d;

	d = va_arg(ap, double);
	round = getroundvalue(data);
	dec = ft_dtoa(d, round);
	width = data->flags[3] - ft_strlen(dec);
	if (width > 0)
		ifield_width(width, dec, data, 'd');
	else
	{
		if (data->flags[1] != 1 && data->flags[2] == 43 && dec[0] != '-')
		{
			data->len += 1;
			ft_putchar('+');
		}
		ft_putstr(dec);
		data->len += ft_strlen(dec);
	}
	free(dec);
}

void		f_type(va_list ap, t_pf *data)
{
	int			round;
	int			width;
	char		*dec;
	float		d;

	if (data->mod[0] == 'l')
		return (double_type(ap, data));
	d = va_arg(ap, double);
	ft_putstr(dec);
	round = getroundvalue(data);
	dec = ft_dtoa(d, round);
	width = data->flags[3] - ft_strlen(dec);
	if (width > 0)
		ifield_width(width, dec, data, 'd');
	else
	{
		if (data->flags[1] != 1 && data->flags[2] == 43 && dec[0] != '-')
		{
			data->len += 1;
			ft_putchar('+');
		}
		ft_putstr(dec);
		data->len += ft_strlen(dec);
	}
	free(dec);
}
