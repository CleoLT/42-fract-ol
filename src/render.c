/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:16:08 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/29 15:37:59 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"

static void	set_pixel_color(int y, int x, t_fractol *f, int color)
{
	int	first_byte_pixel;

	first_byte_pixel = y * f->img_line + x * (f->img_bpp / 8);
	*(int *)(f->img_addr + first_byte_pixel) = color;
}

void	render(t_fractol *f)
{
	int		pixel_x;
	int		pixel_y;
	double	c_x;
	double	c_y;
	int		iter;

	pixel_y = -1;
	printf("%X\n", BLUE);
	while (++pixel_y < HEIGHT)
	{
		c_y = ((double)pixel_y * 4 / HEIGHT - 2) * f->zoom + f->shift.y;
		pixel_x = -1;
		while (++pixel_x < WIDTH)
		{
			c_x = ((double)pixel_x * 4 / WIDTH - 2) * f->zoom + f->shift.x;
			iter = fractal_equation(f, c_x, c_y);
			if (iter < f->iter)
				set_pixel_color(pixel_y, pixel_x, f, (double)iter * BLUE / f->iter);
			else 
				set_pixel_color(pixel_y, pixel_x, f, BLACK);
		}
	}
	mlx_put_image_to_window(f->conn, f->win, f->img, 0, 0);
}
