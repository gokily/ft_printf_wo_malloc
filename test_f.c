#include <stdio.h>
#include <string.h>
#include "ft_printf.h"
#include <stdlib.h>

int	test_f(void)
{
	double		i = 123456.7854545822190;
	long double	t = -444441.2531256431634567890;
	long double	l = -4567.9999999;
	int		reta;
	int		retb;
	char	*format;

	printf("*~*~* Test 1 *~*~*\n");
	format = strdup("%f");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 2 *~*~*\n");
	format = strdup("%f");
	reta = printf(format, 10.0);
	printf("\n");
	retb = ft_printf(format, 10.0);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 3 *~*~*\n");
	format = strdup("%Lf");
	reta = printf(format, l);
	printf("\n");
	retb = ft_printf(format, l);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 4 *~*~*\n");
	format = strdup("%Lf");
	reta = printf(format, t);
	printf("\n");
	retb = ft_printf(format, t);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 5 *~*~*\n");
	format = strdup("%.8f");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 6 *~*~*\n");
	format = strdup("%20f");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 7 *~*~*\n");
	format = strdup("%020f");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 8 *~*~*\n");
	format = strdup("%+20f");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 9 *~*~*\n");
	format = strdup("% f");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 10 *~*~*\n");
	format = strdup("%-020f");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	printf("*~*~* Test 11 *~*~*\n");
	format = strdup("%020.15f");
	reta = printf(format, i);
	printf("\n");
	retb = ft_printf(format, i);
	ft_printf("\n");
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);

	l = -9223372936854775808.000000;
	printf("*~*~* Test 12 *~*~*\n");
	format = strdup("\\!/%20.56lf\\!/");
	reta = printf(format, l);
	printf("\n");
	retb = ft_printf(format, l);
	ft_printf("\n");
	printf("ret is %d", reta);
	printf(reta == retb ? "OK\n" : "KO, our ret is %d and the correct one is %d\n",
			retb, reta);
	free(format);
	return (1);
}
