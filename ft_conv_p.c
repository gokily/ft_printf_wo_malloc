/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:29:15 by gly               #+#    #+#             */
/*   Updated: 2019/03/14 14:36:47 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_conv_p(t_conv conv, va_list ap)
{
	size_t	addr;
	int		len;

	addr = va_arg(ap, size_t);
	conv.len = ft_size_tlen_base(addr, 16);
	len = conv.acc > conv.len ? conv.acc : conv.len;
	ft_add_wd_acc_unsigned(addr, conv, len + 2, conv.width > len + 2 ? 1 : 0);
}
