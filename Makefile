# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 09:52:34 by kbarbry           #+#    #+#              #
#    Updated: 2022/05/17 04:49:45 by kbarbry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BBLU 		=	\033[1;34m
BGREEN		=	\033[1;32m
BRED		=	\033[1;31m
BLU 		=	\033[0;34m
GRN 		=	\033[0;32m
RED 		=	\033[0;31m
RST 		=	\033[0m

SRC			=	main.cpp

HEAD		=	TMap.hpp		\
				TStack.hpp		\
				TVector.hpp

OBJ			=   ${addprefix src/, ${SRC:.cpp=.o}}

HEADER		=	${addprefix inc/, ${HEAD}}

CC			=	c++
FLAGS		=	-Wall -Werror -Wextra -std=c++98
FLAGS_H		=	-Iinc/
NAME		=	Mutant

all: ${NAME}
.PHONY: all

print_header:
	echo "\033[1;34m\033[5G========================================================================================================"
	echo "\033[1;34m\033[5G"
	echo "\033[1;34m\033[5G███████╗████████╗      ██████╗ ██████╗ ███╗   ██╗████████╗ █████╗ ██╗███╗   ██╗███████╗██████╗ ███████╗"
	echo "\033[1;34m\033[5G██╔════╝╚══██╔══╝     ██╔════╝██╔═══██╗████╗  ██║╚══██╔══╝██╔══██╗██║████╗  ██║██╔════╝██╔══██╗██╔════╝"
	echo "\033[1;34m\033[5G█████╗     ██║        ██║     ██║   ██║██╔██╗ ██║   ██║   ███████║██║██╔██╗ ██║█████╗  ██████╔╝███████╗"
	echo "\033[1;34m\033[5G██╔══╝     ██║        ██║     ██║   ██║██║╚██╗██║   ██║   ██╔══██║██║██║╚██╗██║██╔══╝  ██╔══██╗╚════██║"
	echo "\033[1;34m\033[5G██║        ██║███████╗╚██████╗╚██████╔╝██║ ╚████║   ██║   ██║  ██║██║██║ ╚████║███████╗██║  ██║███████║"
	echo "\033[1;34m\033[5G╚═╝        ╚═╝╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝   ╚═╝   ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝╚══════╝"
	echo "\033[1;34m\033[5G"
	echo "\033[1;34m\033[5G=======================================> By kbarbry ft tjolivea <======================================="
.PHONY: print_header

%.o: %.cpp ${HEADER}
	${CC} ${FLAGS} ${FLAGS_H} -c $< -o $@
	echo "${BBLU}[${NAME} OBJ] :${RST} $@ ${BGREEN}\033[47G[✔]${RST}"

${NAME}: print_header ${OBJ}
	${CC} ${FLAGS} ${FLAGS_H} ${OBJ} -o ${NAME}
	echo "${BGREEN}[${NAME} END] :${RST}${RST} ./${NAME} ${BGREEN}\033[47G[✔]${RST}"

clean:
	rm -f ${OBJ}
	echo "${RED}[CLEAN]  :${RST} Deleting objects...${BGREEN}\033[47G[✔]${RST}"
.PHONY: clean

fclean: clean
	rm -f ${NAME}
	echo "${RED}[FCLEAN] :${RST} Deleting executable...${BGREEN}\033[47G[✔]${RST}"
.PHONY: fclean

re:	fclean all
.PHONY: re

.SILENT: