/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-lima <rde-lima@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:25:27 by rde-lima          #+#    #+#             */
/*   Updated: 2021/11/14 20:16:15 by rde-lima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# if __APPLE__
#  define IS_OSX 1
# else
#  define IS_OSX 0
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

char	*ft_itoa(long int n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_toupper(int c);
int		ft_printf(const char *fmt, ...);

#endif
