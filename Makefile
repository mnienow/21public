CHECK = checker

PUSH = push_swap

COMMON = lists.c valider.c ops.c atol.c

SRCS1 = parser.c

SRCS2 = push.c sort.c new.c

LIB = ft_atoi.c ft_itoa.c ft_strcmp.c ft_strlen.c \
get_next_line.c ft_bzero.c ft_lstadd.c ft_lstnew.c \
ft_strdup.c ft_strjoin.c ft_strnew.c ft_strsub.c \
ft_memcpy.c ft_strcat.c ft_strcpy.c ft_strncpy.c \
ft_memdel.c ft_arrlen.c ft_isnumber.c ft_isdigit.c \
ft_strchr.c

MAIN1 = checker.c

MAIN2 = push_swap.c

SRC1 = $(addprefix $(OUT), $(LIB)) $(addprefix $(OUT1), $(MAIN1)) $(addprefix $(OUT1), $(SRCS1))

SRC2 = $(addprefix $(OUT), $(LIB)) $(addprefix $(OUT2), $(MAIN2)) $(addprefix $(OUT2), $(SRCS2))

SRCCOMM = $(addprefix $(COM), $(COMMON))

FLAGS = -Wall -Wextra -Werror

OUT1 = ./Check/

OUT2 = ./Push/

OUT = ./libft/

COM = ./Comm/

OUTPUT1 = $(MAIN1:.c=.o) $(LIB:.c=.o) $(SRCS1:.c=.o)

OUTPUT2 = $(MAIN2:.c=.o) $(LIB:.c=.o) $(SRCS2:.c=.o)

COMMOUT = $(COMMON:.c=.o)

all: 
	gcc $(SRC1) $(SRC2) $(SRCCOMM) -c $(FLAGS)
	gcc $(OUTPUT1) $(COMMOUT) -o $(CHECK) $(FLAGS)
	gcc $(OUTPUT2) $(COMMOUT) -o $(PUSH) $(FLAGS)

push:
	gcc $(SRC2) $(SRCCOMM) -c -std=c11 -ggdb3 $(FLAGS)
	gcc $(OUTPUT2) $(COMMOUT) -o $(PUSH) -std=c11 -ggdb3 $(FLAGS)

check:
	gcc $(SRC1) $(SRCCOMM) -c -std=c11 -ggdb3 $(FLAGS)
	gcc $(OUTPUT1) $(COMMOUT) -o $(CHECK) -std=c11 -ggdb3 $(FLAGS)

clean:
	make -C ./libft clean
	/bin/rm -f $(OUTPUT1)
	/bin/rm -f $(OUTPUT2)
	/bin/rm -f $(COMMOUT)

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(CHECK)
	/bin/rm -f $(PUSH)

re: fclean all
