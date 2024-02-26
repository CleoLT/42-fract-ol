/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:33:26 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/25 16:26:28 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"
#include <unistd.h>

void	help_msg(void)
{
	ft_printf("\n================== Fractol ==================\n\n");
	ft_printf("You must type:\n\n\n");
	ft_printf("\t./fract-ol mandelbrot\n");
	ft_printf("\t./fract-ol julia <param1> <param2>\n");
	ft_printf("\t./fract-ol julia 0.285 0.013\n");
	ft_printf("\t./fract-ol julia -0.4 0.6\n");
	ft_printf("\t./fract-ol julia -0.8 0.156\n\n\n\n");
	exit(1);
}

void	handle_arg(t_fractol *f, char **argv)
{
	int	i;

	i = -1;
	while (argv[1][++i])
		argv[1][i] = ft_tolower(argv[1][i]);
	f->type = 0;
	if (!ft_strncmp(argv[1], "mandelbrot", 11))
		f->type = MANDELBROT;
	if (!ft_strncmp(argv[1], "julia", 6))
		f->type = JULIA;
	if (!ft_strncmp(argv[1], "burningship", 12))
		f->type = BURNINGSHIP;
	if (!ft_strncmp(argv[1], "mandelreverse", 14))
		f->type = MANDELREVERSE;
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
	f->img_addr = mlx_get_data_addr(f->img, &f->img_bpp, &f->img_line, \
			&f->img_endian);
	printf("line : %d, bpp : %d\n", f->img_line, f->img_bpp);
//	if(!f->img_addr)
//		clean_error("Error image address", f, 1);
}

static void	init_julia_c(t_fractol *f, char **argv)
{
	f->julia_c.x = -0.374004139;
	f->julia_c.y = 0.659792175;
	if (!argv[2])
		return ;
//	if (ft_atod(argv[2]))
//		f->julia_c.x = ft_atod(argv[2]); 
//	printf("%f\n", f->julia_c.x);
//	printf("%f\n", DBL_MAX);
}

int	main(int argc, char **argv)
{
	t_fractol	fract;

	if (argc < 2 || argc > 4 || argc == 3)
		help_msg();
	handle_arg(&fract, argv);
	if (fract.type == JULIA)
		init_julia_c(&fract, argv);

	

	if (argv[2])
	{
		fract.julia_c.x = ft_atod(argv[2]); 
		printf("holi%f\n", fract.julia_c.x);
	
	}

	init(&fract);
	init_events(&fract);
	render(&fract);
	mlx_loop(fract.conn);
	return (0);
}
