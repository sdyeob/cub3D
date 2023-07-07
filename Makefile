NAME := cub3D
CC := gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

LBI := libft.a
LIB_DIR := libft

INCLUDES := includes

SRCS := 
OBJS := $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :: $()
$(NAME) :: $(OBJS)
	$(CC) $(CFLAGS) $(LIB) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -I$(LIB) -I$(LIB_DIR) -I$(INCLUDES) -c -o $@ $<

$(LIB) :
	make -C $(LIB_DIR) all
	cp $(LIB_DIR)/$(LIB) $(LIB)

clean :
	$(RM) $(OBJS)

fclean :
	make clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
