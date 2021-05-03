# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/27 13:05:00 by manmarti          #+#    #+#              #
#    Updated: 2021/05/03 17:58:51 by manmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c flags.c ./identifiers/integer.c ./identifiers/unsigned.c ./identifiers/str.c ./identifiers/char.c \
./aux/aux.c ./aux/int_flags.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

libft/libft.a: 
	$(MAKE) -C ./libft

$(NAME): libft/libft.a $(OBJS)
	cp libft/libft.a $(NAME)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	$(MAKE) fclean -C ./libft

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 