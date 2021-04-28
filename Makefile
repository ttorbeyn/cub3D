# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/26 18:56:41 by ttorbeyn          #+#    #+#              #
#    Updated: 2021/04/26 18:56:43 by ttorbeyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

INCLUDE			=	-I include

FRAMEWORKS		=	-lmlx -framework OpenGL -framework AppKit

SRC				=	parsing.c \
					get_next_line.c \
					get_next_line_utils.c \

OBJS			=	$(SRC:.c=.o)

RM				= 	@rm -f

NAME			=	cub3D

all: 		$(NAME)

$(NAME):
			@$(CC) $(FRAMEWORKS) $(CFLAGS) $(SRC) $(INCLUDE) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) cub3D

re:			fclean all

.PHONY:		all clean fclean re save
