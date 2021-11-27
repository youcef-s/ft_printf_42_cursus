/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabtaim <ylabtaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:08:25 by ylabtaim          #+#    #+#             */
/*   Updated: 2021/11/26 03:07:25 by ylabtaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

int	ft_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_string(char *str)
{
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_int(int nbr)
{
	char	*n;
	int		len;

	ft_putnbr_fd(nbr, 1);
	n = ft_itoa(nbr);
	len = ft_strlen(n);
	free(n);
	return (len);
}

int	ft_unsigned(unsigned int i)
{
	int		j;
	int		k;
	int		len;
	char	*tmp;
	char	*tmp2;

	j = 0;
	k = 0;
	if (i <= 2147483647)
		return (ft_int(i));
	else
	{
		j = i / 1000;
		k = i % 1000;
		ft_putnbr_fd(j, 1);
		ft_putnbr_fd(k, 1);
	}
	tmp = ft_itoa(j);
	tmp2 = ft_itoa(k);
	len = ft_strlen(tmp) + ft_strlen(tmp2);
	free (tmp);
	free (tmp2);
	return (len);
}
