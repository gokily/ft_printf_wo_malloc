/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:29:15 by gly               #+#    #+#             */
/*   Updated: 2019/03/14 11:39:38 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_add_width_acc(size_t addr, t_conv conv, int len, int flag)
{
	char	str[flag == 1 ? conv.width + 1 : len + 1];
	int		pos;

	pos = 0;
	if (flag == 1)
	{
		ft_strfill_space(str, 0, conv.width - 2 - len);
		pos = conv.width - len - 2;
	}
	ft_strncpy(str + pos, "0x", 2);
	pos += 2;
	if (conv.acc > conv.len)
	{
		ft_strfill_zero(str, pos, conv.acc - conv.len);
		pos += conv.acc - conv.len;
	}
	ft_strfill_llu_base(str + pos, addr, "0123456789abcdef");
	str[pos + conv.len] = '\0';
	ft_add_to_buffer(str, pos + conv.len);
}

void	ft_conv_p(t_conv conv, va_list ap)
{
	size_t	addr;
	int		len;

	addr = va_arg(ap, size_t);
	conv.len = ft_size_tlen_base(addr, 16);
	len = conv.acc > conv.len ? conv.acc : conv.len;
	ft_add_width_acc(addr, conv, len, conv.width > len + 2 ? 1 : 0);
}
