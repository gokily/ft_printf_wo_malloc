#include <stdio.h>
#include "ft_printf.h"

static void ind_test(int nb, char *str)
{
	int		reta;
	int		retb;

	printf("*~*~* Test %.2i *~*~*\n", nb);
	reta = printf(str, 2);
	printf("\n");
	retb = ft_printf(str, 2);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
}

int	test_undef(void)
{
	ind_test(1, "%");
	return (1);
}	
