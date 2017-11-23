/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:36:09 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/22 13:35:41 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LIBFTPRINTF_H
# define	LIBFTPRINTF_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>

void	        s_type(va_list ap, int *flags, char *mods, char w);
void	        number_type(char *mods, char w, va_list ap, int *flags);
void	        p_type(va_list ap, int *flags);
int             width_flag(const char * restrict s, int flag, int end);
int             minusplus_flag(const char * restrict s, int flag, int end);
int             zero_flag(const char *restrict s, int flag, int end);
void	        Xox_type(va_list ap, int *flags, char *mod, char w);
int             hash_flag(const char * restrict s, int flag, int end);
int             precision_flag(const char *restrict s, int flag, int end);
char            *uitoa_base(uintmax_t nbr, unsigned int base);
void            empty_flagarray(int *flags);
char	        *ft_uimaxtoa(uintmax_t nb);
char	        *ft_imaxtoa(intmax_t nb);
intmax_t        sint_modifiers(char *mod, va_list ap);
uintmax_t       uint_modifiers(char *mod, va_list ap);
void            smtouppercase(char *str);
char            *imtoa_base(intmax_t nbr, int base);
int            ifield_width(int wth, char *r, int *f, char type);
void            ufield_width(int wth, char *r, int *f, char type);
char	        *precision_adjust(char *str, int adj);
void             wchar_type(va_list ap, int *flags);
int	            getbase(char w);
void	prefixtype(char type);
void	ft_unicode_conv(wchar_t c, char *str);
int		ft_printf(const char * restrict format, ...);


#endif
