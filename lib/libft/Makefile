# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 04:12:09 by sinlee            #+#    #+#              #
#    Updated: 2023/07/17 14:16:20 by sinlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = src/
SRCS	=	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_striteri.c \
			ft_tolower.c \
			ft_toupper.c \
			get_next_line.c \
			get_next_line_utils.c

SRCS_B = 	ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c


CFILES = $(addprefix $(SRCS_DIR), $(SRCS))
CFILES_B = $(addprefix $(SRCS_DIR), $(SRCS_B))

OBJS	= ${CFILES:.c=.o}
OBJS_B	= ${CFILES_B:.c=.o}
INCS	= ./includes
NAME	= libft.a
LIBC	= ar rcs
LIBR	= ranlib
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I$(INCS)


all: ${NAME}

$(NAME): ${OBJS} ${OBJS_B}
	${LIBC} $(NAME) ${OBJS} ${OBJS_B}

#for 42 bonus
bonus: ${OBJS} ${OBJS_B}
	${LIBC} $(NAME) ${OBJS_B}

clean:
	${RM} ${OBJS} ${OBJS_B}

fclean: clean
	${RM} $(NAME) $(bonus)

re: fclean all

.PHONY: all bonus clean fclean re