#include <stdio.h>
#include <string.h>
#include "ft_printf.h"
#include <stdlib.h>

int	test_s(void);
int test_p(void);

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

	return (0);
}
