#colors

RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m
YELLOW = \033[0;33m
MAGENTA = \033[0;35m

#program variables

PROG = sort_exe
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

#compiler variables

CC = gcc
CFLAGS = -Wall -pedantic -Werror -Wextra -std=gnu89

#rules

build: $(PROG)

$(PROG): $(OBJ)
	@echo -e "$(YELLOW)In process... to compile the $(MAGENTA)$(PROG)$(NC)"
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(GREEN)$(PROG) compiled$(NC)"

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $<

run: build
	@./$(PROG)

clear:
	@rm -rf $(OBJ) $(PROG)
	@if [ ! -f $(PROG) ]; then \
		echo -e "$(GREEN)$(PROG) deleted$(NC)"; \
	else \
		echo -e "$(RED)$(PROG) not deleted$(NC)"; \
	fi

.PHONY: build run clear