#include <stdio.h>
#include <string.h>
#include "ft_printf.h"
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

void ind_test(int nb, char *str, int i);

int	test_jzt(void)
{
	int		i;
	ptrdiff_t	p;
	size_t		t;

	printf("The size of long long is %lu\n", sizeof(long long));
	printf("The size of long is %lu\n", sizeof(long));
	printf("The size of int is %lu\n", sizeof(int));
	printf("The size of intmax_t is %lu\n", sizeof(intmax_t));
	printf("The size of size_t is %lu\n", sizeof(size_t));
	i = -333333;
	p = -333333;
	t = -2555555555;

	printf("%td\n", p);
	ft_printf("%td\n", p);
	puts("");
	printf("%tu\n", p);
	ft_printf("%tu\n", p);
	puts("");
	printf("%zd\n", t);
	ft_printf("%td\n", t);
	puts("");
	printf("%zu\n", t);
	ft_printf("%tu\n", t);
	return (0);
}
