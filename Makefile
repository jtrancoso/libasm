# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtrancos <jtrancos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/13 14:48:42 by jtrancos          #+#    #+#              #
#    Updated: 2021/04/05 17:57:20 by jtrancos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_strlen.s \
				ft_strcpy.s \
				ft_strcmp.s \
				ft_strdup.s \
				ft_write.s  \
				ft_read.s

OBJS		= ${SRCS:.s=.o}
NAME		= libasm.a
NA			= nasm
NA_FLAGS	= -f macho64
RM			= rm -f
#CFLAGS		= -Wall -Werror -Wextra
TEST		= test
.s.o:
				${NA} ${NA_FLAGS} $<

${NAME}:		${OBJS}
				ar rcs ${NAME} ${OBJS}

all:			${NAME}

clean:			
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME} ${TEST} libasm.a


re:				fclean all

test:			${NAME}
				gcc ${CFLAGS} -L . -lasm main.c -o ${TEST} 

.PHONY:			all clean fclean re




