# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tide-jon <tide-jon@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/28 18:20:08 by tide-jon       #+#    #+#                 #
#    Updated: 2019/04/03 15:17:22 by tide-jon      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
SOURCES = atoi bzero digcount isalnum isalpha isascii isdigit isprint \
iswhitespace itoa lstadd lstaddend lstdel lstdelone lstiter lstmap lstnew \
lstprintelemsizes memalloc memccpy memchr memcmp memcpy memdel memmove memset \
putchar_fd putchar putendl putnbr_fd putnbr putstr_fd putstr strcat strchr \
strclr strcmp strcount strcpy strdel strdup strequ striter strjoin strlcat \
strlen strmap strmapi strncat strncmp strncpy strnequ strnew strnstr strrchr \
strsplit strstr strsub strtrim tolower toupper putendl_fd striteri get_next_line
CFILE = $(SOURCES:%=ft_%.c)
OUT = $(SOURCES:%=ft_%.o)
INCLUDES = ./libft.h
NAME = libft.a

all: $(NAME)

$(NAME): $(OUT)
	@ar rc $(NAME) $(OUT)
	@ranlib $(NAME)
	@echo "Library succesfully created"

%.o: %.c
	@$(CC) $(CFLAGS) $< -o $@ -I $(INCLUDES)

clean:
	@rm -f $(OUT)
	@echo "Clean completed"

fclean: clean
	@rm -f $(NAME)

re: fclean all
