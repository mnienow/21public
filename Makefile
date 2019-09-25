NAME = checker

PUSH = push_swap

COMMON = lists.c

SRCS1 = atol.c checker.c ops.c valider.c

SRCS2 = push.c sort.c new.c

LIB = ft_atoi.c ft_itoa.c ft_strcmp.c ft_strlen.c \
get_next_line.c ft_bzero.c ft_lstadd.c ft_lstnew.c \
ft_strdup.c ft_strjoin.c ft_strnew.c ft_strsub.c \
ft_memcpy.c ft_strcat.c ft_strcpy.c ft_strncpy.c \
ft_memdel.c ft_arrlen.c ft_isnumber.c ft_isdigit.c

MAIN1 = main_check.c

MAIN2 = main_push.c

SRC1 = $(addprefix $(OUT1), $(SRCS1)) $(addprefix $(OUT), $(LIB)) $(addprefix $(OUT1), $(MAIN1)) $(addprefix $(COM), $(COMMON))

SRC2 = $(addprefix $(OUT2), $(SRCS2)) $(addprefix $(OUT), $(LIB)) $(addprefix $(OUT2), $(MAIN2)) $(addprefix $(COM), $(COMMON))

FLAGS = -Wall -Wextra -Werror

OUT1 = ./Check/

OUT2 = ./Push/

OUT = ./libft/

COM = ./Comm/

OUTPUT1 = $(SRCS1:.c=.o) $(COMMON:.c=.o) $(MAIN1:.c=.o) $(LIB:.c=.o)

OUTPUT2 = $(SRCS2:.c=.o) $(COMMON:.c=.o) $(MAIN2:.c=.o) $(LIB:.c=.o)

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
	/bin/rm -f $(OUTPUT2)

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME)
	/bin/rm -f $(PUSH)

re: fclean all
