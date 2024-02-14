
NAME= cub3D
SRC_DIR = ./srcs
# SRCS= $(wildcard $(SRC_DIR)/*.c)
SRCS = $(SRC_DIR)/main.c
# SRCS_BONUS=

INC_DIR= -I./includes

LIB_DIR		= ./libft/
LIB_INC		= -I$(LIB_DIR)includes/
LIB_NAME	= $(LIB_DIR)libft.a

OBJS= ${SRCS:.c=.o}

OBJS_BONUS= ${SRCS_BONUS:.c=.o}
CC= cc
FLAGS= -Wall -Wextra -Werror -g3 -fsanitize=address 

RM=rm -f

all: $(NAME)

${NAME}: $(OBJS)
	cd minilibx-linux;make;cd ..
	@make --silent -C $(LIB_DIR)
	$(CC) $(FLAGS) $(OBJS) -Lminilibx-linux -L/usr/lib -Iminilibx-linux/ -o $(NAME) -lXext -lX11 -lm -lmlx_Linux $(LIB_NAME) -L$(LIB_DIR) $(LIB_INC)
	
# bonus: $(OBJS_BONUS)
# 	cd minilibx-linux;make;cd ..
# 	$(CC) $(FLAGS) $(OBJS_BONUS) -Lminilibx-linux -L/usr/lib -Iminilibx-linux/ -o $(NAME)_bonus -lXext -lX11 -lm -lmlx_Linux

%.o: %.c
	$(CC) -Wall -Wextra -Werror -MP -I/usr/include -Iminilibx-linux/ -c $< -o $@

clean:
	@$(MAKE) clean --silent -C $(LIB_DIR)
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	@$(MAKE) fclean --silent -C $(LIB_DIR)
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re #bonus