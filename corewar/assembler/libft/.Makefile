HEADER = libft.h

OBJS =	ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o \
		ft_isprint.o ft_itoa.o ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o \
		ft_lstmap.o ft_lstnew.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o \
		ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o ft_putchar.o ft_putchar_fd.o \
		ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o \
		ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o \
		ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o ft_strmap.o \
		ft_strmapi.o ft_strmlen.o ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o \
		ft_strnstr.o ft_strrchr.o ft_strslen.o ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o \
		ft_tolower.o ft_toupper.o ft_error.o ft_subchar.o ft_strjoinfree.o get_next_line.o ft_strchcpy.o \
		ft_strspn.o ft_strpass.o ft_strskp.o ft_strpspn.o ft_strpcpy.o ft_strnmcpy.o ft_strachr.o \
		ft_straposchr.o ft_strlchr.o ft_chrpos.o ft_uitoa.o ft_straddprefix.o ft_straddpostfix.o \
		ft_usitoa.o ft_wctomb.o ft_wstrtombstr.o ft_wcblen.o ft_wcslen.o ft_wcsncpy.o \
		get_next_line_stdin.o ft_calloc.o ft_realloc.o get_next_line_fd.o


FLAGS = -Wall -Wextra -Werror -g

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS) $(HEADER)

get_next_line_fd.o: get_next_line_fd.c
	@gcc -c $(FLAGS) get_next_line_fd.c

ft_calloc.o: ft_calloc.c
	@gcc -c $(FLAGS) ft_calloc.c

ft_wcsncpy.o: ft_wcsncpy.c
	@gcc -c $(FLAGS) ft_wcsncpy.c

get_next_line_stdin.o: get_next_line_stdin.c
	@gcc -c $(FLAGS) get_next_line_stdin.c

ft_wcslen.o: ft_wcslen.c
	@gcc -c $(FLAGS) ft_wcslen.c

ft_wcblen.o: ft_wcblen.c
	@gcc -c $(FLAGS) ft_wcblen.c

ft_wstrtombstr.o: ft_wstrtombstr.c
	@gcc -c $(FLAGS) ft_wstrtombstr.c

ft_wctomb.o: ft_wctomb.c
	@gcc -c $(FLAGS) ft_wctomb.c

ft_usitoa.o: ft_usitoa.c
	@gcc -c $(FLAGS) ft_usitoa.c

ft_straddpostfix.o: ft_straddpostfix.c
	@gcc -c $(FLAGS) ft_straddpostfix.c

ft_straddprefix.o: ft_straddprefix.c
	@gcc -c $(FLAGS) ft_straddprefix.c

ft_uitoa.o: ft_uitoa.c
	@gcc -c $(FLAGS) ft_uitoa.c

ft_chrpos.o: ft_chrpos.c
	@gcc -c $(FLAGS) ft_chrpos.c

ft_strlchr.o: ft_strlchr.c
	@gcc -c $(FLAGS) ft_strlchr.c

ft_straposchr.o: ft_straposchr.c
	@gcc -c $(FLAGS) ft_straposchr.c

ft_strachr.o: ft_strachr.c
	@gcc -c $(FLAGS) ft_strachr.c

ft_strnmcpy.o: ft_strnmcpy.c
	@gcc -c $(FLAGS) ft_strnmcpy.c

ft_strpcpy.o: ft_strpcpy.c
	@gcc -c $(FLAGS) ft_strpcpy.c

ft_strpspn.o: ft_strpspn.c
	@gcc -c $(FLAGS) ft_strpspn.c

ft_strskp.o: ft_strskp.c
	@gcc -c $(FLAGS) ft_strskp.c

ft_strpass.o: ft_strpass.c
	@gcc -c $(FLAGS) ft_strpass.c

ft_strspn.o: ft_strspn.c
	@gcc -c $(FLAGS) ft_strspn.c

ft_strchcpy.o: ft_strchcpy.c
	@gcc -c $(FLAGS) ft_strchcpy.c

get_next_line.o: get_next_line.c
	@gcc -c $(FLAGS) get_next_line.c

ft_strjoinfree.o: ft_strjoinfree.c
	@gcc -c $(FLAGS) ft_strjoinfree.c

ft_atoi.o: ft_atoi.c
	@gcc -c $(FLAGS) ft_atoi.c

ft_bzero.o: ft_bzero.c 
	@gcc -c $(FLAGS) ft_bzero.c 

ft_isalnum.o: ft_isalnum.c 
	@gcc -c $(FLAGS) ft_isalnum.c

ft_isalpha.o: ft_isalpha.c
	@gcc -c $(FLAGS) ft_isalpha.c

ft_isascii.o: ft_isascii.c
	@gcc -c $(FLAGS) ft_isascii.c

ft_isdigit.o: ft_isdigit.c
	@gcc -c $(FLAGS) ft_isdigit.c

ft_isprint.o: ft_isprint.c
	@gcc -c $(FLAGS) ft_isprint.c

ft_itoa.o: ft_itoa.c
	@gcc -c $(FLAGS) ft_itoa.c

ft_lstadd.o: ft_lstadd.c
	@gcc -c $(FLAGS) ft_lstadd.c

ft_lstdel.o: ft_lstdel.c
	@gcc -c $(FLAGS) ft_lstdel.c

ft_lstdelone.o: ft_lstdelone.c
	@gcc -c $(FLAGS) ft_lstdelone.c

ft_lstiter.o: ft_lstiter.c
	@gcc -c $(FLAGS) ft_lstiter.c

ft_lstmap.o: ft_lstmap.c
	@gcc -c $(FLAGS) ft_lstmap.c

ft_lstnew.o: ft_lstnew.c
	@gcc -c $(FLAGS) ft_lstnew.c

ft_memalloc.o: ft_memalloc.c
	@gcc -c $(FLAGS) ft_memalloc.c

ft_memccpy.o: ft_memccpy.c
	@gcc -c $(FLAGS) ft_memccpy.c

ft_memchr.o: ft_memchr.c
	@gcc -c $(FLAGS) ft_memchr.c

ft_memcmp.o: ft_memcmp.c
	@gcc -c $(FLAGS) ft_memcmp.c

ft_memcpy.o: ft_memcpy.c
	@gcc -c $(FLAGS) ft_memcpy.c

ft_memdel.o: ft_memdel.c
	@gcc -c $(FLAGS) ft_memdel.c

ft_memmove.o: ft_memmove.c
	@gcc -c $(FLAGS) ft_memmove.c

ft_memset.o: ft_memset.c
	@gcc -c $(FLAGS) ft_memset.c 

ft_putchar.o: ft_putchar.c
	@gcc -c $(FLAGS) ft_putchar.c

ft_putchar_fd.o: ft_putchar_fd.c
	@gcc -c $(FLAGS) ft_putchar_fd.c

ft_putendl.o: ft_putendl.c
	@gcc -c $(FLAGS) ft_putendl.c

ft_putendl_fd.o: ft_putendl_fd.c
	@gcc -c $(FLAGS) ft_putendl_fd.c

ft_putnbr.o: ft_putnbr_fd.c
	@gcc -c $(FLAGS) ft_putnbr.c

ft_putnbr_fd.o: ft_putnbr_fd.c
	@gcc -c $(FLAGS) ft_putnbr_fd.c

ft_putstr.o: ft_putstr.c
	@gcc -c $(FLAGS) ft_putstr.c

ft_putstr_fd.o: ft_putstr_fd.c
	@gcc -c $(FLAGS) ft_putstr_fd.c

ft_strcat.o: ft_strcat.c
	@gcc -c $(FLAGS) ft_strcat.c

ft_strchr.o: ft_strchr.c
	@gcc -c $(FLAGS) ft_strchr.c

ft_strclr.o: ft_strclr.c
	@gcc -c $(FLAGS) ft_strclr.c

ft_strcmp.o: ft_strcmp.c
	@gcc -c $(FLAGS) ft_strcmp.c

ft_strcpy.o: ft_strcpy.c
	@gcc -c $(FLAGS) ft_strcpy.c

ft_strdel.o: ft_strdel.c
	@gcc -c $(FLAGS) ft_strdel.c

ft_strdup.o: ft_strdup.c
	@gcc -c $(FLAGS) ft_strdup.c

ft_strequ.o: ft_strequ.c
	@gcc -c $(FLAGS) ft_strequ.c

ft_striter.o: ft_striter.c
	@gcc -c $(FLAGS) ft_striter.c

ft_striteri.o: ft_striteri.c
	@gcc -c $(FLAGS) ft_striteri.c

ft_strjoin.o: ft_strjoin.c
	@gcc -c $(FLAGS) ft_strjoin.c

ft_strlcat.o: ft_strlcat.c
	@gcc -c $(FLAGS) ft_strlcat.c

ft_strlen.o: ft_strlen.c
	@gcc -c $(FLAGS) ft_strlen.c

ft_strmap.o: ft_strmap.c
	@gcc -c $(FLAGS) ft_strmap.c

ft_strmapi.o: ft_strmapi.c
	@gcc -c $(FLAGS) ft_strmapi.c

ft_strmlen.o: ft_strmlen.c
	@gcc -c $(FLAGS) ft_strmlen.c

ft_strncat.o: ft_strncat.c
	@gcc -c $(FLAGS) ft_strncat.c

ft_strncmp.o: ft_strncmp.c
	@gcc -c $(FLAGS) ft_strncmp.c

ft_strncpy.o: ft_strncpy.c
	@gcc -c $(FLAGS) ft_strncpy.c

ft_strnequ.o: ft_strnequ.c
	@gcc -c $(FLAGS) ft_strnequ.c

ft_strnew.o: ft_strnew.c
	@gcc -c $(FLAGS) ft_strnew.c

ft_strnstr.o: ft_strnstr.c
	@gcc -c $(FLAGS) ft_strnstr.c

ft_strrchr.o: ft_strrchr.c
	@gcc -c $(FLAGS) ft_strrchr.c

ft_strslen.o: ft_strslen.c
	@gcc -c $(FLAGS) ft_strslen.c

ft_strsplit.o: ft_strsplit.c
	@gcc -c $(FLAGS) ft_strsplit.c

ft_strstr.o: ft_strstr.c
	@gcc -c $(FLAGS) ft_strstr.c

ft_strsub.o: ft_strsub.c
	@gcc -c $(FLAGS) ft_strsub.c

ft_strtrim.o: ft_strtrim.c 
	@gcc -c $(FLAGS) ft_strtrim.c

ft_tolower.o: ft_tolower.c
	@gcc -c $(FLAGS) ft_tolower.c

ft_toupper.o: ft_toupper.c
	@gcc -c $(FLAGS) ft_toupper.c

ft_error.o: ft_error.c
	@gcc -c $(FLAGS) ft_error.c

ft_subchar.o: ft_subchar.c
	@gcc -c $(FLAGS) ft_subchar.c

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all clean
