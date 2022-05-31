/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:16:04 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/05/31 20:40:44 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int ft_convert_ptr(uintptr_t ptr)
{                        
	char        *str;    
	int         len;     
	uintptr_t   num;     
	int         mod;     
	const char  hex[] = "0123456789abcdef";                             
	
	num = ptr;           
	len = 0;             
	while (num > 0)      
	{                    
		num = num / 16;  
		len++;           
	}
	str = malloc(len + 1 * sizeof(char));
	str[len] = '\0';     
	num = ptr;           
	while (num > 0)      
	{                    
		len--;           
		mod = num % 16;  
		str[len] = hex[mod];
		num = num / 16;  
	}                    
	ft_putstr_fd(str, 1);
	return (len);        
}                        
                          
static int ft_put_ptr(unsigned long long ptr)
{
	int len;
	
	len = 0;	
	len += write(1, "0x", 2);   
	len += ft_convert_ptr(ptr);    
	return (len);          
} 