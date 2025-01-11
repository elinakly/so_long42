NAME = libftprintf.a
OBJS_DIR = objs
CFLAGS = -Wall -Werror -Wextra
CC = cc

SRC = ft_printf.c \
      ft_putchar.c \
      ft_putnbr.c \
      ft_putstr.c \
      ft_heximal.c \
      ft_undecimal.c 

OBJS = $(SRC:%.c=$(OBJS_DIR)/%.o)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<


all: $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS) 


clean:
	rm -rf $(OBJS_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean