/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:21:47 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/27 20:29:39 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			getbase(char w)
{
	if (w == 'o' || w == 'O')
		return (8);
	if (w == 'x' || w == 'X')
		return (16);
	if (w == 'b')
		return (2);
	return (10);
}

size_t		ft_uimaxlen(uintmax_t nb)
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

void		ft_itostr(char *s, uintmax_t nb, size_t size, int is_neg)
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

char		*ft_imaxtoa(intmax_t nb)
{
	size_t		size;
	uintmax_t	nbr;
	char		*s;
	int			is_neg;

	size = 0;
	is_neg = 0;
	if (nb < 0)
	{
		is_neg = 1;
		nb = -nb;
	}
	nbr = nb;
	size = ft_uimaxlen(nbr) + is_neg;
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (s == 0)
		return (0);
	ft_itostr(s, nbr, size, is_neg);
	return (s);
}

char		*ft_uimaxtoa(uintmax_t nb)
{
	size_t	size;
	char	*s;

	size = ft_uimaxlen(nb);
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (s == 0)
		return (0);
	s[size] = '\0';
	while (size-- > 0)
	{
		s[size] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (s);
}
