SRCS_ARRAY = arraylist.c main_arraylist.c
SRCS_LINKED = linkedlist.c main_linkedlist.c

OBJS_ARRAY = $(SRCS_ARRAY:.c=.o)
OBJS_LINKED = $(SRCS_LINKED:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME_ARRAY = arraylist
NAME_LINKED = linkedlist

all  : $(NAME_ARRAY) $(NAME_LINKED)

$(NAME_ARRAY) : $(OBJS_ARRAY)
		$(CC) $(CFLAGS) -o $(NAME_ARRAY) $(OBJS_ARRAY)
$(NAME_LINKED) : $(OBJS_LINKED)
		$(CC) $(CFLAGS) -o $(NAME_LINKED) $(OBJS_LINKED)

clean :
		rm -f $(OBJS_ARRAY) $(OBJS_LINKED)

fclean : clean
		rm -f $(NAME_ ARRAY) $(NAME_LINKED)

re  : fclean all

.PHONY : all clean fclean re


