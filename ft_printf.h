/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabtaim <ylabtaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:02:46 by ylabtaim          #+#    #+#             */
/*   Updated: 2021/11/27 01:03:20 by ylabtaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_length(char *c, va_list ptr, int len);
int		ft_hexa(unsigned int h, char *base);
int		ft_pointer(void *p);
int		ft_char(char c);
int		ft_string(char *str);
int		ft_unsigned(unsigned int i);
int		ft_int(int nbr);
void	ft_print_hexa(unsigned int h, int len, char *base);
void	ft_print_pointer(void *p, int len, char *base);

#endif
