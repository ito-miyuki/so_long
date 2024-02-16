NAME = so_long

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

MLX_DIR = ./MLX42

SRCS =	read_map.c main.c valid_char_map.c valid_shape_map.c map_validation.c init_structs.c

OBJS = $(SRCS:.c=.o)

CC = cc

HEADERS	= -I ./include -I $(MLX_DIR)/include

CFLAGS = -Wall -Wextra -Werror -I./libft -g
#-g is for debugging, remove it before submitting

AR = ar rcs

RM = rm -f

all: $(NAME)

LDFLAGS = -L$(MLX_DIR)/build -L/Users/mito/.brew/opt/glfw/lib
LIBS = -lmlx42 -ldl -lglfw -pthread -lm

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)
	$(RM) $(MLX_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re

