#include <stdio.h>
#include <string.h>
#include "ft_printf.h"
#include <stdlib.h>

int	test_p(void)
{
	char	*str = "test";
	int		reta;
	int		retb;
	char	*format;

	printf("*~*~* Test 1 *~*~*\n");
	format = strdup("%p");
	reta = printf(format, &str);
	printf("\n");
	retb = ft_printf(format, &str);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 2 *~*~*\n");
	format = strdup("%p");
	reta = printf(format, NULL);
	printf("\n");
	retb = ft_printf(format, NULL);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 3 *~*~*\n");
	format = strdup("%20p");
	reta = printf(format, &str);
	printf("\n");
	retb = ft_printf(format, &str);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 4 *~*~*\n");
	format = strdup("%.2p");
	reta = printf(format, &str);
	printf("\n");
	retb = ft_printf(format, &str);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 5 *~*~*\n");
	format = strdup("%2.20p");
	reta = printf(format, &str);
	printf("\n");
	retb = ft_printf(format, &str);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 6 *~*~*\n");
	format = strdup("%15.20p");
	reta = printf(format, &str);
	printf("\n");
	retb = ft_printf(format, &str);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 7 *~*~*\n");
	format = strdup("%5.8p");
	reta = printf(format, &str);
	printf("\n");
	retb = ft_printf(format, &str);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 8 *~*~*\n");
	format = strdup("%5.2p");
	reta = printf(format, &str);
	printf("\n");
	retb = ft_printf(format, &str);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 9 *~*~*\n");
	format = strdup("%20.15p");
	reta = printf(format, &str);
	printf("\n");
	retb = ft_printf(format, &str);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 10 *~*~*\n");
	format = strdup("%20.5p");
	reta = printf(format, &str);
	printf("\n");
	retb = ft_printf(format, &str);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	return (1);
}
