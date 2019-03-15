#include <stdio.h>
#include <string.h>
#include "ft_printf.h"
#include <stdlib.h>

int	test_s(void);
int test_p(void);
int test_d(void);
int test_u(void);
int test_o(void);
int test_x(void);
int test_f(void);
int test_0(void);
int test_undef(void);

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		printf("Need the first argument to be a string with the type of test\n");
		return (1);
	}
	if (strchr(av[1], 's'))
		test_s();
	if (strchr(av[1], 'p'))
		test_p();
	if (strchr(av[1], 'd') || strchr(av[1], 'i'))
		test_d();
	if (strchr(av[1], 'u'))
		test_u();
	if (strchr(av[1], 'o'))
		test_o();
	if (strchr(av[1], 'x'))
		test_x();
	if (strchr(av[1], 'f'))
		test_f();
	if (strchr(av[1], '0'))
		test_0();
	if (strchr(av[1], 'n'))
		test_undef();
	return (0);
}
