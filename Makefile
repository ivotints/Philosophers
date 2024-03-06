# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 19:07:35 by ivotints          #+#    #+#              #
#    Updated: 2024/03/02 19:42:32 by ivotints         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =	main.c \
		01arg_check.c \
		02arg_init.c \
		03init_philos.c \
		04init_thread.c \
		philo_utils.c
OBJS = ${SRCS:.c=.o}
RM = rm -f

#define color codes
RESET	= \033[0m
BLUE	= \033[34m

all: ${NAME}

${NAME} : ${OBJS}
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(BLUE)$(NAME) is ready!$(RESET)"

clean:
	@$(RM) $(OBJS)

fclean:
	@$(RM) $(OBJS)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
