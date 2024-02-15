/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:33:26 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/15 13:24:10 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fract-ol.h"
#include <unistd.h>

void	help_msg(void)
{
	ft_printf("================== Fract-ol ==================\n\n");
	ft_printf("You must type:\n");
	ft_printf("\t./fract-ol mandelbrot\n");
	ft_printf("\t./fract-ol julia\n");
}

void	init(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		clean_exit("Error connecting to mlx", f);
	f->win = mlx_new_window(f->mlx, 500, 500, "Fract-ol");
	if (!f->win)
		clean_exit("Error creating window", f);
	mlx_loop(f->mlx);
}


int	main(int argc, char **argv)
{
	t_fractol	fract;

	argv[1] = "hola";
	if (argc < 2)
	{
		help_msg();
		exit(EXIT_FAILURE);
	}
	init(&fract);
	
//	void *mlx_ptr;
//	void *win_ptr;

//	mlx_ptr = mlx_init();
//	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx test");
//	mlx_key_hook(win_ptr, deal_key, (void *)0);
//	mlx_loop(mlx_ptr);
	return (0);
}

