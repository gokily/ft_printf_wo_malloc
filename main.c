#include <stdio.h>
#include <string.h>
#include "ft_printf.h"
#include <stdlib.h>

int	test_s(void)
{
	char	*str = "test";
	int		reta;
	int		retb;
	char	*format;

	printf("*~*~* Test 1 *~*~*\n");
	format = strdup("%s");
	reta = printf(format, str);
	printf("\n");
	retb = ft_printf(format, str);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 2 *~*~*\n");
	format = strdup("%s");
	reta = printf(format, NULL);
	printf("\n");
	retb = ft_printf(format, NULL);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 3 *~*~*\n");
	format = strdup("%20s");
	reta = printf(format, str);
	printf("\n");
	retb = ft_printf(format, str);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 4 *~*~*\n");
	format = strdup("%.2s");
	reta = printf(format, str);
	printf("\n");
	retb = ft_printf(format, str);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 5 *~*~*\n");
	format = strdup("%10.2s");
	reta = printf(format, str);
	printf("\n");
	retb = ft_printf(format, str);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 6 *~*~*\n");
	format = strdup("%-10.2s");
	reta = printf(format, str);
	printf("\n");
	retb = ft_printf(format, str);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 7 *~*~*\n");
	format = strdup("%-10.2s");
	str = NULL;
	reta = printf(format, str);
	printf("\n");
	retb = ft_printf(format, str);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	return (1);
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
	return (0);
}
