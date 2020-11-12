LIB = libft.a

FLAG = -Wall -Wextra -Werror -g
HEADER = include/

OPTION = -c -I

OBJS = $(SRCS:src/%.c=%.o) 

EXEC = bsq

SRCS =	src/main.c \
		src/tools.c \
		src/free.c \
		src/print_map.c \
		src/fill.c

all: $(LIB)

$(LIB) :
		@echo "\033[33m----------------------------------\033[0m"
		@echo "\033[36mCompiling in .o\033[0m"
		@gcc $(FLAG) $(OPTION) $(HEADER) $(SRCS)
		@echo "\033[36mCreating library\033[0m"
		@ar rc $(LIB) $(OBJS)
		@echo "\033[36mIncrease the search speed\033[0m"
		@ranlib $(LIB)
		@echo "\033[32mLibrary Created\033[0m"
		@gcc -o $(EXEC) $(LIB) -fsanitize=address

		@echo "\033[32mExecutable Created\033[0m"
		@echo "\033[33m----------------------------------\033[0m"

clean :
		@echo "\033[33m----------------------------------\033[0m"
		@echo "\033[31mDeleting all .o\033[31m"
		@rm -Rf $(OBJS)
		@echo "\033[32mThe folder is clean !\033[32m"
		@echo "\033[33m----------------------------------\033[0m"

fclean :
		@echo "\033[33m----------------------------------\033[0m"
		@echo "\033[31mDeleting Executable, Library.a and all .o\033[31m"
		@rm -Rf $(LIB) $(OBJS) $(EXEC)
		@echo "\033[32mThe folder is clean\033[32m"
		@echo "\033[33m----------------------------------\033[0m"

re : fclean all
