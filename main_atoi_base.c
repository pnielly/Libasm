#include <stdio.h>

int	ft_atoi_base(char *s, char *base);

int	main(void)
{
	char	*a;
	char	*b;

	a = "1000";
	b = "0123456789";
	printf("number : %s\nbase = %s\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	a = "-1000";
	b = "0123456789";
	printf("number : %s\nbase = %s\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	a = "10";
	b = "2";
	printf("number : %s\nbase = %s\n ft = %d", a, b, ft_atoi_base(a, b));
	printf("\n");
	return (0);
}
