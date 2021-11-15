/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minprintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:37:52 by rde-lima          #+#    #+#             */
/*   Updated: 2021/10/26 21:39:31 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

/* minprintf: minimal printf with variable argument list */
void	minprintf(char *fmt, ...)
{
	va_list	ap; /* points to each unnamed arg in turn */
	char	*p;
	char	*sval;
	int		ival;
	double	dval;

	va_start(ap, fmt); /* make ap point to 1st unnamed arg */
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch (*++p) {
			case 'd':
				ival = va_arg(ap, int);
				printf("%d", ival);
			break;
			case 'f':
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval; sval++)
					putchar(*sval);
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap); /* clean up when done */
}

int	main(void)
{
	minprintf("Teste");
	return (0);
}
