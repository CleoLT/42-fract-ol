/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:27:27 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/27 11:16:27 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"

static t_number	mandelbrot(t_number c, t_number z)
{
	t_number	result;

	result.x = z.x * z.x - z.y * z.y + c.x;
	result.y = 2 * z.x * z.y + c.y;
	return (result);
}

static t_number	julia(t_fractol *f, t_number z)
{
	t_number	result;

	result.x = z.x * z.x - z.y * z.y + f->julia_c.x;
	result.y = 2 * z.x * z.y + f->julia_c.y;
	return (result);
}

static t_number	burning_ship(t_number c, t_number z)
{
	t_number	result;

	z.x = fabs(z.x);
	z.y = fabs(z.y);
	result.x = z.x * z.x - z.y * z.y + c.x;
	result.y = 2 * z.x * z.y + c.y;
	return (result);
}

//z = z³ + 1 / c²
static t_number	mandel_reverse(t_number c, t_number z)
{
	t_number	result;
	double		c_divisor;

	c_divisor = c.x * c.x * c.x * c.x + 2 * c.x * c.x * c.y * c.y + \
				c.y * c.y * c.y * c.y;
	result.x = z.x * z.x * z.x - 3 * z.x * z.y * z.y + \
				(c.x * c.x + c.y * c.y) / c_divisor;
	result.y = 3 * z.x * z.x * z.y - z.y * z.y * z.y - \
				2 * c.x * c.y / c_divisor;
	return (result);
}

t_number	fractal_equation(t_fractol *f, t_number c, t_number z)
{
	t_number	result;

	if (f->type == MANDELBROT)
		result = mandelbrot(c, z);
	if (f->type == JULIA)
		result = julia(f, z);
	if (f->type == BURNINGSHIP)
		result = burning_ship(c, z);
	if (f->type == MANDELREVERSE)
		result = mandel_reverse(c, z);
	return (result);
}
