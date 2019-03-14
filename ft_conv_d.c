/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:29:15 by gly               #+#    #+#             */
/*   Updated: 2019/03/14 16:40:05 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include "ft_printf.h"
#include "libft/libft.h"

void	ft_str_add_flags(char *str, int *pos, t_conv conv, long long nb)
{
	if (nb < 0)
	{
		str[*pos] = '-';
		(*pos)++;
	}
	else if (conv.flag & PLUS)
	{
		str[*pos] = '+';
		(*pos)++;
	}
	else if (conv.flag & SPACE)
	{
		str[*pos] = ' ';
		(*pos)++;
	}
}

static void	ft_add_width_acc(long long nb, t_conv conv, int len, int flag)
{
	char	str[flag == 1 ? conv.width + 1 : len + 1];
	int		pos;

	pos = (flag == 1 && conv.flag & MINUS) ? len : 0;
	if (flag == 1)
	{
		if (conv.flag & ZERO && !(conv.flag & ACC) && !(conv.flag & MINUS))
			ft_strfill_zero(str + pos, 0, conv.width - len);
		else
			ft_strfill_space(str + pos, 0, conv.width - len);
		pos = pos == 0 ? conv.width - len : 0;
	}
	ft_str_add_flags(str, &pos, conv, nb);
	if (conv.acc > conv.len)
	{
		ft_strfill_zero(str, pos, conv.acc - conv.len);
		pos += conv.acc - conv.len;
	}
	ft_strfill_ll_base(str + pos, nb, "0123456789");
	str[flag == 1 ? conv.width : len] = '\0';
	ft_add_to_buffer(str, flag == 1 ? conv.width : len);
}

static void	ft_conv_d2(t_conv conv, long long nb)
{
	int		len;

	if (conv.flag & CHAR)
		nb = (char)nb;
	else if (conv.flag & SHORT)
		nb = (short)nb;
	conv.len = ft_longlonglen_base(nb, 10);
	len = conv.acc > conv.len ? conv.acc : conv.len;
	len += (conv.flag & PLUS || conv.flag & SPACE || nb < 0) ? 1 : 0;
	ft_add_width_acc(nb, conv, len, conv.width > len ? 1 : 0);
}

void		ft_conv_d(t_conv conv, va_list ap)
{
	if (conv.flag & JAY)
		ft_conv_d2(conv, va_arg(ap, intmax_t));
	else if (conv.flag & LLNG)
		ft_conv_d2(conv, va_arg(ap, long long));
	else if (conv.flag & ZED)
		ft_conv_d2(conv, va_arg(ap, size_t));
	else if (conv.flag & LONG)
		ft_conv_d2(conv, va_arg(ap, long));
	else if (conv.flag & TEE)
		ft_conv_d2(conv, va_arg(ap, ptrdiff_t));
	else
		ft_conv_d2(conv, va_arg(ap, int));
}
