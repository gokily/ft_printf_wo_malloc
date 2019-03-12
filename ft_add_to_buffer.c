/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 08:49:44 by gly               #+#    #+#             */
/*   Updated: 2019/03/12 15:54:42 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_printf.h"

int		ft_add_to_buffer(char *str)
{
	static char	buf[BUFFSIZE];
	static int	ret = 0;
	static int	i = 0;
	int			len;

	if (str == NULL)
	{
		write(1, buf, i);
		return (ret);
	}
	len = ft_strlen(str);
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
