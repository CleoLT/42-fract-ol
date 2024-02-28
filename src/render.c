/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:16:08 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/28 19:41:53 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"
/*
static double	scale_pixel(double current_pixel, t_offset o)
{
	return ((current_pixel - o.old_min) * (o.new_max - o.new_min) / \
			(o.old_max - o.old_min) + o.new_min);
}
*/
static void	set_pixel_color(int y, int x, t_fractol *f, int color)
{
	int	first_byte_pixel;

	first_byte_pixel = y * f->img_line + x * (f->img_bpp / 8);
	*(int *)(f->img_addr + first_byte_pixel) = color;
}

static void	init_complex_z(t_number *complex_z, t_number *complex_c, \
															t_fractol *f)
{
	complex_z->x = 0;
	complex_z->y = 0;
	if (f->type == JULIA)
	{
		complex_z->x = complex_c->x;
		complex_z->y = complex_c->y;
	}
}

static void	iteration_to_pixel(t_fractol *f, int pixel_x, int pixel_y, \
														t_number complex_c)
{
	int			i;
	int			color;
	t_number	complex_z;

	init_complex_z(&complex_z, &complex_c, f);
	i = 0;
	while (i < f->iteration)
	{
		complex_z = fractal_equation(f, complex_c, complex_z);
		if ((complex_z.x * complex_z.x) + (complex_z.y * complex_z.y) > 4)
		{
			color = i * (WHITE - YELLOW) / f->iteration;
		//	color = blend_color(0x0000FF, BLACK, (double)i / f->iteration);
			set_pixel_color(pixel_y, pixel_x, f, color);
			return ;
		}
		i++;
	}
	set_pixel_color(pixel_y, pixel_x, f, BLACK);
}

void	render(t_fractol *f)
{
	t_number	complex_c;
//	t_offset	win_height;
//	t_offset	win_width;
	int			pixel_x;
	int			pixel_y;

//	init_offset_win(&win_height, &win_width);
	pixel_y = -1;
	while (++pixel_y < HEIGHT)
	{
		complex_c.y = ((double)pixel_y * 4 / HEIGHT - 2) * f->zoom + f->shift.y;
		pixel_x = -1;
		while (++pixel_x < WIDTH)
		{
	//		complex_c.y = scale_pixel(pixel_y, win_height) * f->zoom + f->shift.y;
	//		complex_c.x = scale_pixel(pixel_x, win_width) * f->zoom \ + f->shift.x;
			complex_c.x = ((double)pixel_x * 4 / WIDTH - 2) * f->zoom + f->shift.x;
			iteration_to_pixel(f, pixel_x, pixel_y, complex_c);
		}
	}
	mlx_put_image_to_window(f->conn, f->win, f->img, 0, 0);
}
