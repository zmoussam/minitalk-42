# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 22:50:00 by zmoussam          #+#    #+#              #
#    Updated: 2022/03/25 18:36:11 by zmoussam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = ./partie_obligatoire/minitalk.h
INC_BONUS = ./partie_bonus/minitalk_bonus.h
NAME = server client
CFLAGS = -Wall -Wextra -Werror
CFILES = ./partie_obligatoire/server.c ./partie_obligatoire/utils.c \
		./partie_obligatoire/client.c ./partie_bonus/server_bonus.c \
		./partie_bonus/utils_bonus.c ./partie_bonus/client_bonus.c
OBJ = $(CFILES:.c=.o)

all : $(NAME)

bonus:  server_bonus client_bonus

server: ./partie_obligatoire/server.o ./partie_obligatoire/utils.o $(INC)
	gcc $(CFLAGS)   ./partie_obligatoire/server.o \
	./partie_obligatoire/utils.o -o server

client: ./partie_obligatoire/client.o ./partie_obligatoire/utils.o $(INC)
	gcc $(CFLAGS) ./partie_obligatoire/client.o \
	./partie_obligatoire/utils.o -o client
	
server_bonus: ./partie_bonus/server_bonus.o ./partie_bonus/utils_bonus.o \
				$(INC_BONUS)
	gcc $(CFLAGS)   ./partie_bonus/server_bonus.o \
	./partie_bonus/utils_bonus.o -o server_bonus

client_bonus: ./partie_bonus/client_bonus.o \
				./partie_bonus/utils_bonus.o $(INC_BONUS)
	gcc $(CFLAGS)   ./partie_bonus/client_bonus.o \
	./partie_bonus/utils_bonus.o -o client_bonus

clean:
	rm -rf ./partie_obligatoire/server.o ./partie_bonus/server_bonus.o \
	./partie_obligatoire/client.o ./partie_bonus/client_bonus.o \
	 ./partie_bonus/utils_bonus.o  ./partie_obligatoire/utils.o
	
fclean : clean
	rm -rf server server_bonus \
	client client_bonus

re : fclean all
