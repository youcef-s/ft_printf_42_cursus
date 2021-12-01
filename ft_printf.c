/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabtaim <ylabtaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:02:11 by ylabtaim          #+#    #+#             */
/*   Updated: 2021/11/27 02:19:35 by ylabtaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int		len;
	int		norm_is_bulls;
	va_list	ptr;

	va_start(ptr, format);
	len = ft_length((char *)format, ptr, 0);
	va_end(ptr);
	return (len);
}

int	ft_length(char *c, va_list ptr, int len)
{
	while (*c)
	{
		if (*c == '%' && *(c + 1) == 'c')
			len += ft_char(va_arg(ptr, int));
		else if (*c == '%' && *(c + 1) == 's')
			len += ft_string(va_arg(ptr, char *));
		else if (*c == '%' && (*(c + 1) == 'd' || *(c + 1) == 'i'))
			len += ft_int(va_arg(ptr, int));
		else if (*c == '%' && *(c + 1) == 'x')
			len += ft_hexa(va_arg(ptr, unsigned int), "0123456789abcdef");
		else if (*c == '%' && *(c + 1) == 'X')
			len += ft_hexa(va_arg(ptr, unsigned int), "0123456789ABCDEF");
		else if (*c == '%' && *(c + 1) == 'p')
			len += ft_pointer(va_arg(ptr, void *));
		else if (*c == '%' && *(c + 1) == 'u')
			len += ft_unsigned(va_arg(ptr, unsigned int));
		else if (*c == '%' && *(c + 1) == '%')
			len += ft_char('%');
		else
			len += ft_char((*(c--)));
		c += 2;
	}
	return (len);
}
