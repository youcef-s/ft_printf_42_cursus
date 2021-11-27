/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabtaim <ylabtaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:00:20 by ylabtaim          #+#    #+#             */
/*   Updated: 2021/11/27 02:17:48 by ylabtaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

int	ft_hexa(unsigned int h, char *base)
{
	int					len;
	unsigned int		h1;

	len = 0;
	if (h == 0)
		return (ft_char('0'));
	if (h < 0 || h > 4294967295)
	{
		h1 = 4294967296 - h;
		ft_char('-');
		len++;
	}
	else
		h1 = h;
	while (h1)
	{
		h1 /= 16;
		len++;
	}
	ft_print_hexa(h, len, base);
	return (len);
}

void	ft_print_hexa(unsigned int h, int len, char *base)
{
	char	*nbr;

	nbr = ft_calloc((len + 1), sizeof(char));
	if (!nbr)
		return ;
	while (len--)
	{
		nbr[len] = base[h % 16];
		h /= 16;
	}
	ft_putstr_fd(nbr, 1);
	free(nbr);
}

void	ft_print_pointer(void *p, int len, char *base)
{
	char			*nbr;
	unsigned long	h;

	h = (unsigned long)p;
	nbr = ft_calloc((len + 1), sizeof(char));
	if (!nbr)
		return ;
	while (len--)
	{
		nbr[len] = base[h % 16];
		h /= 16;
	}
	ft_putstr_fd(nbr, 1);
	free(nbr);
}

int	ft_pointer(void *p)
{
	int				len;
	unsigned long	p1;

	len = 0;
	p1 = (unsigned long)p;
	ft_putstr_fd("0x", 1);
	if (p1 == 0)
	{
		ft_char('0');
		return (3);
	}
	while (p1)
	{
		p1 /= 16;
		len++;
	}
	ft_print_pointer(p, len, "0123456789abcdef");
	return (len + 2);
}
