NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
HEADER = ./srcs/
HEADER_BONUS = ./bonus/
SRCS_DIR = ./srcs
SRCS_DIR_BONUS = ./bonus
LIBFT_DIR =	libft
SRCS = push_swap.c cost_ab.c cost_set.c  \
		check_av.c check_dup.c check_set.c check_result.c \
		stack_create.c stack_manage.c \
		stack_rotate.c stack_reverse.c \
		stack_swappush.c stack_util.c \
		op_AtoB.c op_BtoA.c op_dual.c \
		op_final.c op_under.c
BONUS_SRCS = checker_bonus.c \
		get_next_line_bonus.c get_next_line_utils_bonus.c \
		check_av_bonus.c check_dup_bonus.c \
		check_set_bonus.c check_result_bonus.c \
		stack_create_bonus.c stack_manage_bonus.c \
		stack_rotate_bonus.c stack_reverse_bonus.c \
		stack_swappush_bonus.c stack_util_bonus.c

OBJS = $(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o))
BONUS_OBJ = $(addprefix $(SRCS_DIR_BONUS)/, $(BONUS_SRCS:.c=.o))

ifdef BONUS
 OBJS_CUR = $(BONUS_OBJ)
 REAL_NAME = $(NAME_BONUS)
 HEADER_CUR = $(HEADER_BONUS)
else
 OBJS_CUR = $(OBJS)
 REAL_NAME = $(NAME)
 HEADER_CUR = $(HEADER)
endif

all : $(REAL_NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I $(HEADER_CUR) -c $< -o $@

$(REAL_NAME) : $(OBJS_CUR)
	make -C ./libft
	$(CC) $(CFLAGS) -lft -L./libft -o $(REAL_NAME) $(OBJS_CUR)

clean :
	make -C ./libft clean
	rm -rf $(OBJS) $(BONUS_OBJ)

fclean : clean
	rm -rf push_swap checker
	make -C ./libft fclean

re : fclean all

bonus : 
	make BONUS=1 all

.PHONY : all clean fclean re bonus