# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tide-jon <tide-jon@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/11 17:51:16 by tide-jon       #+#    #+#                 #
#    Updated: 2019/05/23 20:41:23 by tide-jon      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fdf

OBJECTS =	$(SRCS:.c=.o)

SRCS = 		main.c key_commands.c rotation.c drawing.c helpers.c

all :		$(NAME)

$(NAME) :	$(OBJECTS)
			@ gcc -Wall -Wextra -Werror $(OBJECTS) -L ./libft/ -lft \
			-L ./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJECTS) : $(SRCS) libs
			@ gcc -c -Wall -Wextra -Werror $(SRCS) -I ./minilibx_macos/ -I ./libft/

libs :
			@ cd libft && make && cd .. && cd minilibx_macos && make && cd ..

clean :
			@ cd libft && make clean && cd .. && cd minilibx_macos && \
			make clean && cd .. && rm -f $(OBJECTS)

fclean :	clean
			@ cd libft && make fclean && cd .. && cd minilibx_macos && \
			rm -f libmlx.a && cd .. && rm -f $(NAME)

re :		fclean all
