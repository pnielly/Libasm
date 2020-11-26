#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s);

int	main(void)
{
	printf("ft = %ld\n", ft_strlen("Bonjour"));
	printf("pr = %ld\n", strlen("Bonjour"));
	return (0);
}

