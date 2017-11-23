/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:47:14 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/17 16:47:15 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

intmax_t sint_modifiers(char *mod, va_list ap)
{
    if (mod[0] == 'l' && mod[1] == 'l')
        return (va_arg(ap, long long));
    if (mod[0] == 'h' && mod[1] == 'h')
        return((signed char)va_arg(ap, int));
    if (mod[1] == 'l')
        return (va_arg(ap, long));
    if (mod[1] == 'h')
        return ((short)va_arg(ap, int));
    if (mod[1] == 'j')
        return (va_arg(ap, intmax_t));
    if (mod[1] == 'z')
        return (va_arg(ap, ssize_t));
    return (va_arg(ap, int));
}

uintmax_t uint_modifiers(char *mod, va_list ap)
{
    if (mod[0] == 'l' && mod[1] == 'l')
        return (va_arg(ap, unsigned long long));
    if (mod[0] == 'h' && mod[1] == 'h')
        return((unsigned char)va_arg(ap, int));
    if (mod[1] == 'l')
        return (va_arg(ap, unsigned long));
    if (mod[1] == 'h')
        return ((unsigned short)va_arg(ap, int));
    if (mod[1] == 'j')
        return (va_arg(ap, uintmax_t));
    if (mod[1] == 'z')
        return (va_arg(ap, size_t));
    return (va_arg(ap, unsigned int));
}