#include "libft.h"

int 	ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\t')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}