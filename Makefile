##
## ETNA PROJ, 
## Makefile
##

CC =	gcc -Wall -Wextra -Werror -std=c11
NAME =	./Release/my_crd/my_crd
SRC =		add_node.c \
		basic_creat_list.c \
		delete_inlist.c \
		display_data.c \
		lookup_node.c \
		my_crd.c \
		./libmy/my_getnbr.c \
		./libmy/my_readline.c \
		./libmy/my_str_to_word_array.c
HED =	my.h
OBJ =	$(SRC:%.c=%.o)
RM =	rm -f

$(NAME):	$(OBJ)
			$(CC) $(HED) $(OBJ) -o $(NAME)
all:	$(NAME)
clean:
		$(RM) $(OBJ)
fclean:	clean
		$(RM) $(NAME)
re:		fclean all
