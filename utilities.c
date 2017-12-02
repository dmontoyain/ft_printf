/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:31:49 by dmontoya          #+#    #+#             */
/*   Updated: 2017/12/01 17:58:35 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	put_color(char *tmp)
{
	if (ft_strcmp(tmp, "red") == 0)
		ft_putstr(RED);
	else if (ft_strcmp(tmp, "magenta") == 0)
		ft_putstr(MAGENTA);
	else if (ft_strcmp(tmp, "blue") == 0)
		ft_putstr(BLUE);
	else if (ft_strcmp(tmp, "yellow") == 0)
		ft_putstr(YELLOW);
	else if (ft_strcmp(tmp, "cyan") == 0)
		ft_putstr(CYAN);
	else if (ft_strcmp(tmp, "eoc") == 0)
		ft_putstr(EOC);
	return ;
}

int		blank_space(const char *restrict s, int flag, int end)
{
	while (flag < end)
		if (s[flag++] == ' ')
			return (1);
	return (0);
}

void	invalid_end(t_pf *data)
{
	if (data->flags[3] > 0)
	{
		data->len += data->flags[3];
		min_width(data, data->flags[3] - 1, "(null)");
	}
	else
		data->len++;
	ft_putchar(data->type);
}
