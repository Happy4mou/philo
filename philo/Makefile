NAME = philo
CFILES = philo.c\
		 check.c \
		 utils.c \
		 utils2.c \
		 utils3.c \

OBJ = ${CFILES:.c=.o}

CFLAGS = -Wall -Werror -Wextra -pthread
CC = cc
LI = ar -rc

all : ${NAME}

${NAME} : ${OBJ}
	cc   $(CFLAGS)  $(CFILES) -o $(NAME) #-fsanitize=thread -g
clean :
	${RM} ${OBJ}
fclean : clean 
	${RM} ${NAME}
re : fclean all  