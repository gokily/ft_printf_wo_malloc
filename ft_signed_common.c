/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_common.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:35:22 by gly               #+#    #+#             */
/*   Updated: 2019/03/15 13:35:25 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
