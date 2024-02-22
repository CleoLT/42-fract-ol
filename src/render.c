/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:16:08 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/22 16:50:17 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fract-ol.h"

//regla de 3 con las distancias
double scale_pixel(double current_pixel, double win_max, double win_min, double new_max, double new_min)
{
	return ((current_pixel - win_min) * (new_max - new_min) / (win_max - win_min) + new_min);
}

/*
static void	set_pixels(int pixel_x, int pixel_y, t_fractol *f)
{
	t_number	complex_z;
	
	complex_z.x = scaled_pixel(pixel_x, WIDTH, 0, 2, -2);
	complex_z.y = scaled_pixel(pixel_y, HEIGHT, 0, -2, 2);
	
	
}
*/

static t_number	fractal_equation(t_number c, t_number z)
{
	t_number	result;

	result.x = z.x * z.x - z.y * z.y + c.x;
	result.y = 2 * z.x * z.y + c.y;
	return (result);
}
/*
static int	fractal_iteration(t_number c)
{
	int			count;
	t_number	z;
	double		tmp_zx;
	
	z.x = 0;
	z.y = 0;
	count = 0;
	while (count < 50)
	{
		if ((z.x * z.x + z.y *z.y) > 4)
			break;
		tmp_zx = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = tmp_zx;
		count++;
	}
	return (count);
}

static void	pixel_color(t_fractol *f, int x, int y, int color)
{
	f->img_addr[x * 4 + y * WIDTH * 4] = color;
	f->img_addr[x * 4 + y * WIDTH * 4 + 1] = color >> 8;

}

*/
static void set_pixel_color(int y, int x, t_fractol *f, int color)
{
	int offset;
	offset = y * f->img_line + x * (f->img_bpp / 8);
	*(unsigned int *)(f->img_addr + offset) = color;


}

static void	iteration_to_pixel(t_fractol *f, int pixel_x, int pixel_y, t_number complex_c)
{
	int			i;
	int 		color;
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
	//	ft_printf("%d", i);	
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
//	int			iter;

//	f->color = ft_calloc((50 + 1), sizeof(int));
	pixel_y = -1;
	while (++pixel_y < HEIGHT)
	{
	//	complex_c.y = scale_pixel(pixel_y, HEIGHT, 0, -2, 2);
		pixel_x = -1;
		while (++pixel_x < WIDTH)
		{
		//	iter = fractal_iteration(complex_c);
		//ft_printf("%d ", iter);
		complex_c.y = scale_pixel(pixel_y, HEIGHT, 0, -2, 2);		
		complex_c.x = scale_pixel(pixel_x, WIDTH, 0, 2, -2);
		iteration_to_pixel(f, pixel_x, pixel_y, complex_c);
	//	pixel_color(f, pixel_x, pixel_y, f->color[iter]);
		}
	}
	mlx_put_image_to_window(f->conn, f->win, f->img, 0, 0);
}
