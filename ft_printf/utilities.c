/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:16:21 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/16 22:16:22 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void    smtouppercase(char *str)
{
    while (*str)
    {
        if (*str >= 97 && *str <= 122)
            *str = *str - 32;
            str++;
    }
}

char    *uitoa_base(uintmax_t nbr, unsigned int base)
{
    uintmax_t	i;
	size_t		size;
	char		*ret;
    char *str = "0123456789abcdef";

	i = nbr;
	size = 1;
	while ((i /= base))
		size++;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	ret[size] = '\0';
	i = nbr;
	ret[--size] = str[i % base];
	while ((i /= base))
		ret[--size] = str[i % base];
	return (ret);
}

char    *imtoa_base(intmax_t nbr, int base)
{
    intmax_t	i;
	size_t		size;
	char		*ret;
    char *str = "0123456789abcdef";

	i = nbr;
	size = 1;
	while ((i /= base))
		size++;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	ret[size] = '\0';
	i = nbr;
	ret[--size] = str[i % base];
	while ((i /= base))
		ret[--size] = str[i % base];
	return (ret);
}

void    empty_flagarray(int *flags)
{
	flags[1] = 0;
	flags[2] = 0;
	flags[3] = 0;
	flags[4] = 0;
	flags[5] = 0;
}

void	prefixtype(char type)
{
	if (type == 'x')
		return (ft_putstr("0x"));
	if (type == 'X')
		return (ft_putstr("0X"));
	if (type == 'o')
		return (ft_putchar('0'));
	if (type == 'd')
		return (ft_putchar('+'));
}

int		intminus_flag(char *res, int *flags, char type)
{
	if (flags[2] == 88 && res[0] != '-')
		prefixtype(type);
	ft_putstr(res);
	return (1);
}

int		ifield_width(int width, char *res, int *fl, char type)
{
	int temp;

	temp = 0;
	if (fl[2] >= 45)
		temp = intminus_flag(res, fl, type);
	if ((fl[2] == 88 || fl[2] == 43) && res[0] != '-')
		width--;
	if (fl[1] == 1 && fl[2] == 43)
	{
		if (res[0] == '-')
		{
			ft_putchar('-');
			res++;
		}
		else
			prefixtype(type);
	}
	while (width-- > 0)
	{
		if (fl[1] == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	if (fl[2] < 45)
	{
		if (fl[1] != 1 && fl[2] == 43)
			ft_putchar('+');
		ft_putstr(res);
	}
	return (temp);
}

void	ufield_width(int width, char *res, int *fl, char type)
{
	if (fl[2] >= 45)
	{
		if (fl[4] != 0)
			prefixtype(type);
		ft_putstr(res);
	}
	if (fl[2] < 45 && fl[1] == 1 && fl[4] != 0)
		prefixtype(type);
	while (width-- > 0)
	{
		if (fl[1] == 1 && fl[4] < 45)
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	if (fl[2] < 45)
	{
		if (fl[4] != 0 && fl[1] != 1)
			prefixtype(type);
		ft_putstr(res);
	}
}

char	*precision_adjust(char *str, int adj)
{
	char *tmp;
	int len;
	int i;
	int j;
	
	i = 0;
	j = 0;
	len = adj + ft_strlen(str);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	tmp[len] = '\0';
	while (str[i] != '\0')
	{
		if (str[i] == '-')
		{
			tmp[j++] = '-';
			i++;
		}
		if (adj > 0)
			while (adj--)
				tmp[j++] = '0';
		tmp[j++] = str[i++];
	}
	ft_strdel(&str);
	return (tmp);
}

int		getbase(char w)
{
	if (w == 'o')
		return (8);
	if (w == 'x' || w == 'X')
		return (16);
	if (w == 'b')
		return (2);
	return (0);
}