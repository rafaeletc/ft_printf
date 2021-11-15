/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:46:45 by rde-lima          #+#    #+#             */
/*   Updated: 2021/11/14 22:27:09 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include "../ft_printf.h"

int	main(void)
{
	void	*p;
	int		s;
	int		r;

	s = printf("%i %i %i %i %i\n", INT_MAX, INT_MIN, UINT_MAX, 0, -42);
	r = ft_printf("%i %i %i %i %i\n", INT_MAX, INT_MIN, UINT_MAX, 0, -42);
	if (r != s)
		printf("Wrong size! Got %d when expected %d\n", r, s);
	s = printf("%d %d %d %d %d %d %d %d\n",
			-10, -11, -14, -15, -16, -88, -100, -101);
	r = ft_printf("%d %d %d %d %d %d %d %d\n",
			-10, -11, -14, -15, -16, -88, -100, -101);
	if (r != s)
		printf("Wrong size! Got %d when expected %d\n", r, s);
	p = malloc(1024);
	s = printf("%p = Olá %s %d%c\n", p, "mundo", -42, '!');
	r = ft_printf("%p = Olá %s %d%c\n", p, "mundo", -42, '!');
	if (r != s)
		printf("Wrong size! Got %d when expected %d\n", r, s);
	s = printf("%%, %c, %d, %i, %u, %p, %x, %X, %s.\n",
			'*', 1024, -42, 42, p, 42, 42, "teste");
	r = ft_printf("%%, %c, %d, %i, %u, %p, %x, %X, %s.\n",
			'*', 1024, -42, 42, p, 42, 42, "teste");
	if (r != s)
		printf("Wrong size! Got %d when expected %d\n", r, s);
	s = printf("%p %p\n", (void *)0, (void *)0);
	r = ft_printf("%p %p\n", (void *)0, (void *)0);
	if (r != s)
		printf("Wrong size! Got %d when expected %d\n", r, s);
	s = printf("%x %X %x %X\n", INT_MAX, INT_MAX, UINT_MAX, UINT_MAX);
	r = ft_printf("%x %X %x %X\n", INT_MAX, INT_MAX, UINT_MAX, UINT_MAX);
	if (r != s)
		printf("Wrong size! Got %d when expected %d\n", r, s);
	free (p);
	p = NULL;
	return (0);
}
