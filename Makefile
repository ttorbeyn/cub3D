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

LIBFT			=	@ cd libft && make ;

SRC				=				libft/libft.a \
								ft_cub3D.c \
								ft_set.c \
								ft_raycasting.c \
								ft_mlx_utils.c \
								ft_key.c \
								ft_draw.c \
								ft_parsing.c \
								ft_parsing_text.c \
								ft_parsing_map.c \
								ft_parsing_utils.c \
								ft_utils.c \
								gnl/get_next_line.c

OBJS			=	$(SRC:.c=.o)

RM				= 	@rm -f

NAME			=	cub3D

all: 		$(NAME)

$(NAME):
			@$(LIBFT)w
			@$(CC) $(FRAMEWORKS) $(CFLAGS) $(SRC) $(INCLUDE) -o $(NAME)

clean:
			@cd libft && make clean
			$(RM) $(OBJS)

fclean:		clean
			$(RM) cub3D

re:			fclean all

.PHONY:		all clean fclean re save
