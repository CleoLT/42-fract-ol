/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:15:51 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/28 17:35:38 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"

int blend_color(int black, int white, double iteration)
{
	int	color;	

	color >> 16 = (1 - iteration) * ((black >> 16) & 0xFF) + iteration * ((white >> 16) & 0xFF); 
	color >> 8 = (1 - iteration) * ((black >> 8) & 0xFF) + iteration * ((white >> 8) & 0xFF); 
	color >> 0 = (1 - iteration) * ((black >> 0) & 0xFF) + iteration * ((white >> 0) & 0xFF); 
	return (color);
}	


/* set_pixel_color:
	Add a color to one pixel of the MLX image map.
	The MLX image is composed of 32 bits per pixel.
	Color ints are stored from right to left, here, and are in
	the form of 0xAARRGGBB. 8 bits encode each color component,
	Alpha (Transparency), Red, Green and Blue.
	Bit shifting:
		- BB >> 0   (0x000000BB)
		- GG >> 8   (0x0000GG00)
		- RR >> 16  (0x00RR0000)
		- AA >> 24  (0xAA000000)

static void	set_pixel_color(t_fractol *f, int x, int y, int color)
{
		f->buf[x * 4 + y * WIDTH * 4] = color;
		f->buf[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
		f->buf[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
		f->buf[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}
*/
