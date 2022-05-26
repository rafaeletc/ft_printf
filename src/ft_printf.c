/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:24:39 by rde-lima          #+#    #+#             */
/*   Updated: 2021/11/14 20:12:59 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printd(long int n)
{
	char	*tmp;
	int		size;

	tmp = ft_itoa(n);
	size = ft_putstr(tmp);
	free(tmp);
	return (size);
}

static int	ft_printh(unsigned int n, const char flag)
{
	static int	size;
	char		*base;
	char		tmp;

	size = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		ft_printh(n / 16, flag);
	tmp = base[n % 16];
	if (flag == 'X')
		size += ft_putchar(ft_toupper(tmp));
	else
		size += ft_putchar(tmp);
	return (size);
}

static int	ft_printp(unsigned long int n)
{
	static int	size;
	char		*base;
	char		tmp;

	if (!n && !IS_OSX)
		return (ft_putstr("(nil)"));
	size = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		ft_printp(n / 16);
	tmp = base[n % 16];
	if (!size)
		size += ft_putstr("0x");
	size += ft_putchar(tmp);
	return (size);
}

static int	ft_printfargs(const char *p, va_list ap, int size)
{
	while (*p)
	{
		if (*p == '%')
		{
			if (*++p == 'c')
				size += ft_putchar(va_arg(ap, int));
			else if (*p == 's')
				size += ft_putstr(va_arg(ap, char *));
			else if (*p == 'd' || *p == 'i')
				size += ft_printd(va_arg(ap, int));
			else if (*p == 'u')
				size += ft_printd(va_arg(ap, unsigned int));
			else if (*p == 'x' || *p == 'X')
				size += ft_printh(va_arg(ap, unsigned int), *p);
			else if (*p == 'p')
				size += ft_printp(va_arg(ap, unsigned long int));
			else
				size += ft_putchar(*p);
			++p;
		}
		else
			size += ft_putchar(*p++);
	}
	return (size);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		size;

	va_start(ap, fmt);
	size = 0;
	size = ft_printfargs(fmt, ap, size);
	va_end(ap);
	return (size);
}
