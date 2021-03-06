/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:16:04 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/06/21 17:59:13 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h" 

int	get_ptr_len(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

int	ft_puthex(unsigned long long ptr)
{
	int	ascii;

	ascii = 0;
	if (ptr >= 16)
	{
		ft_puthex(ptr / 16);
		ft_puthex(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
		{
			ascii = ptr + '0';
			if (write(1, &ascii, 1) != 1)
				return (-1);
		}
		else
		{
			ascii = ptr - 10 + 'a';
			if (write (1, &ascii, 1) != 1)
				return (-1);
		}
	}
	return (0);
}

int	ft_put_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (write(1, "0x", 2) != 2)
		return (-1);
	else
		len += 2;
	if (ptr == 0)
	{
		if (write(1, "0", 1) != 1)
			return (-1);
		else
			len += 1;
	}
	else
	{
		ft_puthex(ptr);
		len += get_ptr_len(ptr);
	}
	return (len);
}
