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

SERVER_B = server_bonus
SRCS_SERVER_B = ./srcs_bonus/server_bonus.c

CLIENT_B = client_bonus
SRCS_CLIENT_B = ./srcs_bonus/client_bonus.c

all: $(SERVER) $(CLIENT)

$(SERVER): $(LIBFT) $(SRCS_SERVER)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT) -o $(SERVER) $(SRCS_SERVER)
	@echo "\nš„ $(GREEN) Server is ready$(RESET) ā\n"

$(CLIENT): $(LIBFT) $(SRCS_CLIENT)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT) -o $(CLIENT) $(SRCS_CLIENT)
	@echo "\nš„ $(GREEN) Client is ready$(RESET) ā\n"

$(SERVER_B): $(LIBFT) $(SRCS_SERVER_B)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT) -o $(SERVER_B) $(SRCS_SERVER_B)
	@echo "\nš„ $(GREEN) Server bonus is ready$(RESET) ā\n"

$(CLIENT_B): $(LIBFT) $(SRCS_CLIENT_B)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT) -o $(CLIENT_B) $(SRCS_CLIENT_B)
	@echo "\nš„ $(GREEN) Client bonus is ready$(RESET) ā\n"

$(LIBFT):
	@make -C libft --silent
	@echo "\nš $(GREEN)Libft is ready$(RESET) ā\n"

clean:
	@make -C libft clean --silent
	@echo "\nš® $(RED) Binary files removed $(RESET) š§¹\n"

fclean: clean
	@make -C libft fclean --silent
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_B) $(SERVER_B)
	@echo "\nš® $(RED) Executable files removed $(RESET) š§¹\n"

bonus: $(SERVER_B) $(CLIENT_B)

re: fclean all

.PHONY: all clean fclean re bonus