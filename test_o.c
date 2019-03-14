#include <stdio.h>
#include <string.h>
#include "ft_printf.h"
#include <stdlib.h>

int	test_o(void)
{
	int		i = 1234567890;
	unsigned long	t = 444444441234567890;
	unsigned long	l = 331234567890;
	int		reta;
	int		retb;
	char	*format;

	printf("*~*~* Test 1 *~*~*\n");
	format = strdup("%o");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 2 *~*~*\n");
	format = strdup("%o");
	reta = printf(format, 0);
	printf("\n");
	retb = ft_printf(format, 0);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 3 *~*~*\n");
	format = strdup("%20o");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 4 *~*~*\n");
	format = strdup("%.2o");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 5 *~*~*\n");
	format = strdup("%2.20o");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 6 *~*~*\n");
	format = strdup("%15.20o");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 7 *~*~*\n");
	format = strdup("%5.8o");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 8 *~*~*\n");
	format = strdup("%5.2o");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 9 *~*~*\n");
	format = strdup("%20.15o");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 10 *~*~*\n");
	format = strdup("%20.5o");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 11 *~*~*\n");
	format = strdup("%20.5lo");
	reta = printf(format, l);
	printf("\n");
	retb = ft_printf(format, l);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 12 *~*~*\n");
	format = strdup("%20.5hho");
	reta = printf(format, l);
	printf("\n");
	retb = ft_printf(format, l);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 13 *~*~*\n");
	format = strdup("%20.5ho");
	reta = printf(format, l);
	printf("\n");
	retb = ft_printf(format, l);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 14 *~*~*\n");
	format = strdup("%20.5o");
	reta = printf(format, t);
	printf("\n");
	retb = ft_printf(format, t);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 15 *~*~*\n");
	format = strdup("%+20.5o");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 16 *~*~*\n");
	format = strdup("% -20o");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 17 *~*~*\n");
	format = strdup("%-+20o");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);


	return (1);
}
