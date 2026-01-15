NAME = push_swap
SRC = push_swap.c parsing_one.c parsing_two.c instructions1.c instructions2.c instructions3.c instructions4.c big_algo.c small_algo.c function_algo.c
OBJS = $(SRC:.c=.o)
CC = cc 
CFLAGS = -Wall -Wextra -Werror
HEADER = push_swap.h 
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re