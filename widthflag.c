/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widthflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 22:00:26 by dmontoya          #+#    #+#             */
/*   Updated: 2017/12/01 17:52:30 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	intminus_flag(char *res, t_pf *data, char type)
{
	if (data->flags[2] == 88 && res[0] != '-')
		prefixtype(type);
	ft_putstr(res);
}

void	min_width(t_pf *data, int width, char *res)
{
	if (res[0] != '-' && data->flags[7] == 1 && data->flags[2] < 45)
	{
		ft_putchar(' ');
		width--;
	}
	while (width-- > 0)
	{
		if (data->flags[1] == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
}

void	ifield_width(int width, char *res, t_pf *data, char type)
{
	data->len += data->flags[3];
	if (data->flags[2] >= 45)
		intminus_flag(res, data, type);
	if ((data->flags[2] == 88 || data->flags[2] == 43) && res[0] != '-')
		width--;
	if (data->flags[1] == 1 && data->flags[2] <= 43)
	{
		if (res[0] == '-')
		{
			data->flags[2] = 0;
			ft_putchar('-');
			res++;
		}
		else if (data->flags[2] == 43)
			prefixtype(type);
	}
	min_width(data, width, res);
	if (data->flags[2] < 45)
	{
		if (data->flags[1] != 1 && data->flags[2] == 43 && res[0] != '-')
			ft_putchar('+');
		ft_putstr(res);
	}
}

void	ufield_width(int width, char *res, t_pf *data, char type)
{
	data->len += data->flags[3];
	if (ft_strlen(res) == 0 && ft_atoi(res) == 0 && type != 's')
		return (min_width(data, width, res));
	if (data->flags[2] >= 45)
	{
		if (data->flags[4] != 0)
			prefixtype(type);
		ft_putstr(res);
	}
	if (data->flags[2] < 45 && data->flags[1] == 1 && data->flags[4] != 0)
		prefixtype(type);
	if (data->flags[4] != 0 && type != 'u')
		width = width - data->flags[4];
	min_width(data, width, res);
	if (data->flags[2] < 45)
	{
		if (data->flags[4] != 0 && data->flags[1] != 1)
			prefixtype(type);
		ft_putstr(res);
	}
}

void	pointer_width(int width, char *res, t_pf *data)
{
	data->len += data->flags[3];
	if (data->flags[2] >= 45)
	{
		ft_putstr("0x");
		if (res != 0)
			ft_putstr(res);
	}
	if (data->flags[2] < 45 && data->flags[1] == 1)
		ft_putstr("0x");
	min_width(data, width, res);
	if (data->flags[2] < 45)
	{
		if (data->flags[1] != 1)
			ft_putstr("0x");
		if (res != 0)
			ft_putstr(res);
	}
}
