/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 13:21:47 by user42            #+#    #+#             */
/*   Updated: 2020/12/15 15:43:13 by user42           ###   ########.fr       */
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

size_t	ft_strlen(const char *s);
int	ft_atoi_base(char *s, char *base);

void	ft_test_atoi_base(void)
{
	char	*a;
	char	*b;

	a = "1000";
	b = "0123456789";
	printf("number : %s\nbase = <%s>\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	if (ft_atoi_base(a, b) == 1000)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	a = "-1000";
	b = "0123456789";
	printf("number : %s\nbase = <%s>\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	if (ft_atoi_base(a, b) == -1000)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	a = "-54";
	b = "0123456789";
	printf("number : %s\nbase = <%s>\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	if (ft_atoi_base(a, b) == -54)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	a = "10";
	b = "0123456789ABCDEFG";
	printf("number : %s\nbase = <%s>\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	if (ft_atoi_base(a, b) == 17)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	a = "10";
	b = "01234";
	printf("number : %s\nbase = <%s>\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	if (ft_atoi_base(a, b) == 5)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	a = "10";
	b = "01XF";
	printf("number : %s\nbase = <%s>\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	if (ft_atoi_base(a, b) == 4)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	a = "XF";
	b = "01XF";
	printf("number : %s\nbase = <%s>\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	if (ft_atoi_base(a, b) == 11)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	a = "10";
	b = "01 ";
	printf("number : %s\nbase = <%s>\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	if (ft_atoi_base(a, b) == 0)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	a = "10";
	b = "01+";
	printf("number : %s\nbase = <%s>\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	if (ft_atoi_base(a, b) == 0)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	a = "10";
	b = "2";
	printf("number : %s\nbase = <%s>\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	if (ft_atoi_base(a, b) == 0)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	a = "";
	b = "203";
	printf("number : %s\nbase = <%s>\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	if (ft_atoi_base(a, b) == 0)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	a = "";
	b = "2";
	printf("number : %s\nbase = <%s>\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	if (ft_atoi_base(a, b) == 0)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	a = "0";
	b = "1234";
	printf("number : %s\nbase = <%s>\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	if (ft_atoi_base(a, b) == 0)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	a = "1";
	b = "0234";
	printf("number : %s\nbase = <%s>\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	if (ft_atoi_base(a, b) == 0)
		printf("%sCORRECT%s\n", GREEN, WHITE);
	else
		printf("%sERROR%s\n", RED, WHITE);
	return ;
}

int	main(void)
{
	printf("%sBONUS 1. TESTING ATOI_BASE%s\n", YELLOW, WHITE);
	ft_test_atoi_base();
	return (0);	
}
