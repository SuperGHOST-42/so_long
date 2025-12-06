CC = cc
CFLAGS = -Wall -Wextra -Werror
DEPS = includes
SRCDIR = .
OBJDIR = obj

SRCS = ft_printf.c ft_utils.c

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

NAME = libftprintf.a

all: $(NAME)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I $(DEPS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re