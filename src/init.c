/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:06:14 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/27 13:12:17 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"

void	init_offset_win(t_offset *height, t_offset *width)
{
	height->old_min = 0;
	height->old_max = HEIGHT;
	height->new_min = -2;
	height->new_max = 2;
	width->old_min = 0;
	width->old_max = WIDTH;
	width->new_min = -2;
	width->new_max = 2;
}

void	data_init(t_fractol *f)
{
	f->iteration = 100;
	f->zoom = 1;






}
