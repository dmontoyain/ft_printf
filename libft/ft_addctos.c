/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addctos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:42:59 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/25 23:08:24 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addctos(char *s, char c)
{
	char	*str;
	size_t	len;
	int		i;
	int		j;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * len + 2);
	while (s[i] != '\0')
		str[j++] = s[i++];
	str[j++] = c;
	str[j] = '\0';
	free(s);
	return (str);
}
