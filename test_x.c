#include <stdio.h>
#include <string.h>
#include "ft_printf.h"
#include <stdlib.h>

int	test_x(void)
{
	unsigned long		i = -4294967296;
	unsigned int	j = 94967296;
	unsigned int	k = 542;
	int		reta;
	int		retb;
	char	*format;

	printf("*~*~* Test 1 *~*~*\n");
	format = strdup("%jx");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 2 *~*~*\n");
	format = strdup("%jx");
	reta = printf(format, 0);
	printf("\n");
	retb = ft_printf(format, 0);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 3 *~*~*\n");
	format = strdup("%20x");
	reta = printf(format, j);
	printf("\n");
	retb = ft_printf(format, j);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 4 *~*~*\n");
	format = strdup("%.2x");
	reta = printf(format, j);
	printf("\n");
	retb = ft_printf(format, j);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 5 *~*~*\n");
	format = strdup("%2.20x");
	reta = printf(format, j);
	printf("\n");
	retb = ft_printf(format, j);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 6 *~*~*\n");
	format = strdup("%15.20x");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 7 *~*~*\n");
	format = strdup("%5.8x");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 8 *~*~*\n");
	format = strdup("%5.2x");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 9 *~*~*\n");
	format = strdup("%20.15x");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 10 *~*~*\n");
	format = strdup("%20.5x");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 11 *~*~*\n");
	format = strdup("%20.5lx");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 12 *~*~*\n");
	format = strdup("%20.5hhx");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 13 *~*~*\n");
	format = strdup("%20.5hx");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 14 *~*~*\n");
	format = strdup("%20.5x");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 15 *~*~*\n");
	format = strdup("%+20.5x");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 16 *~*~*\n");
	format = strdup("% -20x");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 17 *~*~*\n");
	format = strdup("%-+20x");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 18 *~*~*\n");
	format = strdup("%010x");
	reta = printf(format, k);
	printf("\n");
	retb = ft_printf(format, k);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	return (1);
}
