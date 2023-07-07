NAME := cub3D
CC := gcc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
RM = rm -rf

LIB := libft.a
LIB_DIR := ./libft

INCLUDES := includes

SRCS := $(addprefix srcs/, main.c err.c ) $(addprefix srcs/inspect/, inspect.c )
OBJS := $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :: $(LIB)
$(NAME) :: $(OBJS)
	$(CC) $(CFLAGS) $(LIB) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -I$(LIB_DIR) -I$(INCLUDES) -c -o $@ $<

$(LIB) :
	make -C $(LIB_DIR) all
	cp $(LIB_DIR)/$(LIB) $(LIB)

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(LIB)
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
