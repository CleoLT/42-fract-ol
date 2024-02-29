/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:56:28 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/29 16:15:21 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || \
			c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	skip_space_and_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if ((str[i] && str[i] == '+') || (str[i] && str[i] == '-'))
		i++;
	if (str[i - 1] == '-')
		*sign = -1;
	return (i);
}

double	ft_atod(char *str)
{
	double	nb;
	double	fract;
	int		i;
	int		sign;
	double	power;

	nb = 0;
	sign = 1;
	fract = 0;
	power = 1;
	i = skip_space_and_sign(str, &sign);
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		power /= 10;
		fract = fract + (str[i] - '0') * power;
		i++;
	}
	return ((nb + fract) * sign);
}
