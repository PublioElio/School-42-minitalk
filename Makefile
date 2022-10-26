# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adiaz-be <adiaz-be@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 17:05:55 by adiaz-be          #+#    #+#              #
#    Updated: 2022/10/24 17:06:01 by adiaz-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

INC = -Iinclude/ -Ilibft/

LIBFT = ./libft/libft.a

SERVER = server
SRCS_SERVER = ./srcs/server.c

CLIENT = client
SRCS_CLIENT = ./srcs/client.c

all: $(SERVER) $(CLIENT)

$(SERVER): $(LIBFT) $(SRCS_SERVER)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT) -o $(SERVER) $(SRCS_SERVER)
	@echo "\n🖥 $(GREEN) Server is ready$(RESET) ✅\n"

$(CLIENT): $(LIBFT) $(SRCS_CLIENT)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT) -o $(CLIENT) $(SRCS_CLIENT)
	@echo "\n🖥 $(GREEN) Client is ready$(RESET) ✅\n"

$(LIBFT):
	@make -C libft --silent
	@echo "\n📕 $(GREEN)Libft is ready$(RESET) ✅\n"

clean:
	@make -C libft clean --silent
	@echo "\n🚮 $(RED) Binary files removed $(RESET) 🧹\n"

fclean: clean
	@make -C libft fclean --silent
	@$(RM) $(CLIENT) $(SERVER)
	@echo "\n🚮 $(RED) Executable files removed $(RESET) 🧹\n"

re: fclean all

.PHONY: all clean fclean re