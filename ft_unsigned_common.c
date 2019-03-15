/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_common.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:52:56 by gly               #+#    #+#             */
/*   Updated: 2019/03/15 13:38:58 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_prefix_len(t_conv conv)
{
	if (conv.type == 'p')
		return (2);
	else if (ft_strchr("bo", conv.type) && conv.flag & POUND)
		return (1);
	else if (ft_strchr("xX", conv.type) && conv.flag & POUND)
		return (2);
	return (0);
}

void	ft_putprefix(char *str, t_conv conv)
{
	if (conv.type == 'p')
		ft_strncpy(str, "0x", 2);
	else if (conv.flag & POUND)
	{
		if (conv.type == 'b')
			ft_strncpy(str, "b", 1);
		else if (conv.type == 'o')
			ft_strncpy(str, "0", 1);
		else if (conv.type == 'x')
			ft_strncpy(str, "0x", 2);
		else if (conv.type == 'X')
			ft_strncpy(str, "0X", 2);
	}
}

void	ft_strfill_nb(char *str, unsigned long long nb, t_conv conv)
{
	if (conv.type == 'u')
		ft_strfill_llu_base(str, nb, "0123456789");
	else if (conv.type == 'o')
		ft_strfill_llu_base(str, nb, "01234567");
	else if (conv.type == 'b')
		ft_strfill_llu_base(str, nb, "01");
	else if (conv.type == 'x' || conv.type == 'p')
		ft_strfill_llu_base(str, nb, "0123456789abcdef");
	else if (conv.type == 'X')
		ft_strfill_llu_base(str, nb, "0123456789ABCDEF");
}

void	ft_add_wd_acc_unsigned(unsigned long long nb, t_conv conv,
	int len, int flag)
{
	char	str[flag == 1 ? conv.width + 1 : len + 1];
	int		pos;
	int		prefix;

	prefix = ft_prefix_len(conv);
	pos = (flag == 1 && conv.flag & MINUS) ? len : 0;
	if (flag == 1)
	{
		if (conv.flag & ZERO && !(conv.flag & ACC) && !(conv.flag & MINUS))
			ft_strfill_zero(str + pos, 0, conv.width - len);
		else
			ft_strfill_space(str + pos, 0, conv.width - len);
		pos = pos == 0 ? conv.width - len : 0;
	}
	ft_putprefix(str + pos, conv);
	pos += prefix;
	if (conv.acc > conv.len)
	{
		ft_strfill_zero(str, pos, conv.acc - conv.len);
		pos += conv.acc - conv.len;
	}
	ft_strfill_nb(str + pos, nb, conv);
	str[flag == 1 ? conv.width : len] = '\0';
	ft_add_to_buffer(str, flag == 1 ? conv.width : len);
}
