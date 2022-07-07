
RELATIVE = .
OBJ_PATH = .
SRC_NAME =	$(wildcard *.c)


OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(SRC_NAME)
OBJ = $(addprefix ,$(OBJ_NAME))
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INC = .
LIBFT_PATH = .
CPPFLAGS = -I$(INC)
NAME = $(LIBFT_PATH)/libft.a

.PHONY: clean fclean all re

all : $(NAME)


$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf '\033[1;32m%-100.100s\n\033[0m' 'Libft compiled successfully!'

$(OBJ_PATH)/%.o: $(SRC_PATH)%.c $(INC)/libft.h
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@printf "\033[2;36mObject %-50.100s [\033[0;32m✔\033[2;36m]\r" $@

clean:
	@rm -rf $(OBJ)
	@printf '\033[0;34m%s\n\033[0m' "Objects files deleted"

fclean: clean
	rm -rf $(NAME)

re : fclean all