# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: akant <akant@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/12 13:53:25 by akant         #+#    #+#                  #
#    Updated: 2021/11/18 11:55:20 by akant         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_atoi_failed.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memcpy.c \
ft_memchr.c ft_memcmp.c ft_memccpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strrchr.c \
ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
ft_strncmp.c ft_strnstr.c ft_strchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
ft_toupper.c ft_strcmp.c ft_print_split.c ft_strstr.c ft_split_free.c

BONUS_FILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

HEADER_FILES = libft.h

CFLAGS = -Wall -Wextra -Werror

OBJS_REG = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS_FILES:.c=.o)

ifdef BONUS_BOOL
OBJS = $(OBJS_REG) $(OBJS_BONUS)
else
OBJS = $(OBJS_REG)
endif

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

bonus:
	$(MAKE) BONUS_BOOL=1 all

clean:
	rm -f $(OBJS_BONUS) $(OBJS_REG)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re
