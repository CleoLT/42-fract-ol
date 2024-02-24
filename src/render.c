/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:16:08 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/22 18:38:19 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fract-ol.h"

double	scale_pixel(double current_pixel, double win_max, double win_min, double new_max, double new_min)
{
	return ((current_pixel - win_min) * (new_max - new_min) / (win_max - win_min) + new_min);
}

static t_number	fractal_equation(t_number c, t_number z)
{
	t_number	result;

	result.x = z.x * z.x - z.y * z.y + c.x;
	result.y = 2 * z.x * z.y + c.y;
	return (result);
}

static void	set_pixel_color(int y, int x, t_fractol *f, int color)
{
	int	pixel;
	int	i;

	pixel = y * f->img_line + x * (f->img_bpp / 8);
	if (x == 1 && y == 0)
	{
		printf("offset %d \n", pixel);
		printf("%c\n", f->img_addr[0]);
		printf("%c\n", f->img_addr[1]);
	}
//	line : 3600 line = (WIDTH *4), bpp : 32 
	f->img_addr[pixel] = color;
	f->img_addr[pixel + 1] = color >> 8;
	f->img_addr[pixel + 2] = color >> 16;
	f->img_addr[pixel + 3] = color >> 24;
//	*(int *)(f->img_addr + pixel) = color;
	if (x == 1 && y == 0)
	{
		i = 0;
		while (i < 10)
		{
			printf("%d\n", f->img_addr[i]);
			i++;
		}
/*		printf("offset %d \n", offset);
		printf("%d\n", f->img_addr[0]);
		printf("%d\n", f->img_addr[1]);
		printf("%d\n", f->img_addr[2]);
		printf("%d\n", f->img_addr[3]);
		printf("%d\n", f->img_addr[4]);
		printf("%d\n", f->img_addr[5]);
		printf("%d\n", (unsigned int *)(f->img_addr + offset)[3]) ;*/
	}
}

static void	iteration_to_pixel(t_fractol *f, int pixel_x, int pixel_y, t_number complex_c)
{
	int			i;
	int			color;
	t_number	complex_z;

//	t_number	complex_c;
//	complex_c.y = scale_pixel(pixel_y, HEIGHT, 0, -2, 2);		
//	complex_c.x = scale_pixel(pixel_x, WIDTH, 0, 2, -2);
	f->iteration = 100;
	complex_z.x = 0;
	complex_z.y = 0;
	i = 0;
	while (i < f->iteration)
	{
		complex_z = fractal_equation(complex_c, complex_z);
		if ((complex_z.x * complex_z.x) + (complex_z.y * complex_z.y) > 4)
		{
			color = scale_pixel(i, f->iteration, 0, BLACK, WHITE);
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
	int			pixel_x;
	int			pixel_y;

	pixel_y = -1;
	while (++pixel_y < HEIGHT)
	{
	//	complex_c.y = scale_pixel(pixel_y, HEIGHT, 0, -2, 2);
		pixel_x = -1;
		while (++pixel_x < WIDTH)
		{
			complex_c.y = scale_pixel(pixel_y, HEIGHT, 0, -2, 2);
			complex_c.x = scale_pixel(pixel_x, WIDTH, 0, 2, -2);
			iteration_to_pixel(f, pixel_x, pixel_y, complex_c);
		}
	}
	mlx_put_image_to_window(f->conn, f->win, f->img, 0, 0);
}
