/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:05:57 by gly               #+#    #+#             */
/*   Updated: 2019/03/14 16:44:44 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	*ft_strfill_space(char *str, int start, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		str[start] = ' ';
		start++;
		i++;
	}
	return (str);
}

char	*ft_strfill_zero(char *str, int start, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		str[start] = '0';
		start++;
		i++;
	}
	return (str);
}

int		ft_strfill_llu_base(char *str, unsigned long long nb, char *base)
{
	int					i;
	unsigned long long	l_base;
	unsigned long long	power;

	l_base = ft_strlen(base);
	power = 1;
	i = 0;
	while (nb / power >= l_base)
		power *= l_base;
	while (power > 0)
	{
		str[i] = base[nb / power];
		nb %= power;
		power /= l_base;
		i++;
	}
	return (i);
}

int		ft_strfill_ll_base(char *str, long long nb, char *base)
{
	int					i;
	long long	l_base;
	long long	power;

	l_base = ft_strlen(base);
	power = nb >= 0 ? 1 : -1;
	power *= (nb >= l_base || nb <= -l_base) ? l_base : 1;
	i = 0;
	while (nb / power >= l_base)
		power *= l_base;
	while (power != 0)
	{
		str[i] = base[nb / power];
		nb %= power;
		power /= l_base;
		i++;
	}
	return (i);
}
