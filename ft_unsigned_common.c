/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_common.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:52:56 by gly               #+#    #+#             */
/*   Updated: 2019/03/15 17:27:24 by gly              ###   ########.fr       */
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

int		ft_putprefix(unsigned long long nb, char *str, int pos, t_conv conv)
{
	int		len;

	if (nb == 0)
		return (pos);
	len = ft_prefix_len(conv);
	str += pos;
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
	return (pos + len);
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

	pos = (flag == 1 && conv.flag & MINUS) ? len : 0;
	if (flag == 1)
	{
		if (conv.flag & ZERO && !(conv.flag & ACC) && !(conv.flag & MINUS))
		{
			pos = ft_putprefix(nb, str, pos, conv);
			ft_strfill_zero(str + pos, 0, conv.width - len);
			flag = 2;
		}
		else
			ft_strfill_space(str + pos, 0, conv.width - len);
		pos = (pos == 0 || flag == 2) ? conv.width - len + pos : 0;
	}
	if (flag != 2)
		pos = ft_putprefix(nb, str, pos, conv);
	if (conv.acc > conv.len)
		pos = ft_strfill_zero(str, pos, conv.acc - conv.len);
	ft_strfill_nb(str + pos, nb, conv);
	str[flag >= 1 ? conv.width : len] = '\0';
	ft_add_to_buffer(str, flag >= 1 ? conv.width : len);
}
