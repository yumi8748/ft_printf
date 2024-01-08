# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 22:09:00 by yu-chen           #+#    #+#              #
#    Updated: 2023/12/01 19:20:09 by yu-chen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = srcs

SRC = ft_printf.c ft_util.c ft_padding.c ft_put.c

SRC := $(addprefix $(SRC_PATH)/,$(SRC))

OBJ = $(SRC:.c=.o)

CC = clang

CFLAGS = -Wall -Werror -Wextra -g3 -I.

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

all : $(NAME)

$(LIBFT) :
	make all -C $(LIBFT_PATH)

$(NAME) : $(LIBFT) ${OBJ}
	cp $(LIBFT) $(NAME)
	ar rcs ${NAME} ${OBJ}

bonus : $(NAME)

clean :
	make clean -C $(LIBFT_PATH)
	rm -f $(NAME) $(OBJ)

fclean : clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

c : ${NAME}
	${CC} -g3 -L. -lftprintf
	valgrind ./a.out
	rm ./a.out

re : fclean all

.PHONY : all clean fclean re