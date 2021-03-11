# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/13 14:48:42 by jtrancos          #+#    #+#              #
#    Updated: 2021/03/11 19:18:10 by jtrancos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_strlen.s\
				ft_strcpy.s\
				ft_strcmp.s

OBJS		= ${SRCS:.s=.o}
NAME		= libasm.a
NA			= nasm
NA_FLAGS	= -f macho64
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra
TEST		= test
.s.o:
				${NA} ${NA_FLAGS} $<

${NAME}:		${OBJS}
				ar rcs ${NAME} ${OBJS}

all:			${NAME}

clean:			
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME} libasm.a

re:				fclean all

test:			${NAME}
				gcc ${CFLAGS} -L . -lasm -o ${TEST} main.c

.PHONY:			all clean fclean re




