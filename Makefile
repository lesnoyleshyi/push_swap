
NAME	=	push_swap

HEADER	=	push_swap.h

LIBFT	=	./libft/libft.a

SRCS	=	push_swap.c	ft_get_stack_a_from_input_funcs.c	ft_sort_funcs.c \
			ft_index_funcs.c	ft_push_funcs.c	ft_presort_funcs.c \
			ft_b_scoring_funcs.c	ft_little_sort_funcs.c

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
				leaks -atExit -- ./push_swap 1 3 2 7 5 6 4 10 9 8 -100 2147483647

run			:	${NAME}
				./push_swap 1 3 2 7 5 6 4 10 9 8 -100 2147483647

run_two		:	${NAME}
				./push_swap 10 5

run_three	:	${NAME}
				./push_swap 5 15 10

run_four	:	${NAME}
				./push_swap 5 10 15 20

all			:	${NAME} bonus

re			:	fclean ${NAME}
