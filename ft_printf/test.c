/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:49:28 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/13 14:56:11 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void foo(char *fmt, ...)
{
	va_list ap;
	int d;
	char c, *s;

	va_start(ap, fmt);
//	va_copy(ap2, ap);
	while (*fmt)
		switch(*fmt++) {
		case 's':                       /* string */
			s = va_arg(ap, char *);
			printf("string %s\n", s);
			break;
		case 'd':                       /* int */
			d = va_arg(ap, int);
			printf("int %d\n", d);
			break;
		case 'c':                       /* char */
			/* Note: char is promoted to int. */
			c = va_arg(ap, int);
			printf("char %c\n", c);
			break;
		}
	va_end(ap);
}

int main()
{
	char *fmt = "sdsc";
	char *s1 = "hey";
	char *s2 = "hola";
	char c = 'f';
	int f = 7;
	foo(fmt, s1, f, s2, c);
	return (0);
}
