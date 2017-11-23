/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:21:47 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/19 17:21:49 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t          ft_imaxlen(intmax_t nb)
{
	size_t		size;

	size = 0;
	if (nb < 0)
	{
		size++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		size++;
	}
	return (size + 1);
}

void            ft_itostr(char *s, intmax_t nb, size_t size, int is_neg)
{
	s[size] = '\0';
	while (size-- > 0)
	{
		if (size == 0 && is_neg == 1)
		{
			s[0] = '-';
			break ;
		}
		s[size] = nb % 10 + '0';
		nb = nb / 10;
	}
}

char			*ft_imaxtoa(intmax_t nb)
{
	size_t		size;
	char	*s;
	int		is_neg;

	is_neg = 0;
	size = ft_imaxlen(nb);
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (s == 0)
		return (0);
	if (nb < 0)
	{
		is_neg = 1;
		nb = -nb;
	}
	ft_itostr(s, nb, size, is_neg);
	return (s);
}

size_t          ft_uimaxlen(uintmax_t nb)
{
	size_t		size;

	size = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		size++;
	}
	return (size + 1);
}

void            ft_uitostr(char *s, uintmax_t nb, size_t size)
{
	s[size] = '\0';
	while (size-- > 0)
	{
		s[size] = nb % 10 + '0';
		nb = nb / 10;
	}
}

char			*ft_uimaxtoa(uintmax_t nb)
{
	size_t		size;
	char	*s;

	size = ft_uimaxlen(nb);
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (s == 0)
		return (0);
	ft_uitostr(s, nb, size);
	return (s);
}