# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 09:38:54 by alakhdar          #+#    #+#              #
#    Updated: 2022/03/07 13:55:03 by alakhdar         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = fdf
BONUS_NAME	= fdf_bonus
SRCS		= 	src/main.c src/check_errors.c src/get_next_line_fdf.c src/free.c src/iso.c src/parse.c src/utils.c src/image.c
HEADER		=	includes/fdf.h includes/get_next_line.h libft/libft.h includes/alias.h
BONUS		=	bonus/main.c bonus/check_errors.c bonus/get_next_line_fdf.c bonus/free.c bonus/handle_keys.c bonus/iso.c bonus/parse.c bonus/utils.c bonus/image.c
BONUSH		=	bonus/fdf_bonus.h bonus/get_next_line.h bonus/alias.h
OBJS		= ${SRCS:.c=.o}
BONUS_OBJ	= ${BONUS:.c=.o}

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

bonus : ${BONUS} $(BONUSH) Makefile
	@$(CC) $(CFLAGS) $(BONUS) libft/libft.a -L minilibx -I minilibx libmlx.dylib -framework OpenGL -framework AppKit -o ${BONUS_NAME}
	@echo "\033[92m\n[- BONUS COMPILATION COMPLETE -]\n\033[0m"
	@echo "\033[94m\n[- PLEASE LAUNCH FDF WITH A MAP AS AN ARGUMENT -]\n\033[0m"

clean :
	$(RM) fdf
	$(RM) fdf_bonus
	$(RM) src/*.o
	$(RM) bonus/*.o
	$(RM) libft/*.o
	@echo "\033[91m\n[- FILES DELETED -]\n\033[0m"

fclean : clean

re : fclean all

.PHONY : all clean bonus fclean re