/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:16:08 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/21 18:13:18 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fract-ol.h"

//regla de 3 con las distancias
double scale_pixel(double current_pixel, double win_max, double win_min, double new_max, double new_min)
{
	return ((current_pixel - win_min) * (new_max - new_min) / (win_max - win_min) + new_min);
}

/*static void	set_pixels(int pixel_x, int pixel_y, t_fractol *f)
{
	t_number	complex_z;
	
	complex_z.x = scaled_pixel(pixel_x, WIDTH, 0, 2, -2);
	complex_z.y = scaled_pixel(pixel_y, HEIGHT, 0, -2, 2);
	
	
}*/
static t_number	fractal_equation(t_number c, t_number z)
{
	t_number	result;

	result.x = z.x * z.x - z.y * z.y + c.x;
	result.y = 2 * z.x * z.y + c.y;
	return (result);
}

void	render(t_fractol *f)
{
	t_number	complex_c;
	t_number	complex_z;
	int			pixel_x;
	int			pixel_y;

	complex_z.x = 0;
	complex_z.y = 0;
	pixel_y = -1;
	while (++pixel_y < HEIGHT)
	{
		complex_c.y = scale_pixel(pixel_y, HEIGHT, 0, -2, 2);
		pixel_x = -1;
		while (++pixel_x < WIDTH)
		{
			complex_c.x = scale_pixel(pixel_x, WIDTH, 0, 2, -2);
			complex_z = fractal_equation(complex_c, complex_z);

		}
	}
	mlx_put_image_to_window(f->conn, f->win, f->img, 0, 0);
}
