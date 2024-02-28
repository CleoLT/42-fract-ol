/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:37:30 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/28 14:16:13 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"

int	key_event(int key_code, t_fractol *f)
{
	if (key_code == ESC_KEY)
		exit(0);
	if (key_code == 1) //esto no es nada, areemplazar
		clean_exit(f);
	printf("paso x key event");
	printf(" key event %d\n", f->iteration);
	return (0);
}

int	mouse_event(int key_code, int x, int y, t_fractol *f)
{
	printf("holi paso x mouse event\n");
//	printf(" mouse event %d\n", f->iteration);
	if (key_code == ON_MOUSEDOWN)//4
		f->zoom *= 1.1;
	if (key_code == ON_MOUSEUP)//5
		f->zoom *= 0.9;
	printf("%f\n", f->zoom);
	render(f);
	x=0;
	y=0;
	return (0);
}

void	init_events(t_fractol *f)
{
	mlx_hook(f->win, ON_DESTROY, 0, ft_exit, f);
	mlx_key_hook(f->win, key_event, f);
	mlx_mouse_hook(f->win, mouse_event, f);
}


