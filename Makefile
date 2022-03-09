NAME = libftprintf.a

HEADERS = ft_printf.h libft/libft.h

LIBFT = Libft/*.o

SRCS =	ft_printf.c\
		ft_printf_utils1.c\
		ft_printf_utils2.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

AR = ar -rcs

all: $(NAME)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME):$(OBJS) $(HEADERS) $(LIBFT)
	$(AR) $(NAME) $(LIBFT) $(OBJS)

$(LIBFT):
	make -C Libft/

clean:
	$(RM) $(OBJS) $(LIBFT)

fclean:clean
	$(RM) $(NAME) Libft/libft.a

re: fclean all

.PHONY: all clean fclean
