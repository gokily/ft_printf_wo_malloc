/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:05:18 by gly               #+#    #+#             */
/*   Updated: 2019/03/15 13:38:15 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include "ft_printf.h"
#include "libft/libft.h"

int		ft_baselen(t_conv conv)
{
	if (conv.type == 'u')
		return (10);
	else if (conv.type == 'o')
		return (8);
	else if (conv.type == 'b')
		return (2);
	else if (conv.type == 'x' || conv.type == 'X')
		return (16);
	return (0);
}

void	ft_conv_u2(t_conv conv, unsigned long long nb)
{
	int		len;

	if (conv.flag & CHAR)
		nb = (unsigned char)nb;
	else if (conv.flag & SHORT)
		nb = (unsigned short)nb;
	conv.len = ft_longlonglen_base(nb, ft_baselen(conv));
	len = conv.acc > conv.len ? conv.acc : conv.len;
	ft_add_wd_acc_unsigned(nb, conv, len, conv.width > len ? 1 : 0);
}

void	ft_conv_unsigned(t_conv conv, va_list ap)
{
	if (conv.flag & JAY)
		ft_conv_u2(conv, va_arg(ap, uintmax_t));
	else if (conv.flag & LLNG)
		ft_conv_u2(conv, va_arg(ap, unsigned long long));
	else if (conv.flag & ZED)
		ft_conv_u2(conv, va_arg(ap, size_t));
	else if (conv.flag & LONG)
		ft_conv_u2(conv, va_arg(ap, unsigned long));
	else if (conv.flag & TEE)
		ft_conv_u2(conv, va_arg(ap, ptrdiff_t));
	else
		ft_conv_u2(conv, va_arg(ap, unsigned int));
}
