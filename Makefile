
NAME	=	push_swap

HEADER	=	push_swap.h

LIBFT	=	./libft/libft.a

SRCS	=	push_swap.c get_stack_a_from_input_funcs.c ft_sort_funcs.c

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

%.o			:	%.c	${HEADER}
				${CC} ${CFLAGS} -g $< -c -o $@

.PHONY		:	all re clean fclean debug run libft

${NAME}		:	${OBJS} ${LIBFT}
				${CC} ${CFLAGS} ${OBJS} -L./libft -lft -o ${NAME}

bonus		:
				echo "nothing for now"

${LIBFT}	:	libft ;

libft		:
				${MAKE} -C ./libft bonus

clean		:
				rm -rf ${OBJS}
				${MAKE} -C ./libft clean

fclean		:
				rm -rf ${OBJS} ${NAME} bonus
				${MAKE} -C ./libft fclean

debug		:
				${CC} ${CFLAGS} -g ${SRCS} -L./libft -lft -o ${NAME}_debug

ch_leaks	:	${NAME}
				leaks -atExit -- ./push_swap 1 2 3 4 5 6 7 8 9 10 -100 2147483647

all			:	${NAME} bonus

re			:	fclean ${NAME}
