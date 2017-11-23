/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:02:38 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/13 16:51:53 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	c_type(va_list ap, char *mod, int *flags, char w)
{
	unsigned char c;
	int width;

	width = flags[3] - 1;
	if (w == 'C' || (mod[1] == 'l' && w == 'c'))
		return (wchar_type(ap, flags));
	c = va_arg(ap, int);
	if (flags[2] >= 45)
		ft_putchar(c);
	while (width-- > 0)
		ft_putchar(' ');
	if (flags[2] < 45)
		ft_putchar(c);
}

void	di_type(va_list ap, char *mod, int *flags)
{
	int width;
	char *res;
	int tmp;

	tmp = 0;
	res = ft_imaxtoa(sint_modifiers(mod, ap));
	width = flags[3] - ft_strlen(res);
	if (width > 0)
		tmp = ifield_width(width, res, flags, 'd');
	else
	{
		if (flags[1] != 1 && flags[2] == 43 && res[0] != '-')
			ft_putchar('+');
		ft_putstr(res);
	}
	free(res);
}

void	u_type(va_list ap, char *mod, int *flags)
{
	int width;
	char *res;

	res = ft_uimaxtoa(uint_modifiers(mod, ap));
	width = flags[3] - ft_strlen(res);
	if (width > 0)
		ufield_width(width, res, flags, 'u');
	else
		ft_putstr(res);
	free(res);
}

void	number_type(char *mod, char w, va_list ap, int *flags)
{
	if (w == 'd' || w == 'i' || w == 'D')
		di_type(ap, mod, flags);
	else if (w == 'c' || w == 'C')
		c_type(ap, mod, flags, w);
	else if (w == 'u' || w == 'U')
		u_type(ap, mod, flags);
}