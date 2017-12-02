/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:36:09 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/29 16:09:44 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define EOC   	"\x1b[0m"

typedef struct		s_pf
{
	char			type;
	size_t			len;
	char			mod[4];
	int				flags[8];
}					t_pf;

int					ft_printf(const char *restrict format, ...);
void				s_type(va_list ap, t_pf *data);
void				percent_type(t_pf *data);
void				p_type(va_list ap, t_pf *data);
void				b_type(va_list ap, t_pf *data);
void				c_type(va_list ap, t_pf *data);
void				di_type(va_list ap, t_pf *data);
void				ox_type(va_list ap, t_pf *data);
void				u_type(va_list ap, t_pf *data);
void				f_type(va_list ap, t_pf *data);
void				ft_unicode_conv(wchar_t c, char *str);
int					width_flag(const char *restrict s, int f, int e);
int					minusplus_flag(const char *restrict s, int f, int e);
int					zero_flag(const char *restrict s, int f, int e);
int					hash_flag(const char *restrict s, int f, int e);
int					precision_flag(const char *restrict s, int f, int e, int i);
void				restart_modsflags(t_pf *data);
int					search_end(const char *restrict s, int i, int x);
void				ifield_width(int wth, char *r, t_pf *data, char type);
void				ufield_width(int wth, char *r, t_pf *data, char type);
void				pointer_width(int width, char *res, t_pf *data);
char				*precision_adjust(char *str, t_pf *data, int len);
void				prefixtype(char type);
void				undet_behavior(t_pf *data, char **res);
int					blank_space(const char *restrict s, int flag, int end);
void				min_width(t_pf *data, int width, char *res);
void				modifiers(const char *restrict s, int f, int e, t_pf *data);
int					check_hmod(t_pf *d, char c);
uintmax_t			uint_modifiers(va_list ap, t_pf *data);
intmax_t			sint_modifiers(va_list ap, t_pf *data);
char				*ft_uimaxtoa(uintmax_t nb);
char				*ft_imaxtoa(intmax_t nb);
int					getbase(char type);
void		wstrtostr(wchar_t *wstr, char *str);
void	ft_unicode_conv(wchar_t c, char *str);
void				put_color(char *tmp);

#endif
