#include <stdio.h>
#include <string.h>
#include "ft_printf.h"
#include <stdlib.h>

void ind_test(int nb, char *str, int i);

int	test_0(void)
{
	int		i;

	i = 0;
	ind_test(1, "%x", i);
	ind_test(2, "%.x", i);
	ind_test(3, "%#x", i);
	ind_test(4, "%#.x", i);
	ind_test(5, "%o", i);
	ind_test(6, "%.o", i);
	ind_test(7, "%#o", i);
	ind_test(8, "%#.o", i);

	ind_test(9, "%.5x", i);
	ind_test(10, "%#.5x", i);
	ind_test(11, "%.5o", i);
	ind_test(12, "%#.5o", i);

	ind_test(13, "%5x", i);
	ind_test(14, "%#5x", i);
	ind_test(15, "%5o", i);
	ind_test(16, "%#5o", i);

	ind_test(17, "%5.x", i);
	ind_test(18, "%#5.x", i);
	ind_test(19, "%5.o", i);
	ind_test(20, "%#5.o", i);

	return (0);
}
