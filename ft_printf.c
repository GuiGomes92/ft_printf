/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:27:54 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/05/26 16:24:53 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int ft_printf(const char *, ...)
{
	va_list arg;
	printf("%s\n", va_arg(arg, char *));
	printf("%s\n", va_arg(arg, char *));
	va_end(arg);
	return (0);
}

int main(void)
{
	char c = 'A';
	char d = 'B';
	ft_printf("%c %c", c, d);
	
}
