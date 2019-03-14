/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 08:49:44 by gly               #+#    #+#             */
/*   Updated: 2019/03/14 09:56:02 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_printf.h"

int		ft_add_to_buffer(char *str, int len)
{
	static char	buf[BUFFSIZE];
	static int	ret = 0;
	static int	i = 0;
	int			tmp;

	if (str == NULL)
	{
		write(1, buf, i);
		i = 0;
		tmp = ret;
		ret = 0;
		return (tmp);
	}
	if (i + len > BUFFSIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (len > BUFFSIZE)
		write(1, str, len);
	else
	{
		ft_strncpy(buf + i, str, len);
		i += len;
	}
	ret += len;
	return (ret);
}
