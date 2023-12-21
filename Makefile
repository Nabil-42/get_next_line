# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabil <nabil@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 10:28:40 by nabboud           #+#    #+#              #
#    Updated: 2023/12/19 20:34:24 by nabil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# VARIABLES

NAME	=	get_next_line
CC	=	cc 
CCFLAGS	=	-Wall -Wextra -Werror -D BUFFER_SIZE=30

BIN	=	bin
SRC = get_next_line_utils.c \
	get_next_line.c \

OBJ	=	$(addprefix $(BIN)/, $(SRC:.c=.o))


# **************************************************************************** #
# COLORS

GREEN		= \033[0;32m
GREY		= \033[1;30m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
CYAN		= \033[0;36m
END_COLOR	= \033[0;39m


# **************************************************************************** #
# RULES

all: $(NAME)

$(BIN)/%.o: src/%.c | $(BIN)
	@echo "$(BLUE)[Compiling]$(END_COLOR) $<"
	@$(CC) $(CCFLAGS) -c $< -o $@

$(BIN):
	@echo "$(YELLOW)[BIN]$(END_COLOR) Creating bin folder"
	@mkdir -p $(BIN)

$(NAME): $(BIN) $(OBJ)
	@echo "$(CYAN)[Library]$(END_COLOR) Creating get_next_line"
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)[Success]$(END_COLOR) get_next_line is ready !"

clean:
	@rm -rf $(BIN)
	@echo "$(GREY)[Clean]$(END_COLOR) Objects have been deleted !"

fclean:	clean
	@rm -rf $(NAME) a.out
	@echo "$(GREY)[Clean]$(END_COLOR) get_next_line & executable has been deleted !"

re: fclean all

.PHONY: all clean fclean re