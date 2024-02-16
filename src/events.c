/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:37:30 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/16 18:47:26 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fract-ol.h"

int	key_event(int key_code, t_fractol *f)
{
	if (key_code == 53)
		clean_exit(f);
	return (0);
}

void	init_events(t_fractol *f)
{
	mlx_hook(f->win, 17, 0, clean_exit, f);
	mlx_key_hook(f->win, key_event, f);
}
