/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:36:49 by gly               #+#    #+#             */
/*   Updated: 2019/03/12 15:54:20 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_add_width(char c, int width, int flag)
{
	char	str[width + 1];
	int		i;

	i = 0;
	while (i < width)
	{
		str[i] = ' ';
		i++;
	}
	if (flag)
		str[0] = c;
	else
		str[width - 1] = c;
	str[width] = '\0';
	ft_add_to_buffer(str);
}

void	ft_conv_c(t_conv conv, va_list ap)
{
	char c;

	c = va_arg(ap, int);
	ft_add_width(c, conv.width > 1 ? conv.width : 1, conv.flag & MINUS);
}
