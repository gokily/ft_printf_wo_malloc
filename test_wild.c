#include <stdio.h>
#include <string.h>
#include "ft_printf.h"
#include <stdlib.h>

void ind_test_wild(int nb, char *str, int i, int w);

int	test_wild(void)
{
	int		i;
	int		b;

	i = 0;
	b = 42;
	ind_test_wild(1, "%*d", i, 0);
	ind_test_wild(2, "%*d", b, 0);
	ind_test_wild(3, "{%*d}", i, 5);
	ind_test_wild(4, "{%*d}", b, 5);

	ind_test_wild(3, "{%*d}", i, -5);
	ind_test_wild(4, "{%*d}", b, -5);
	
	ind_test_wild(5, "{%*d}", b, -2147483648);

	return (0);
}
