SRCS	=	$(wildcard arraygraph/*.c) \
			$(wildcard arrayheap/*.c) \
			$(wildcard srcs/*.c)

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

NAME	=	mst

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re


