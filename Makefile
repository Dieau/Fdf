# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 09:38:54 by alakhdar          #+#    #+#              #
#    Updated: 2022/02/22 14:02:11 by alakhdar         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS		= 	src/main.c src/check_errors.c src/get_next_line_fdf.c src/free.c src/handle_keys.c src/iso.c src/parse.c src/utils.c src/image.c
HEADER		=	includes/fdf.h includes/get_next_line.h libft/libft.h includes/alias.h
OBJS		= ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -rf

all: lib ${NAME}

$(NAME) : ${SRCS} $(HEADER) Makefile
	@$(CC) $(CFLAGS) $(SRCS) libft/libft.a -L minilibx -I minilibx libmlx.dylib -framework OpenGL -framework AppKit -o ${NAME}
	@echo "\033[92m\n[- COMPILATION COMPLETE -]\n\033[0m"
	@echo "\033[94m\n[- PLEASE LAUNCH FDF WITH A MAP AS AN ARGUMENT -]\n\033[0m"

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

lib:
	@make -C libft

clean :
	$(RM) fdf
	$(RM) src/*.o
	$(RM) libft/*.o
	@echo "\033[91m\n[- FILES DELETED -]\n\033[0m"

fclean : clean

re : fclean all

.PHONY : all clean bonus fclean re