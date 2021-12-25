# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/07 20:34:37 by a1111             #+#    #+#              #
#    Updated: 2021/12/25 21:38:18 by a1111            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

LIBS	=	-I ./ -L ./ -l mlx \
			-I ft -framework OpenGL -framework Appkit

SRCS	=	so_long.c			errors_one.c				errors_two.c \
			movement.c			game_interface_one.c		game_interface_two.c \
			init_structs.c		parsing_one.c				parsing_two.c \
			putstr.c

OBJS	=	${SRCS:.c=.o}
OBJSD	=	${SRCS:.c=.d}

RM		=	rm

all		:	${NAME}

${NAME}	:	${OBJS}
	${CC} ${FLAGS} ${LIBS} -o ${NAME} ${OBJS}

%.o		:	%.c
	${CC} ${FLAGS} -c $< -o $@ -MD

include $(wildcard ${OBJSD})

clean	:
	${RM} -f ${OBJS} ${OBJSD}

fclean	:	clean
	${RM} -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re