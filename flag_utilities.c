/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 21:56:29 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/25 23:13:32 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	undet_behavior(t_pf *data, char **res, char w)
{
	if (data->flags[2] >= 45 && data->flags[1] == 1)
		data->flags[1] = 0;
	if (ft_atoi(res[0]) == 0 && data->flags[6] == 1 && data->flags[5] == 0)
		res[0] = ft_strnew(0);
	if (ft_atoi(res[0]) == 0 && w != 'o')
		data->flags[4] = 0;
	if (data->flags[6] == 1 && data->flags[1] == 1)
		data->flags[1] = 0;
	if (data->flags[2] == 43 || data->flags[2] == 88)
		data->flags[7] = 0;
}

int		search_end(const char *restrict s, int i)
{
	while (s[i] != 'c' && s[i] != 'd' && s[i] != 's' && s[i] != 'D'
			&& s[i] != 'S' && s[i] != 'C' && s[i] != 'x' && s[i] != 'X'
			&& s[i] != 'p' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u'
			&& s[i] != 'U' && s[i] != 'O' && s[i] != '\0' && s[i] != 'b'
			&& s[i] != '%' && s[i] != 'Z')
		i++;
	return (i);
}

char	*precision_adjust(char *str, t_pf *data, int len)
{
	char	*tmp;
	int		adj;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((adj = data->flags[5] - len) == 0 && ft_atoi(str) >= 0)
		return (str);
	if (str[0] == '-')
		adj++;
	len = adj + ft_strlen(str);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	tmp[len] = '\0';
	while (str[i] != '\0')
	{
		if (str[0] == '-')
			tmp[j++] = str[i++];
		if (adj > 0)
			while (adj-- > 0)
				tmp[j++] = '0';
		tmp[j++] = str[i++];
	}
	ft_strdel(&str);
	return (tmp);
}

void	restart_modsflags(t_pf *data)
{
	data->flags[1] = 0;
	data->flags[2] = 0;
	data->flags[3] = 0;
	data->flags[4] = 0;
	data->flags[5] = 0;
	data->flags[6] = 0;
	data->flags[7] = 0;
	data->mod[0] = '0';
	data->mod[1] = '0';
	data->mod[2] = '0';
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
