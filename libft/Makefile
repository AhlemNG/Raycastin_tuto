# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anouri <anouri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 17:36:35 by anouri            #+#    #+#              #
#    Updated: 2024/01/31 10:21:56 by anouri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

SRCS = ft_isalnum.c ft_isalpha.c \
    ft_isascii.c ft_isdigit.c \
    ft_toupper.c ft_tolower.c \
    ft_isprint.c ft_strlcat.c \
    ft_strlen.c ft_atoi.c \
    ft_memset.c ft_bzero.c \
    ft_strnstr.c ft_strlcpy.c \
    ft_calloc.c ft_strchr.c \
    ft_strrchr.c ft_strncmp.c \
    ft_strdup.c ft_memcpy.c \
    ft_memmove.c ft_memchr.c \
    ft_substr.c ft_strjoin.c \
    ft_strtrim.c ft_putchar_fd.c \
    ft_putstr_fd.c ft_putendl_fd.c \
    ft_putnbr_fd.c ft_strmapi.c \
    ft_split.c ft_memcmp.c \
    ft_striteri.c ft_itoa.c \
    ft_strncpy.c ft_lstnew.c \
    ft_lstadd_front.c ft_lstsize.c \
    ft_lstlast.c ft_lstadd_back.c \
    ft_lstdelone.c ft_lstclear.c \
    ft_lstiter.c ft_lstmap.c \
    ft_strncpy_sa.c ft_isspace.c \
    ft_perror.c \
    save_str_as_file.c \
    gnl/get_next_line.c \
    gnl/get_next_line_utils.c\
    ft_strnstr2.c \
    print_char_table.c\
    free_char_table.c\

INC_DIR= ./

OBJS = ${SRCS:.c=.o}

# OBJS2 = ${SRCSBO:.c=.o}

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

AR = ar rc

.c.o:
	${CC} ${CFLAGS} -I ${INC_DIR} -c $< -o ${<:.c=.o}

all: $(NAME)

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

# bonus: ${OBJS} ${OBJS2}
	# ${AR} ${NAME} ${OBJS} ${OBJS2}


clean:
	${RM} ${OBJS} #${OBJS2}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re #bonus
