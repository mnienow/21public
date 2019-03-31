NAME = checker

SRCS = ./Check/main.c ./Check/lsts.c ./Check/ops.c ./libft/ft_atoi.c \
./libft/ft_itoa.c ./libft/ft_strcmp.c ./libft/ft_strlen.c \
./libft/get_next_line.c ./libft/ft_bzero.c ./libft/ft_lstadd.c \
./libft/ft_lstnew.c ./libft/ft_strdup.c ./libft/ft_strjoin.c \
./libft/ft_strnew.c ./libft/ft_strsub.c ./libft/ft_memcpy.c \
./libft/ft_strcat.c ./libft/ft_strcpy.c ./libft/ft_strncpy.c \
./libft/ft_memdel.c

FLAGS = -Wall -Wextra -Werror

OUTPUT = *.o

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS) -c -I ./Check
	gcc $(OUTPUT) -I ./Check -o $(NAME)

clean:
	make -C ./libft clean
	/bin/rm -f $(OUTPUT) rm -f ft_printf.h.gch

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME)

re: fclean all