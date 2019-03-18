#include <stdio.h>
#include <string.h>
#include "ft_printf.h"
#include <stdlib.h>

void ind_test(int nb, char *str, int i);
void ind_test_str(int nb, char *str, char *i);

int	test_mouli(void)
{
	int		i;
	int		b;

	i = 0;
	b = 42;
	ind_test(1, "%p", i);
	ind_test(1, "%04p", b);
	ind_test(2, "{%5p}", i);
	ind_test(3, "{%03c}", i);
	ind_test(3, "{%3%}", i);
	ind_test(3, "{%03%}", i);
puts("");
	ind_test(4, "%#.x", i);
	ind_test(4, "%5.u", i);
	ind_test(5, "%.u", i);
	ind_test(6, "%.0u", i);
	ind_test(7, "%.p", i);
	ind_test(8, "%.0p", i);
	ind_test(9, "%10.0p", i);
	ind_test(10, "%.0p", b);
	ind_test(11, "%.5p", b);
puts("");

	ind_test_str(12, "{%05.s}", NULL);
	ind_test_str(13, "{%05s}", "abc");

	return (0);
}
