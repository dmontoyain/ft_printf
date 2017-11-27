/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:36:09 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/25 23:30:37 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIBFTPRINTF_H
# define	LIBFTPRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

typedef struct		s_pf
{
	size_t			len;
	char			mod[3];
	int				flags[8];
	char			type;
}					t_pf;
int					ft_printf(const char *restrict format, ...);
void				s_type(va_list ap, t_pf *dat, char w);
void				number_type(char w, va_list ap, t_pf *data);
void				percent_type(t_pf *data);
void				p_type(va_list ap, t_pf *data);
void				b_type(va_list ap, t_pf *data);
void				ox_type(va_list ap, t_pf *data, char w);
void				wchar_type(va_list ap, t_pf *data);
void				ft_unicode_conv(wchar_t c, char *str);
int					width_flag(const char *restrict s, int f, int e);
int					minusplus_flag(const char *restrict s, int f, int e);
int					zero_flag(const char *restrict s, int f, int e);
int					hash_flag(const char *restrict s, int f, int e);
int					precision_flag(const char *restrict s, int f, int e, int i);
void				restart_modsflags(t_pf *data);
int					search_end(const char *restrict s, int i);
void				ifield_width(int wth, char *r, t_pf *data, char type);
void				ufield_width(int wth, char *r, t_pf *data, char type);
char				*precision_adjust(char *str, t_pf *data, int len);
void				prefixtype(char type);
void				undet_behavior(t_pf *data, char **res, char w);
int					blank_space(const char *restrict s, int flag, int end);
void				min_width(t_pf *data, int width);
void				modifiers(const char *restrict s, int f, int e, t_pf *data);
int				check_hmod(t_pf *d, char c);
uintmax_t			uint_modifiers(va_list ap, t_pf *data);
intmax_t			sint_modifiers(va_list ap, t_pf *data);
char				*ft_uimaxtoa(uintmax_t nb);
char				*ft_imaxtoa(intmax_t nb);
int					getbase(char type);

#endif
