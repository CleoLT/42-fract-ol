/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:27:27 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/25 14:38:52 by ale-tron         ###   ########.fr       */
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

t_number	fractal_equation(t_fractol *f, t_number c, t_number z)
{
	t_number	result;

	if (f->type == MANDELBROT)
		result = mandelbrot(c, z);
	if (f->type == JULIA)
		result = julia(f, z);
	return (result);
}

