/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:37:30 by ale-tron          #+#    #+#             */
/*   Updated: 2024/03/01 12:42:24 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"

static int	key_event(int key_code, t_fractol *f)
{
	if (key_code == ESC_KEY)
		exit(0);
	if (key_code == PLUS_KEY)
		f->iter += 9;
	if (key_code == MINUS_KEY)
		f->iter -= 9;
	if (key_code == LEFT_KEY)
		f->shift.x -= 0.5 * f->zoom;
	if (key_code == RIGHT_KEY)
		f->shift.x += 0.5 * f->zoom;
	if (key_code == UP_KEY)
		f->shift.y -= 0.5 * f->zoom;
	if (key_code == DOWN_KEY)
		f->shift.y += 0.5 * f->zoom;
	if (key_code == R_KEY)
		f->r *= 2;
	if (key_code == G_KEY)
		f->g *= 2;
	if (key_code == B_KEY)
		f->b *= 2;
	render(f);
	return (0);
}

static int	mouse_event(int mouse_code, int x, int y, t_fractol *f)
{
	double	p_x;
	double	p_y;
	double	zoom_factor;

	if (mouse_code == ON_MOUSEDOWN)
		f->zoom *= 1.1;
	if (mouse_code == ON_MOUSEUP)
	{
		p_x = ((double)x * 4 / WIDTH - 2) * f->zoom + f->shift.x;
		p_y = ((double)y * 4 / HEIGHT - 2) * f->zoom + f->shift.y;
		zoom_factor = 0.9;
		f->shift.x += (p_x) * (1 - zoom_factor);
		f->shift.y += (p_y - f->shift.y) * (1 - zoom_factor);
		f->zoom *= zoom_factor;
	}
	render(f);
	x = 0;
	y = 0;
	return (0);
}

void	init_events(t_fractol *f)
{
	mlx_hook(f->win, ON_DESTROY, 0, ft_exit, f);
	mlx_key_hook(f->win, key_event, f);
	mlx_mouse_hook(f->win, mouse_event, f);
}
