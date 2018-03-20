# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/17 15:31:58 by bsemchuk          #+#    #+#              #
#*   Updated: 2018/03/19 18:33:16 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

CC = @gcc
HEADER = libft.h
NAME = libft.a

SRC =	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
		ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
		ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
		ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
		ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
		ft_strmapi.c ft_strmlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
		ft_strnstr.c ft_strrchr.c ft_strslen.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
		ft_tolower.c ft_toupper.c ft_error.c ft_subchar.c ft_strjoinfree.c get_next_line.c ft_strchcpy.c \
		ft_strspn.c ft_strpass.c ft_strskp.c ft_strpspn.c ft_strpcpy.c ft_strnmcpy.c ft_strachr.c \
		ft_straposchr.c ft_strlchr.c ft_chrpos.c ft_uitoa.c ft_straddprefix.c ft_straddpostfix.c \
		ft_usitoa.c ft_wctomb.c ft_wstrtombstr.c ft_wcblen.c ft_wcslen.c ft_wcsncpy.c \
		get_next_line_stdin.c ft_calloc.c get_next_line_fd.c ft_fd_valid.c ft_free.c ft_is_whitespace.c \
		ft_delete_deintegrated.c ft_split_whitespace.c get_raw_line_fd.c


CFLAGS = -g3 -Wall -Wextra -Werror 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ) 
	@ranlib $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re: fclean all
