#include <stdio.h>
#include <string.h>
#include "ft_printf.h"
#include <stdlib.h>

int	test_d(void)
{
	int		i = -1234567890;
	long	l = -331234567890;
	int		reta;
	int		retb;
	char	*format;

	printf("*~*~* Test 1 *~*~*\n");
	format = strdup("%d");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 2 *~*~*\n");
	format = strdup("%d");
	reta = printf(format, 0);
	printf("\n");
	retb = ft_printf(format, 0);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 3 *~*~*\n");
	format = strdup("%20d");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 4 *~*~*\n");
	format = strdup("%.2d");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 5 *~*~*\n");
	format = strdup("%2.20d");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 6 *~*~*\n");
	format = strdup("%15.20d");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 7 *~*~*\n");
	format = strdup("%5.8d");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 8 *~*~*\n");
	format = strdup("%5.2d");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 9 *~*~*\n");
	format = strdup("%20.15d");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 10 *~*~*\n");
	format = strdup("%20.5d");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 11 *~*~*\n");
	format = strdup("%20.5ld");
	reta = printf(format, l);
	printf("\n");
	retb = ft_printf(format, l);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 12 *~*~*\n");
	format = strdup("%20.5hhd");
	reta = printf(format, l);
	printf("\n");
	retb = ft_printf(format, l);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 13 *~*~*\n");
	format = strdup("%20.5hi");
	reta = printf(format, l);
	printf("\n");
	retb = ft_printf(format, l);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);
	return (1);
}
