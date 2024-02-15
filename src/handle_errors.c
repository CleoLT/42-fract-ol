/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:18:42 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/15 18:39:56 by ale-tron         ###   ########.fr       */
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
	perror(error);
	if (!f)
		exit(1);
	if (f->img_addr)
		free(f->img_addr);
	if (f->img)
		mlx_destroy_image(f->conn, f->img);
	if (f->win)
	{
	//	print_error(error);
		mlx_destroy_window(f->conn, f->win);
	}
	if (f->conn)
		free(f->conn);
	
	exit(1);
}
