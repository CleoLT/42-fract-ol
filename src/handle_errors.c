/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:18:42 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/15 12:45:27 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fract-ol.h"

void 	print_error(char *error)
{
	if (error[0] != '\0')
		ft_printf("%s\n", error);
}

void	clean_exit(char *error, t_fractol *f)
{
	if (!f)
	{
		print_error("f don't exist");
		exit(1);
	}
	if (f->win)
	{
		print_error(error);
		mlx_destroy_window(f->mlx, f->win);
		exit(1);
	}

}
