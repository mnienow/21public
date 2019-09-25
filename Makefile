NAME = checker

PUSH = push_swap

COMMON = ./Common/lists.c

SRCS = check.c ops.c atol.c

LIB = ft_atoi.c ft_itoa.c ft_strcmp.c ft_strlen.c \
get_next_line.c ft_bzero.c ft_lstadd.c ft_lstnew.c \
ft_strdup.c ft_strjoin.c ft_strnew.c ft_strsub.c \
ft_memcpy.c ft_strcat.c ft_strcpy.c ft_strncpy.c \
ft_memdel.c

MAIN1 = main_check.c

MAIN2 = main_push.c

SRC1 = $(addprefix $(OUT1), $(SRCS)) $(addprefix $(OUT), $(LIB)) $(addprefix $(OUT1), $(MAIN1)) $(COMMON)

SRC2 = $(addprefix $(OUT1), $(SRCS)) $(addprefix $(OUT), $(LIB)) $(addprefix $(OUT2), $(MAIN2)) $(COMMON)

FLAGS = -Wall -Wextra -Werror

OUT1 = ./Check/

OUT2 = ./Push/

OUT = ./libft/

OUTPUT1 = $(SRCS:.c=.o) $(MAIN1:.c=.o) $(LIB:.c=.o)

OUTPUT2 = $(SRCS:.c=.o) $(MAIN2:.c=.o) $(LIB:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC1) -c
	gcc $(OUTPUT1) -o $(NAME)

.PHONY: push

push:
	gcc $(FLAGS) $(SRC2) -c -std=c11 -ggdb3
	gcc $(OUTPUT2) -o $(PUSH) -std=c11 -ggdb3 $(FLAGS) 

clean:
	make -C ./libft clean
	/bin/rm -f $(OUTPUT1) rm -f ft_printf.h.gch

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME)
	/bin/rm -f $(PUSH)

re: fclean all
