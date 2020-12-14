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

size_t	ft_strlen(const char *s);
int	ft_atoi_base(char *s, char *base);

void	ft_test_atoi_base(void)
{
	char	*a;
	char	*b;

	a = "1000";
	b = "0123456789";
	if (ft_atoi_base(a, b) == 1000)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("number : %s\nbase = %s\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	a = "-1000";
	b = "0123456789";
	if (ft_atoi_base(a, b) == -1000)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("number : %s\nbase = %s\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	a = "-54";
	b = "0123456789";
	if (ft_atoi_base(a, b) == -54)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("number : %s\nbase = %s\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	a = "10";
	b = "0123456789ABCDEFG";
	if (ft_atoi_base(a, b) == 17)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("number : %s\nbase = %s\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	a = "10";
	b = "01234";
	if (ft_atoi_base(a, b) == 5)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("number : %s\nbase = %s\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	a = "10";
	b = "01";
	if (ft_atoi_base(a, b) == 2)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("number : %s\nbase = %s\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	a = "10";
	b = "01 ";
	if (ft_atoi_base(a, b) == 0)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("number : %s\nbase = %s\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	a = "10";
	b = "2";
	if (ft_atoi_base(a, b) == 0)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	printf("number : %s\nbase = %s\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	return ;
}

int	main(void)
{
	printf("%sBONUS 1. TESTING ATOI_BASE%s\n", YELLOW, WHITE);
	ft_test_atoi_base();
	return (0);	
}
