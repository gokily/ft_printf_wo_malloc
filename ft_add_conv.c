/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:45:24 by gly               #+#    #+#             */
/*   Updated: 2019/03/14 13:11:25 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft/libft.h"

void	ft_make_conv(t_conv conv, va_list ap)
{
	if (conv.type == 'c')
		ft_conv_c(conv, ap);
	else if (conv.type == 's')
		ft_conv_s(conv, ap);
	else if (conv.type == 'p')
		ft_conv_p(conv, ap);
	else if (conv.type == 'i' || conv.type == 'd')
		ft_conv_d(conv, ap);
/*	else if (conv.type == 'o')
		ft_conv_o(conv, ap);
	else if (conv.type == 'u')
		ft_conv_u(conv, ap);
	else if (conv.type == 'x' || conv.type == 'X')
		ft_conv_x(conv, ap);
	else if (conv.type == 'b')
		ft_conv_b(conv, ap);
	else if (conv.type == 'f')
		ft_conv_f(conv, ap);*/
}

t_conv	ft_parse_mod(const char *format, int i, t_conv conv)
{
	if (format[i] == 'l')
	{
		if (format[i + 1] == 'l')
			conv.flag |= LLNG;
		else if (!(conv.flag & LLNG))
			conv.flag |= LONG;
	}
	else if (format[i] == 'h')
	{
		if (format[i + 1] == 'h')
			conv.flag |= CHAR;
		else if (!(conv.flag & CHAR))
			conv.flag |= SHORT;
	}
	else if (format[i] == 'L')
		conv.flag |= LDOUBLE;
	else if (format[i] == 'j')
		conv.flag |= JAY;
	else if (format[i] == 'z')
		conv.flag |= ZED;
	else if (format[i] == 't')
		conv.flag |= TEE;
	return (conv);
}

t_conv	ft_parse_acc_wd(const char *format, va_list ap, int i, t_conv conv)
{
	if (format[i] == '*')
		conv.width = va_arg(ap, int);
	else if (format[i] >= '1' && format[i] <= '9')
		conv.width = ft_atoi_pf(format, &i);
	else if (format[i] == '.')
	{
		i++;
		conv.flag |= ACC;
		if (format[i] == '*')
			conv.acc = va_arg(ap, int);
		else if (format[i] >= '1' && format[i] <= '9')
			conv.acc = ft_atoi_pf(format, &i);
	}
	conv.i = i;
	return (conv);
}

t_conv	ft_parse_flag(const char *format, va_list ap, int i, t_conv conv)
{
	while (ft_strchr(FLAG, format[i]))
	{
		if (format[i] == '-')
			conv.flag |= MINUS;
		else if (format[i] == '+')
			conv.flag |= PLUS;
		else if (format[i] == '#')
			conv.flag |= POUND;
		else if (format[i] == ' ')
			conv.flag |= SPACE;
		else if (format[i] == '0')
			conv.flag |= ZERO;
		else
		{
			conv = ft_parse_mod(format, i, conv);
			conv = ft_parse_acc_wd(format, ap, i, conv);
			i = conv.i;
		}
		i++;
	}
	conv.i = i;
	conv.type = ft_strchr(CONV, format[i]) ? format[i] : 0;
	return (conv);
}

int		ft_add_conv(const char *format, va_list ap, int i)
{
	t_conv	conv;

	conv.i = i;
	conv.acc = 0;
	conv.width = 0;
	conv.flag = 0;
	conv.len = 0;
	conv = ft_parse_flag(format, ap, i, conv);
	if (conv.type == 0)
		return (ft_add_str(format, conv.i));
	if (conv.type == 'X')
		conv.flag |= CAPS;
	ft_make_conv(conv, ap);
	return (conv.i + 1);
}
