/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:07:24 by dmontoya          #+#    #+#             */
/*   Updated: 2017/12/01 17:37:39 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		minusplus_flag(const char *restrict s, int flag, int end)
{
	int i;

	i = 0;
	while (flag < end)
	{
		if (i != 88)
		{
			if (s[flag] == '+')
				if (i != 43)
					i = i + s[flag];
			if (s[flag] == '-')
				if (i != 45)
					i = i + s[flag];
		}
		flag++;
	}
	return (i);
}

int		hash_flag(const char *restrict s, int flag, int end)
{
	while (flag < end)
	{
		if (s[flag] == '#')
		{
			if (s[end] == 'X' || s[end] == 'x')
				return (2);
			return (1);
		}
		if (ft_isdigit(s[flag]) != 0)
			break ;
		flag++;
	}
	return (0);
}

int		zero_flag(const char *restrict s, int flag, int end)
{
	while (flag < end)
	{
		if (ft_isdigit(s[flag]) != 0)
		{
			if (s[flag] == '0')
				return (1);
			else
				return (0);
		}
		flag++;
	}
	return (0);
}

int		precision_flag(const char *restrict s, int flag, int end, int i)
{
	int precision;

	precision = 0;
	while (flag < end)
	{
		if (s[flag] == '.')
		{
			if (i == 1)
				return (1);
			while (ft_isdigit(s[++flag]) > 0)
				precision = (precision * 10) + (s[flag] - 48);
			return (precision);
		}
		flag++;
	}
	return (0);
}

int		width_flag(const char *restrict s, int flag, int end)
{
	int width;

	width = 0;
	while (((ft_isdigit(s[flag]) == 0) || s[flag] == '0') && flag < end)
		if (s[flag++] == '.')
			return (width);
	while (ft_isdigit(s[flag]) != 0)
		width = (width * 10) + (s[flag++] - 48);
	return (width);
}
