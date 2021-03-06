# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gly <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/12 09:31:19 by gly               #+#    #+#              #
#    Updated: 2019/03/15 18:14:59 by gly              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	ft_printf.c	\
			ft_add_str.c	\
			ft_add_conv.c	\
			ft_add_to_buffer.c	\
			ft_util.c	\
			ft_unsigned_common.c	\
			ft_signed_common.c	\
			ft_conv_cper.c	\
			ft_conv_s.c	\
			ft_conv_p.c	\
			ft_conv_d.c	\
			ft_conv_u.c	\
			ft_conv_f.c	\

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIBFTDIR	=	libft

LIBFT	=	$(LIBFTDIR)/libft.a

all		:	$(NAME)

$(NAME)	:	$(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJ)

$(LIBFT):
	make -C $(LIBFTDIR)

%.o		:	%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	make -C $(LIBFTDIR) clean
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(LIBFT) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
