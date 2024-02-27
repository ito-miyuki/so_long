NAME = so_long

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

MLX_DIR = ./MLX42
MLX42 = ./MLX42/build/libmlx42.a

SRCS =	read_map.c main.c valid_char_map.c valid_shape_map.c init_map_data.c init_structs.c \
		load_images.c render_map.c moves.c get_position.c valid_path_map.c remove_item.c

OBJS = $(SRCS:.c=.o)

CC = cc

##MLX42FLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

HEADERS	= -I ./include -I $(MLX_DIR)/include

CFLAGS = -Wall -Wextra -Werror -I./libft -g
#-g is for debugging, remove it before submitting

AR = ar rcs

RM = rm -f

all: $(NAME)

LDFLAGS = -L$(MLX_DIR)/build -L/Users/$(USER)/.brew/opt/glfw/lib

LIBS = -lmlx42 -ldl -lglfw -pthread -lm

$(NAME): $(LIBFT) $(MLX42) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS) $(HEADERS) $(LIBS) -L$(LIBFT_DIR) -lft 

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX42):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re

