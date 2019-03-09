# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sstannis <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 19:40:56 by sstannis          #+#    #+#              #
#    Updated: 2018/11/29 19:58:29 by sstannis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_strlen.c ft_memset.c ft_bzero.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strcat.c \
ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_putchar.c ft_putstr.c \
ft_putnbr.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
ft_striter.c ft_striteri.c ft_strmap.c ft_striteri.c ft_strequ.c ft_strnequ.c \
ft_strsub.c ft_strjoin.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_strtrim.c ft_itoa.c ft_strsplit.c ft_wordcount.c \
ft_strmapi.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
ft_lstmap.c ft_strlowcase.c ft_strndup.c ft_strupcase.c ft_sqrt.c ft_range.c \
get_next_line.c
OUTPUT = ft_*.o

all: $(NAME)
$(NAME):
	gcc -Wall -Wextra -Werror $(SRCS) -c libft.h
	ar rc $(NAME) $(OUTPUT)

clean:
	/bin/rm -f $(OUTPUT)

fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
