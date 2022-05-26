/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:41:05 by rde-lima          #+#    #+#             */
/*   Updated: 2021/11/14 18:51:30 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_get_digits(long int n)
{
	unsigned int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		++size;
	}
	return (size);
}

char	*ft_itoa(long int n)
{
	char			*str;
	unsigned int	size;
	unsigned int	neg;

	size = 0;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
		++size;
	}
	size += ft_get_digits(n);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	if (neg == 1)
		str[0] = '-';
	str[size] = '\0';
	while (size-- > neg)
	{
		str[size] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	size;

	size = 0;
	if (!s)
		return (ft_putstr("(null)"));
	if (s != NULL)
	{
		while (*s)
			size += ft_putchar(*s++);
	}
	return (size);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c & 95);
	return (c);
}
