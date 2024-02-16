/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:18:42 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/16 18:14:49 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fract-ol.h"

void 	print_error(char *error)
{
	if (error[0] != '\0')
		ft_printf("%s\n", error);
}

void	clean_error(char *error, t_fractol *f, int code_exit)
{
	perror(error);
	if (!f)
		exit(1);
	if (f->img)
		mlx_destroy_image(f->conn, f->img);
	if (f->win)
		mlx_destroy_window(f->conn, f->win);
	if (f->conn)
		free(f->conn);
	exit(code_exit);
}

int	clean_exit(t_fractol *f)
{
	clean_error("", f, 0);
//	if (f->img)
//		mlx_destroy_image(f->conn, f->img);
//	if (f->win)
//		mlx_destroy_window(f->conn, f->win);
//	if (f->conn)
//		free(f->conn);
//	exit(0);
	return (0);
}
