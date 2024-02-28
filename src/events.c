/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:37:30 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/28 16:24:01 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"

int	key_event(int key_code, t_fractol *f)
{
	if (key_code == ESC_KEY)
		exit(0);
	if (key_code == PLUS_KEY)
		f->iteration += 10;
	if (key_code == MINUS_KEY)
		f->iteration -= 10;
	if (key_code == LEFT_KEY)
		f->shift.x -= 0.5 * f->zoom;
	if (key_code == RIGHT_KEY)
		f->shift.x += 0.5 * f->zoom;
	if (key_code == UP_KEY)
		f->shift.y -= 0.5 * f->zoom;
	if (key_code == DOWN_KEY)
		f->shift.y += 0.5 * f->zoom;
	render(f);
	return (0);
}

int	mouse_event(int mouse_code, int x, int y, t_fractol *f)
{
	printf("holi paso x mouse event\n");
	if (mouse_code == ON_MOUSEDOWN)//4
		f->zoom *= 1.1;
	if (mouse_code == ON_MOUSEUP)//5
		f->zoom *= 0.9;
	printf("x : %d\n", x);
	printf("y : %d\n\n", y);
	render(f);
//	x=0;
//	y=0;
	return (0);
}

void	init_events(t_fractol *f)
{
	mlx_hook(f->win, ON_DESTROY, 0, ft_exit, f);
	mlx_key_hook(f->win, key_event, f);
	mlx_mouse_hook(f->win, mouse_event, f);
//	mlx_hook(f->win, ON_MOUSEUP, 0, mouse_event, f);
}


