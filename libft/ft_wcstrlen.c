/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcstrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 00:08:12 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/25 22:53:30 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcstrlen(wchar_t *wstr)
{
	int		i;
	size_t	size;

	i = -1;
	size = 0;
	while (wstr[++i])
		size = size + ft_wcharlen(wstr[i]);
	return (size);
}
