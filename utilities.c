/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:31:49 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/27 20:43:57 by dmontoya         ###   ########.fr       */
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
