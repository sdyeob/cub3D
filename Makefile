NAME := cub3D
CC := cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

LIB := libft.a
LIB_DIR := ./libft
LIBMLX := libmlx.a
DYLD_LIBRARY_PATH := ./minilibx_opengl_20191021

INCLUDES := includes

SRCS := $(addprefix srcs/, main.c err_detect.c utils.c ) \
		$(addprefix srcs/inspect/, inspect.c ) \
		$(addprefix srcs/parsing/, parsing_identifier.c \
			parsing_color.c parsing_map.c parsing_map2.c \
			map_list.c map_validity.c ) \
		$(addprefix srcs/draw/, color.c draw_cub3d.c hook.c \
		render_frame.c render_frame_utils.c vector.c \
		render_minimap.c move.c door.c)

OBJS := $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :: $(LIB)
$(NAME) :: $(LIBMLX)
$(NAME) :: $(OBJS)
	$(CC) $(CFLAGS) $(LIB) $(LIBMLX) -framework OpenGL -framework Appkit -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -I$(DYLD_LIBRARY_PATH) -I$(LIB_DIR) -I$(INCLUDES) -c -o $@ $<

$(LIB) :
	make -C $(LIB_DIR) all
	cp $(LIB_DIR)/$(LIB) $(LIB)

$(LIBMLX) :
	make -C $(DYLD_LIBRARY_PATH) all
	cp $(DYLD_LIBRARY_PATH)/$(LIBMLX) $(LIBMLX)

clean :
	$(RM) $(OBJS) $(LIB) $(LIBMLX)

fclean :
	make clean
	make -C $(LIB_DIR) fclean
	make -C $(DYLD_LIBRARY_PATH) clean
	$(RM) $(LIB)
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
