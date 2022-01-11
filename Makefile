
NAME	=	push_swap

HEADER	=	push_swap.h

LIBFT	=	./libft/libft.a

SRCS	=	push_swap.c	ft_get_stack_a_from_input_funcs.c	ft_sort_funcs.c \
			ft_index_funcs.c	ft_push_funcs.c	ft_presort_funcs.c \
			ft_score_stack_b_funcs.c	ft_little_sort_funcs.c \
			ft_is_cir_sorted_funcs.c	ft_move_back_from_stack_b_funcs.c \
			ft_move_rb_rrb_ra_rra_funcs.c	ft_rb_ra_rrb_rra_sa_sb_funcs.c \
			ft_move_rr_rrr_funcs.c	ft_rr_rrr_funcs.c	ft_final_sort_funcs.c \
			ft_get_rb_ra_rrb_rra_cost_funcs.c

CH_SRCS	=	checker.c	ft_checker_utils.c	\
			get_next_line.c	get_next_line_utils.c

CH_DIR	=	./checker_srcs

CH_SRCS_D = $(addprefix ${CH_DIR}/,${CH_SRCS})

OBJS	=	${SRCS:.c=.o}

CH_OBJS	=	${CH_SRCS_D:.c=.o}

COMMON_OBJS = $(filter-out push_swap.o,${OBJS})

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

%.o			:	%.c ${HEADER}
				${CC} ${CFLAGS} $< -c -o $@

.PHONY		:	all re clean fclean debug run libft checker

${NAME}		:	${OBJS} ${LIBFT}
				${CC} ${CFLAGS} ${OBJS} -L./libft -lft -o ${NAME}

${LIBFT}	:	libft ;

libft		:
				${MAKE} -C ./libft

checker		:	${OBJS} ${CH_OBJS} ${LIBFT}
				${CC} ${CFLAGS} ${COMMON_OBJS} ${CH_OBJS} -L./libft -lft -o checker

clean		:
				rm -rf ${OBJS}
				${MAKE} -C ./libft clean

fclean		:
				rm -rf ${OBJS} ${NAME} bonus
				${MAKE} -C ./libft fclean

debug		:
				${CC} ${CFLAGS} -g ${SRCS} -L./libft -lft -o ${NAME}_debug


ch_leaks		:	${NAME}
					leaks -atExit -- ./push_swap 0 1 3 2 7 5 6 4 10 9 8 -100 2147483647

ch_leaks_cir 	:	${NAME}
					leaks -atExit -- ./push_swap  2 4 6 0 1

ch_leaks_two 	:	${NAME}
					leaks -atExit -- ./push_swap  4 2

ch_leaks_three 	:	${NAME}
					leaks -atExit -- ./push_swap  4 2 5

ch_leaks_word 	:	${NAME}
					leaks -atExit -- ./push_swap  4 2 55 lol 7

ch_leaks_double :	${NAME}
					leaks -atExit -- ./push_swap  4 2 4 8 7

ch_leaks_m_int 	:	${NAME}
					leaks -atExit -- ./push_swap  4 2 55 7 2147483648

run			:	${NAME}
				./push_swap 0 1 3 2 7 5 6 4 10 9 8 -100 2147483647

run_two		:	${NAME}
				./push_swap 10 5

run_three	:	${NAME}
				./push_swap 2 1 0

run_four	:	${NAME}
				./push_swap 10 5 20 15

run_five	:	${NAME}
				./push_swap 1 5 2 4 3

run_word	:	${NAME}
				./push_swap 5 20 hello 15 10

run_many	:	${NAME}
				./push_swap 49 43 80 25 11 28 48 68 87 1 93 47 15 88 2 75 56 62 \
				100 92 90 70 17 69 66 32 52 50 5 78 98 83 45 54 65 16 40 71 22 \
				61 26 55 95 79 12 24 29 21 67 74 84 91 30 81 13 46 99 19 18 \
				44 36 4 89 14 42 20 57 96 34 82 58 76 10 23 97 63 85 37 77 \
				9 73 51 39 33 7 6 59 86 35 27 41 53 38 8 31 60 72 94 64 3

all			:	${NAME}

re			:	fclean ${NAME}

test		:
				${COMMON_OBJS}
