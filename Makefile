
NAME	=	push_swap

HEADER	=	push_swap.h

LIBFT	=	./libft/libft.a

SRCS	=	push_swap.c	ft_get_stack_a_from_input_funcs.c	ft_sort_funcs.c \
			ft_index_funcs.c	ft_push_funcs.c	ft_presort_funcs.c \
			ft_b_scoring_funcs.c	ft_little_sort_funcs.c \
			ft_is_cir_sorted_funcs.c	ft_move_back_from_stack_b_funcs.c \
			ft_move_rb_rrb_ra_rra_funcs.c	ft_rb_ra_rrb_rra_sa_sb_pa_funcs.c \
			ft_move_rr_rrr_funcs.c	ft_rr_rrr_funcs.c	ft_final_sort_funcs.c

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
				leaks -atExit -- ./push_swap 0 1 3 2 7 5 6 4 10 9 8 -100 2147483647

run			:	${NAME}
				./push_swap 0 1 3 2 7 5 6 4 10 9 8 -100 2147483647

run_two		:	${NAME}
				./push_swap 10 5

run_three	:	${NAME}
				./push_swap 5 15 10

run_four	:	${NAME}
				./push_swap 10 15 20 5

run_five	:	${NAME}
				./push_swap 1 5 2 4 3

run_word	:	${NAME}
				./push_swap 5 20 hello 15 10

run_many	:	${NAME}
				./push_swap 49 43 80 25 11 28 48 68 87 1 93 47 3 88 2 75 56 62 100 92 7 70 17 69 66 32 52 50 5 78 98 83 45 54 65 16 40 71 22 61 26 55 95 79 12 24 29 21 67 74 84 91 30 81 13 46 99 19 18 44 36 4 89 14 42 20 57 96 34 82 58 76 10 23 97 63 85 37 77 9 73 51 39 33 90 6 59 86 35 27 41 53 38 8 31 60 72 94 64 15


all			:	${NAME} bonus

re			:	fclean ${NAME}
