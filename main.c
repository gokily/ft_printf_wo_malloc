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
int test_mouli(void);

void ind_test(int nb, char *str, int i)
{
	int		reta;
	int		retb;

	printf("*~*~* Test %.2i *~*~*\n", nb);
	reta = printf(str, i);
	printf("\n");
	retb = ft_printf(str, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
}

void ind_test_str(int nb, char *str, char *i)
{
	int		reta;
	int		retb;

	printf("*~*~* Test %.2i *~*~*\n", nb);
	reta = printf(str, i);
	printf("\n");
	retb = ft_printf(str, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
}

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
	if (strchr(av[1], 'm'))
		test_mouli();
	return (0);
}
