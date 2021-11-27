NAME = libftprintf.a

HEADERS = ft_printf.h libft/libft.h

LIBFT_SRCS = ft_itoa.c\
			ft_putchar_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_strlen.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_memset.c\
			ft_strncmp.c

SRCS =	ft_printf.c\
		ft_printf_utils1.c\
		ft_printf_utils2.c\
		$(addprefix libft/, $(LIBFT_SRCS))

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

AR = ar -rcs

all: $(NAME)

$(NAME):$(OBJS) $(HEADERS)
	$(AR) $(NAME) $(OBJS) 

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean
