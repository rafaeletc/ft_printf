/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:38:25 by rde-lima          #+#    #+#             */
/*   Updated: 2021/11/14 23:47:19 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

double	average(int count, ...)
{
	va_list	ap;
	int		size;
	double	sum;

	sum = 0;
	size = 0;
	va_start(ap, count); /* last fixed parameter (to get the address) */
	while (size++ < count)
		sum += va_arg(ap, int); /* Increments ap to the next argument. */
	va_end(ap);
	return (sum / count);
}

int	main(void)
{
	printf("%f\n", average(6, 1, 2, 3, 10, 4, 6));
	return (0);
}
