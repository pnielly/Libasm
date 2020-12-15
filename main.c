/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 13:21:35 by user42            #+#    #+#             */
/*   Updated: 2020/12/15 16:25:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ssize_t	ret1;
	ssize_t	ret2;
	ssize_t	reta;
	ssize_t	retb;
	int	check;

	check = 0;
	if (!(fd = open("ft_write.txt", O_CREAT | O_RDWR, 0666)))
	{
		printf("open failed\n");
		return (0);
	}
	ret1 = ft_write(fd, "Jojo\n", 5);
	if (!(fd2 = open("write.txt", O_CREAT | O_RDWR, 0666)))
	{
		printf("open failed\n");
		return (0);
	}
	ret2 = write(fd2, "Jojo\n", 5);
	while (((reta = read(fd, buf1, 300)) && (retb = read(fd2, buf2, 300))))
	{
		buf1[reta] = '\0';
		printf("%s\n", buf1);
		buf2[retb] = '\0';
		printf("%s\n", buf2);
		if (strcmp(buf1, buf2))
			check = 1;
	}
	if (ret1 == ret2 && !check)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("ret1 = %zd, ret2 = %zd\n", ret1, ret2);
	return (0);
}

int	ft_test_read(void)
{
	int	fd;
	ssize_t	ret;
	char	buf1[301];
	char	buf2[301];

	if (!(fd = open("bible.txt", O_RDONLY | O_CREAT, 7777)))
	{
		printf("open failed\n");
		return (0);
	}
	while ((ret = read(fd, buf1, 300)))
	{
		buf1[ret] = '\0';
		//		printf("%s\n", buf1);
	}
	close(fd);
	if (!(fd = open("bible.txt", O_RDONLY | O_CREAT, 7777)))
	{
		printf("open failed\n");
		return (0);
	}
	while ((ret = ft_read(fd, buf2, 300)))
	{
		buf2[ret] = '\0';
		//		printf("%s\n", buf2);
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
	char *s1;
	char *long_str;

	long_str = "Les sanglots longs des violons de l'automne blessent mon coeur d'une langueur monotone. Tout suffocant et blême quand sonne l'heure, je me souviens des jours anciens et je pleure. Et je m'en vais au vent mauvais qui m'emporte, deça, delà, pareil à la feuille morte.";
	//TEST STRLEN
	printf("%s1. TESTING STRLEN%s\n", YELLOW, WHITE);
	//TEST 1
	if (ft_strlen("Bonjour") == strlen("Bonjour"))
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("ft_strlen = %ld\n", ft_strlen("Bonjour"));
	printf("strlen = %ld\n", strlen("Bonjour"));

	//TEST 2
	if (ft_strlen("") == strlen(""))
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("ft_strlen = %ld\n", ft_strlen(""));
	printf("strlen = %ld\n", strlen(""));

	//TEST 3
	if (ft_strlen(long_str) == strlen(long_str))
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("ft_strlen = %ld\n", ft_strlen(long_str));
	printf("strlen = %ld\n", strlen(long_str));

	//TEST STRCPY
	printf("%s2. TESTING STRCPY%s\n", YELLOW, WHITE);
	//TEST 1
	if (!(s = malloc(8)) || !(s1 = malloc(8)))
	{
		printf("malloc failed\n");
		return (0);
	}
	if (!strcmp(ft_strcpy(s, "Bonjour"), strcpy(s1, "Bonjour")))
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("ft_strcpy = %s\n", s);
	printf("strcpy = %s\n", s1);
	free(s);
	free(s1);

	//TEST 2
	if (!(s = malloc(8)) || !(s1 = malloc(8)))
	{
		printf("malloc failed\n");
		return (0);
	}
	if (!strcmp(ft_strcpy(s, ""), strcpy(s, "")))
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("ft_strcpy = %s\n", s);
	printf("strcpy = %s\n", s1);
	free(s);
	free(s1);

	//TEST 3
	if (!(s = malloc(4)) || !(s1 = malloc(4)))
	{
		printf("malloc failed\n");
		return (0);
	}
	if (!strcmp(ft_strcpy(s, "\n"), strcpy(s1, "\n")))
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("ft_strcpy = %s\n", s);
	printf("strcpy = %s\n", s1);
	free(s);
	free(s1);

	//TEST STRCMP
	printf("%s3. TESTING STRCMP%s\n", YELLOW, WHITE);
	//TEST 1
	if (ft_strcmp("Bonjour", "Bonji") == strcmp("Bonjour", "Bonji"))
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("ft_strcmp = %d\n", ft_strcmp("Bonjour", "Bonji"));
	printf("strcmp = %d\n", strcmp("Bonjour", "Bonji"));

	//TEST 2
	if (ft_strcmp("Bonjour", "") == strcmp("Bonjour", ""))
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("ft_strcmp = %d\n", ft_strcmp("Bonjour", ""));
	printf("strcmp = %d\n", strcmp("Bonjour", ""));

	//TEST 3
	if (ft_strcmp("Bonji", "Bonji") == strcmp("Bonji", "Bonji"))
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("ft_strcmp = %d\n", ft_strcmp("Bonji", "Bonji"));
	printf("strcmp = %d\n", strcmp("Bonji", "Bonji"));

	//TEST 4
	if (ft_strcmp("", "") == strcmp("", ""))
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("ft_strcmp = %d\n", ft_strcmp("", ""));
	printf("strcmp = %d\n", strcmp("", ""));

	//TEST 5
	if (ft_strcmp("Bonjour", "Bonjouri") == strcmp("Bonjour", "Bonjouri"))
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("ft_strcmp = %d\n", ft_strcmp("Bonjour", "Bonjouri"));
	printf("strcmp = %d\n", strcmp("Bonjour", "Bonjouri"));

	//TEST 6
	if (ft_strcmp(long_str, long_str + 1) == strcmp(long_str, long_str + 1))
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("ft_strcmp = %d\n", ft_strcmp(long_str, long_str + 1));
	printf("strcmp = %d\n", strcmp(long_str, long_str + 1));
	
	//TEST WRITE
	printf("%s4. TESTING WRITE%s\n", YELLOW, WHITE);
	ft_test_write();

	//TEST READ
	printf("%s5. TESTING READ%s\n", YELLOW, WHITE);
	ft_test_read();

	//TEST STRDUP
	printf("%s6. TESTING STRDUP%s\n", YELLOW, WHITE);
	//TEST 1
	if (!strcmp(ft_strdup("Bonjour"), strdup("Bonjour")))
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("ft_strdup = %s\n", ft_strdup("Bonjour"));
	printf("strdup = %s\n", strdup("Bonjour"));

	//TEST 2
	if (!strcmp(ft_strdup(""), strdup("")))
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("ft_strdup = %s\n", ft_strdup(""));
	printf("strdup = %s\n", strdup(""));

	//TEST 3
	if (!strcmp(ft_strdup(long_str), strdup(long_str)))
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("ft_strdup = %s\n", ft_strdup(long_str));
	printf("strdup = %s\n", strdup(long_str));
	return (0);
}
