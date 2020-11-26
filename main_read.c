#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

ssize_t	ft_read(int fd, void *buf, size_t count);

int	main(void)
{
	int	fd;
	int	ret;
//	int	i;
	char	buf[301];

	if (!(fd = open("fichier.txt", O_RDONLY | O_CREAT, 7777)))
	{
		printf("pd\n");
		return (0);
	}
	printf("FD = %d\n", fd);
	sleep(1);
	while ((ret = read(fd, buf, 300)))
	{
		printf("Affreux jojo\n");
		printf("FD = %d\n", fd);
		sleep(1);
		buf[ret] = '\0';
		printf("%s\n", buf);
	}
/*	while (read(fd, &i, sizeof(int)) != EOF)
	{
		printf("%d\n", i);
	}*/
	close(fd);
	if (!(fd = open("fichier.txt", O_RDONLY | O_CREAT, 7777)))
	{
		printf("pd\n");
		return (0);
	}
	printf("FD = %d\n", fd);
	sleep(1);
	while ((ret = ft_read(fd, buf, 300)))
	{
		printf("Affreux jojo\n");
		printf("FD = %d\n", fd);
		sleep(1);
		buf[ret] = '\0';
		printf("%s\n", buf);
	}
/*	while (read(fd, &i, sizeof(int)) != EOF)
	{
		printf("%d\n", i);
	}*/
	close(fd);
	return (0);
}
