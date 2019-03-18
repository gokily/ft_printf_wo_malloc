#include <stdio.h>
#include <string.h>
#include "ft_printf.h"
#include <stdlib.h>

void ind_test(int nb, char *str, int i);

int	test_mouli(void)
{
	int		i;

	i = 0;
	ind_test(1, "%p", i);
	ind_test(2, "{%5p}", i);
	ind_test(3, "{%03c}", i);
	ind_test(4, "%#.x", i);
	ind_test(5, "%.u", i);
	ind_test(6, "%.0u", i);
	ind_test(7, "%.p", i);
	ind_test(8, "%.0p", i);

	return (0);
}
