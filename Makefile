NAME = so_long
SRC_DIR = src
LIBMLX = MLX42
HEADERS	:= -I ./include -I $(LIBMLX)/include 
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
OBJS_DIR  = objs
LIBS	:= $(LIBMLX)/build/libmlx42.a libft/libft.a printf/libftprintf.a -ldl -lglfw -pthread -lm

SRCS = main.c  get_next_line.c  get_next_line_utils.c hooks.c images.c  maps.c	map_validation.c position.c init_game.c valid_path.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: libmlx $(NAME)

libmlx: MLX42/.git
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

MLX42/.git:
	git submodule update --init MLX42

libft/libft.a:
	@make -C libft

printf/libftprintf.a:
	@make -C printf

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)


$(NAME): $(OBJS) libft/libft.a printf/libftprintf.a $(LIBMLX)/build/libmlx42.a
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)
	rm -rf $(LIBMLX)/build
	make -C libft clean
	make -C printf clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean
	make -C printf fclean

re: fclean all

.PHONY: all re fclean clean libmlx libft/libft.a printf/libftprintf.a