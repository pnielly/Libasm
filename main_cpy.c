#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strcpy(char *dest, const char *src);

int	main(void)
{
	char	*s;

	if (!(s = malloc(8)))
	{
		printf("pd\n");
		return (0);
	}
	printf("ft = %s\n", ft_strcpy(s, "Bonjour"));
	printf("pr = %s\n", strcpy(s, "Bonjour"));
	return (0);
}

