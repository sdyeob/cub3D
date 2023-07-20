NAME := cub3D
NAME_B := cub3D_bonus
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
		render_frame.c render_frame_utils.c vector.c move.c)

SRCS_B := $(addprefix srcs_bonus/, main_bonus.c err_detect_bonus.c utils_bonus.c ) \
		$(addprefix srcs_bonus/inspect/, inspect_bonus.c ) \
		$(addprefix srcs_bonus/parsing/, parsing_identifier_bonus.c \
			parsing_color_bonus.c parsing_map_bonus.c parsing_map2_bonus.c \
			map_list_bonus.c map_validity_bonus.c ) \
		$(addprefix srcs_bonus/draw/, color_bonus.c draw_cub3d_bonus.c hook_bonus.c \
		render_frame_bonus.c render_frame_utils_bonus.c vector_bonus.c \
		render_minimap_bonus.c move_bonus.c door_bonus.c)

OBJS := $(SRCS:.c=.o)
OBJS_B := $(SRCS_B:.c=.o)

all : $(NAME)

bonus : $(NAME_B)

$(NAME_B) :: $(LIB)
$(NAME_B) :: $(LIBMLX)
$(NAME_B) :: $(OBJS_B)
	$(CC) $(CFLAGS) $(LIB) $(LIBMLX) -framework OpenGL -framework Appkit -o $@ $^

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
	$(RM) $(OBJS) $(OBJS_B) $(LIB) $(LIBMLX)

fclean :
	make clean
	make -C $(LIB_DIR) fclean
	make -C $(DYLD_LIBRARY_PATH) clean
	$(RM) $(LIB)
	$(RM) $(NAME)
	$(RM) $(NAME_B)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re
