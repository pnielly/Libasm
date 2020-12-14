#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define GREEN	"\33[1;32m"
#define RED	"\33[1;31m"
#define YELLOW	"\33[1;33m"
#define WHITE	"\33[0;37m"

int	ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *s);
ssize_t ft_read(int fd, void *buf, size_t count);
ssize_t	ft_write(int fd, const void *buf, size_t count);

int	ft_test_write(void)
{
	int	fd;
	int	fd2;
	char	buf1[301];
	char	buf2[301];
	int	ret1;
	int	ret2;
	int	ret;
	
	if (!(fd = open("ft_write.txt", O_RDWR | O_CREAT, 7777)))
	{
		printf("open failed\n");
		return (0);
	}
	ret1 = ft_write(fd, "Jojo\n", 5);
	while ((ret = read(fd, buf1, 300)))
	{
		buf1[ret] = '\0';
		printf("%s\n", buf1);
	}
	if (!(fd2 = open("write.txt", O_RDWR | O_CREAT, 7777)))
	{
		printf("open failed\n");
		return (0);
	}
	ret2 = write(fd2, "Jojo\n", 5);
	while ((ret = read(fd2, buf2, 300)))
	{
		buf2[ret] = '\0';
		printf("%s\n", buf2);
	}
	if (ret1 == ret2 && !strcmp(buf1, buf2))
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("ret1 = %d, ret2 = %d\n", ret1, ret2);
	return (0);
}

int	ft_test_read(void)
{
	int	fd;
	int	ret;
	char	buf1[301];
	char	buf2[301];

	if (!(fd = open("fichier.txt", O_RDONLY | O_CREAT, 7777)))
	{
		printf("open failed\n");
		return (0);
	}
	while ((ret = read(fd, buf1, 300)))
	{
		buf1[ret] = '\0';
	//	printf("%s\n", buf1);
	}
	close(fd);
	if (!(fd = open("fichier.txt", O_RDONLY | O_CREAT, 7777)))
	{
		printf("open failed\n");
		return (0);
	}
	while ((ret = ft_read(fd, buf2, 300)))
	{
		buf2[ret] = '\0';
	//	printf("%s\n", buf2);
	}
	close(fd);
	if (!strcmp(buf1, buf2))
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	return (0);
}

int	main(void)
{
	char *s;
	
	//TEST STRLEN
	printf("%s1. TESTING STRLEN%s\n", YELLOW, WHITE);
	if (ft_strlen("Bonjour") == strlen("Bonjour"))
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("ft_strlen = %ld\n", ft_strlen("Bonjour"));
	printf("strlen = %ld\n", strlen("Bonjour"));
	
	
	//TEST STRCPY
	printf("%s2. TESTING STRCPY%s\n", YELLOW, WHITE);
	if (!(s = malloc(8)))
	{
		printf("malloc failed\n");
		return (0);
	}
	if (!strcmp(ft_strcpy(s, "Bonjour"), strcpy(s, "Bonjour")))
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("ft_strcpy = %s\n", ft_strcpy(s, "Bonjour"));
	printf("strcpy = %s\n", strcpy(s, "Bonjour"));
	
	
	//TEST STRCMP
	printf("%s3. TESTING STRCMP%s\n", YELLOW, WHITE);
	if (ft_strcmp("Bonjour", "Bonji") == strcmp("Bonjour", "Bonji"))
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("ft_strcmp = %d\n", ft_strcmp("Bonjour", "Bonji"));
	printf("strcmp = %d\n", strcmp("Bonjour", "Bonji"));
	
	
	//TEST WRITE
	printf("%s4. TESTING WRITE%s\n", YELLOW, WHITE);
	ft_test_write();
	
	
	//TEST READ
	printf("%s5. TESTING READ%s\n", YELLOW, WHITE);
	ft_test_read();
	
	
	//TEST STRDUP
	printf("%s6. TESTING STRDUP%s\n", YELLOW, WHITE);
	if (!strcmp(ft_strdup("Bonjour"), strdup("Bonjour")))
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("ft_strdup = %s\n", ft_strdup("Bonjour"));
	printf("strdup = %s\n", strdup("Bonjour"));
	return (0);
}
