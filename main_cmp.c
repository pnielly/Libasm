#include <stdio.h>
#include <string.h>

int	ft_strcmp(const char *s1, const char *s2);

int	main(void)
{
	printf("ft = %d\n", ft_strcmp("Bonjour", "Bonji"));
	printf("pr = %d\n", strcmp("Bonjour", "Bonji"));
	return (0);
}
