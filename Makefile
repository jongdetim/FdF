# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tide-jon <tide-jon@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/11 17:51:16 by tide-jon       #+#    #+#                 #
#    Updated: 2019/05/24 19:44:56 by tide-jon      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		fdf

SRCS = 		main.c key_commands.c rotation.c drawing.c helpers.c offset.c

OBJECTS =	$(SRCS:.c=.o)

all :		$(NAME)

$(NAME) :	$(OBJECTS)
			@ cd minilibx_macos && make && cd .. && cd libft && make && cd ..
			@ gcc -Wall -Wextra -Werror $(OBJECTS) -L ./libft/ -lft \
			-L ./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
			@ gcc -c -Wall -Wextra -Werror $< -o $@ -I ./minilibx_macos/ -I ./libft/

clean :
			@ cd libft && make clean && cd .. && cd minilibx_macos && \
			make clean && cd .. && rm -f $(OBJECTS)

fclean :	clean
			@ cd libft && make fclean && cd .. && cd minilibx_macos && \
			rm -f libmlx.a && cd .. && rm -f $(NAME)

re :		fclean all
