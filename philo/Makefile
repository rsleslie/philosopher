# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rleslie- <rleslie-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 19:20:30 by rleslie-          #+#    #+#              #
#    Updated: 2023/07/02 14:08:18 by rleslie-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = philo
SCS   = sources/philo.c 	\
		sources/actions.c 	\
		sources/checkout.c 	\
		sources/init.c 		\
		sources/routine.c 	\
		sources/time.c 		\
		sources/utils.c 		\

OBJS  = $(addprefix objects/, $(notdir $(SCS:.c=.o)))
CC 	  = cc
FLAGS = -Wall -Wextra -Werror -pthread -g3

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) $(FLAGS) -o $(NAME)

objects:
		mkdir -p objects sources

objects/%.o: sources/%.c | objects
	$(CC) $(FLAGS) -c $< -o $@
	
clean: 
		rm -rf objects

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
