/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:33:26 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/22 17:41:07 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fract-ol.h"
#include <unistd.h>

void	help_msg(void)
{
	ft_printf("\n================== Fract-ol ==================\n\n");
	ft_printf("You must type:\n\n\n");
	ft_printf("\t./fract-ol mandelbrot\n");
	ft_printf("\t./fract-ol julia\n\n\n\n");
	exit(1);
}

void	handle_arg(t_fractol *f, char **argv)
{	
	int	i;

	i = -1;
	while(argv[1][++i])
		argv[1][i] = ft_tolower(argv[1][i]);
//	ft_printf("%s", argv[1]);
	f->type = 0;
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
		f->type = 1;
	if (!ft_strncmp(argv[1], "julia", 6))
		f->type = 2;
	if (!f->type)
		help_msg();
}

void	init(t_fractol *f)
{
	f->conn = mlx_init();
	if (!f->conn)
		clean_error("Error connecting to mlx", f, 1);
	f->win = mlx_new_window(f->conn, WIDTH, HEIGHT, "Fract-ol");
	if (!f->win)
		clean_error("Error creating window", f, 1);
	f->img = mlx_new_image(f->conn, WIDTH, HEIGHT);
	if (!f->img)
		clean_error("Error creating img", f, 1);
	f->img_addr = mlx_get_data_addr(f->img, &f->img_bpp, &f->img_line, &f->img_endian);

	{
		printf("line : %d, bpp : %d\n", f->img_line, f->img_bpp);
	}

//	if(!f->img_addr)
//		clean_error("Error image address", f, 1);
	

}


int	main(int argc, char **argv)
{
	t_fractol	fract;
 
	if (argc != 2)
		help_msg();
	handle_arg(&fract, argv);
	init(&fract);
	init_events(&fract);
	render(&fract);
	mlx_loop(fract.conn);
	return (0);
}

