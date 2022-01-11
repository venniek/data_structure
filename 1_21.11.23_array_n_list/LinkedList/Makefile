SRCS_LINKED = linkedlist.c main_linkedlist.c
OBJS_LINKED = $(SRCS_LINKED:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME_LINKED = linkedlist

all  : $(NAME_LINKED)

$(NAME_LINKED) : $(OBJS_LINKED)
		$(CC) $(CFLAGS) -o $(NAME_LINKED) $(OBJS_LINKED)

clean :
		rm -f $(OBJS_LINKED)

fclean : clean
		rm -f $(NAME_LINKED)

re  : fclean all

.PHONY : all clean fclean re


