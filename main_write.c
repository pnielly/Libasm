#include <unistd.h>
#include <stdio.h>

ssize_t	ft_write(int fd, const void *buf, size_t count);

int	main(void)
{
	printf("%ld", ft_write(1, "Jojo\n", 5));
	printf("%ld", write(1, "Jojo\n", 5));
	return (0);
}
