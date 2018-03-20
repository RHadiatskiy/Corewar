CC = @gcc
HEADER = libft.h
NAME = libft.a

SRC =  ft_atoi.c ft_strcat.c ft_strcpy.c ft_strdup.c \
	   ft_strlen.c ft_strncat.c ft_strncpy.c ft_strnlen.c \
	   ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	   ft_isprint.c ft_toupper.c ft_tolower.c ft_strcmp.c \
	   ft_strncmp.c ft_memcmp.c ft_memcpy.c ft_memset.c \
	   ft_bzero.c ft_memccpy.c ft_memmove.c ft_strstr.c \
	   ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	   ft_memalloc.c ft_strnew.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_memchr.c ft_strchr.c ft_strrchr.c ft_strlcat.c \
	   ft_strnstr.c ft_memdel.c ft_strdel.c ft_strclr.c \
	   ft_putendl_fd.c ft_striter.c ft_striteri.c ft_strmap.c \
	   ft_strmapi.c ft_strequ.c ft_strnequ.c ft_putnbr_fd.c \
	   ft_strsub.c ft_strjoin.c ft_strtrim.c \
	   ft_islower.c ft_isupper.c ft_isnumber.c ft_isblank.c \
	   ft_strndup.c ft_strsplit.c ft_lstnew.c ft_lstdelone.c \
	   ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	   get_next_line.c ft_split.c ft_strisdigit.c ft_szero.c \
	   ft_to_bin.c ft_delete_deintegrated.c get_raw_line_fd.c \
	   ft_split_whitespace.c ft_calloc.c ft_strspn.c \
	   ft_fd_valid.c ft_error.c ft_is_whitespace.c ft_free.c


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
