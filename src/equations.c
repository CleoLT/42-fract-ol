/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:27:27 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/29 15:55:11 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"

static int	mandelbrot(double c_x, double c_y, t_fractol *f)
{
	int		i;
	double	z_x;
	double	z_y;
	double	tmp_zx;

	z_x = 0;
	z_y = 0;
	i = -1;
	while (z_x * z_x + z_y * z_y < 4 && ++i < f->iter)
	{
		tmp_zx = z_x * z_x - z_y * z_y + c_x;
		z_y = 2 * z_x * z_y + c_y;
		z_x = tmp_zx;
	}
	return (i);
}

static int	julia(double c_x, double c_y, t_fractol *f)
{
	int		i;
	double	tmp_zx;
	double	z_x;
	double	z_y;

	i = 0;
	z_x = c_x;
	z_y = c_y;
	while (z_x * z_x + z_y * z_y < 4 && ++i < f->iter)
	{
		tmp_zx = z_x * z_x - z_y * z_y + f->julia_c.x;
		z_y = 2 * z_x * z_y + f->julia_c.y;
		z_x = tmp_zx;
	}
	return (i);
}

static int	burning_ship(double c_x, double c_y, t_fractol *f)
{
	int		i;
	double	z_x;
	double	z_y;
	double	tmp_zx;

	i = 0;
	z_x = 0;
	z_y = 0;
	while (z_x * z_x + z_y * z_y < 4 && ++i < f->iter)
	{
		z_x = fabs(z_x);
		z_y = fabs(z_y);
		tmp_zx = z_x * z_x - z_y * z_y + c_x;
		z_y = 2 * z_x * z_y + c_y;
		z_x = tmp_zx;
	}
	return (i);
}

//z = z³ + 1 / c²
static int	mandel_reverse(double c_x, double c_y, t_fractol *f)
{
	int		i;
	double	c_divisor;
	double	z_x;
	double	z_y;
	double	tmp_zx;

	i = 0;
	z_x = 0;
	z_y = 0;
	while (z_x * z_x + z_y * z_y < 4 && ++i < f->iter)
	{
		c_divisor = c_x * c_x * c_x * c_x + 2 * c_x * c_x * c_y * c_y + \
				c_y * c_y * c_y * c_y;
		tmp_zx = z_x * z_x * z_x - 3 * z_x * z_y * z_y + \
				(c_x * c_x + c_y * c_y) / c_divisor;
		z_y = 3 * z_x * z_x * z_y - z_y * z_y * z_y - \
				2 * c_x * c_y / c_divisor;
		z_x = tmp_zx;
	}
	return (i);
}

int	fractal_equation(t_fractol *f, double c_x, double c_y)
{
	int	result;

	result = 0;
	if (f->type == MANDELBROT)
		result = mandelbrot(c_x, c_y, f);
	if (f->type == JULIA)
		result = julia(c_x, c_y, f);
	if (f->type == BURNINGSHIP)
		result = burning_ship(c_x, c_y, f);
	if (f->type == MANDELREVERSE)
		result = mandel_reverse(c_x, c_y, f);
	return (result);
}
