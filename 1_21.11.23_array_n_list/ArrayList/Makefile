SRCS = arraylist.c main_arraylist.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = arraylist

all  : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re  : fclean all

.PHONY : all clean fclean re


