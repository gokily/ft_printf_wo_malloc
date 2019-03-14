/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 09:02:25 by gly               #+#    #+#             */
/*   Updated: 2019/03/14 13:04:37 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	ft_add_str_to_buf(const char *format, int i, int len)
{
	char	str[len + 1];
	int		j;

	j = 0;
	while (j < len)
	{
		str[j] = format[i + j];
		j++;
	}
	str[len] = '\0';
	ft_add_to_buffer(str, len);
}

int		ft_add_str(const char *format, int i)
{
	int		len;

	len = 0;
	while (format[i + len] != '\0' && format[i + len] != '%')
		len++;
	ft_add_str_to_buf(format, i, len);
	return (i + len);
}
