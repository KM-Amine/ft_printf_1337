NAME = libftprintf.a
CC = cc
RM = rm -rf
AR = ar rcs
SRC = ft_printf.c put_functions.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -I .
HEADER = ft_printf.h

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $@ $^

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ 
clean : 
	$(RM) $(OBJ)
fclean : clean
	$(RM) $(NAME)
re : fclean all