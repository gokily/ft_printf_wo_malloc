/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 09:42:58 by gly               #+#    #+#             */
/*   Updated: 2019/03/12 15:32:26 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#define BUFFSIZE 1024
# include <stdarg.h>

# include <stdio.h>

# define FLAG " -+#*.0123456789lh"
# define CONV "cspdiouxXf"
# define PLUS 1
# define MINUS 1 << 1
# define SPACE 1 << 2
# define POUND 1 << 3
# define ZERO 1 << 4
# define LONG 1 << 5
# define LLNG 1 << 6
# define LDOUBLE 1 << 7
# define SHORT 1 << 8
# define CHAR 1 << 9
# define ACC 1 << 10
# define CAPS 1 << 11

typedef struct	s_conv
{
	int			flag;
	int			width;
	int 		acc;
	int 		len;
	char		type;
	int			i;
}				t_conv;

int				ft_printf(const char *format, ...);

int				ft_add_to_buffer(char *str);
int				ft_add_str(const char *format, int i);
int				ft_add_conv(const char *format, va_list ap, int i);
int				ft_atoi_pf(const char *str, int *index);

void			ft_conv_c(t_conv conv, va_list ap);
#endif
