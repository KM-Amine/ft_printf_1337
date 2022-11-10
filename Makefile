CC = cc
CFLAGS = -Wall -Wextra -Werror -I .
RM = rm -rf
AR = ar rcs
SRC = ft_printf.c ft_printf_utils.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
HEADER = ft_printf.h

all: $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re 