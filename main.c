/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:35:57 by prando-a          #+#    #+#             */
/*   Updated: 2023/08/28 16:14:54 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int	ft_isint(char *str)
{
	int	i;
	int	num_check;
	int	sym_lock;
	int	float_check;

	i = 0;
	num_check = 0;
	sym_lock = 0;
	if (!*str)
		return (0);
	while (str[i] && str[i] != '.')
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (sym_lock++ == 0 && str[i + 1] >= '0' && str[i + 1] <= '9')
				num_check++;
		}
		if (str[i] >= '0' && str[i] <= '9')
			num_check++;
		i++;
	}
	float_check = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (float_check++ == 0 && str[i + 1] >= '0' && str[i + 1] <= '9')
				num_check++;
		}
		if (str[i] >= '0' && str[i] <= '9')
			num_check++;
		i++;
	}
	if (num_check == i && float_check == 0)
		return (1);
	else if (num_check == i && float_check == 1)
		return (2);
	else
		return (0);
}

int	arg_check(char *str, int mode)
{
	if (ft_isint(str) != 0)
	{
		if (mode == 1)
		{
			if (ft_isint(str) == 1)
				return (printf("%lld", atoll(str)), 0);
			else
				return (printf("%f", atof(str)), 0);
		}
		else
			return (1);
	}
	if (mode == 2)
	{
		if ((str[0] == '-' && !str[1]) || (str[0] == '+' && !str[1])
			|| (str[0] == '*' && !str[1]) || (str[0] == '/' && !str[1]))
			return (1);
	}
	return (printf("INVALID NUMBER AND / OR OPERATION "), -1);
}

int	main(int argc, char **argv)
{
	int				i;
	double long		res;
	double long		res_frac;
	double long		res_int;

	if (argc == 1)
		return (printf("NO INPUT DATA"));
	if (argc == 2)
		return (arg_check(argv[1], 1));
	i = 1;
	while (argv[i])
	{
		if (arg_check(argv[i++], 2) == -1)
			return (-1);
	}
	i = 1;
	res = 0;
	if (!argv[i + 2])
		return (arg_check("", 1));
	if (argv[i + 1][0] == '-')
		res += atof(argv[i]) - atof(argv[i + 2]);
	else if (argv[i + 1][0] == '+')
		res += atof(argv[i]) + atof(argv[i + 2]);
	else if (argv[i + 1][0] == '*')
		res += atof(argv[i]) * atof(argv[i + 2]);
	else if (argv[i + 1][0] == '/')
		res += atof(argv[i]) / atof(argv[i + 2]);
	if (argv[i + 1])
		i += 2;
	while (argv[i + 1])
	{
		if (!argv[i + 2])
			return (arg_check("", 1));
		if (argv[i + 1][0] == '-')
			res -= atof(argv[i + 2]);
		else if (argv[i + 1][0] == '+')
			res += atof(argv[i + 2]);
		else if (argv[i + 1][0] == '*')
			res *= atof(argv[i + 2]);
		else if (argv[i + 1][0] == '/')
			res /= atof(argv[i + 2]);
		if (argv[i + 1])
			i += 2;
	}
	res_int = (long long)res;
	res_frac = res - res_int;
	if (!res_frac)
		return (printf("%.Lf", res_int), 0);
	return (printf("%Lf", res), 0);
}
