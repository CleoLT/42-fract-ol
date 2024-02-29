/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:33:26 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/29 15:37:59 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"

static void	handle_arg(t_fractol *f, char **argv)
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

static void	init_mlx(t_fractol *f)
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
}

static void	init_julia_c(t_fractol *f, char **argv)
{
	f->julia_c.x = -0.374004139;
	f->julia_c.y = 0.659792175;
	if (!argv[2] || !argv[3])
		return ;
	if (handle_julia_arg(argv[2]) || handle_julia_arg(argv[3]))
		help_msg();
	f->julia_c.x = ft_atod(argv[2]);
	f->julia_c.y = ft_atod(argv[3]);
	if (f->julia_c.x > 2 || f->julia_c.x < -2 || f->julia_c.y > 2 \
			|| f->julia_c.y < -2)
		help_msg();
}

static void	data_init(t_fractol *f)
{
	f->iter = 50;
	f->zoom = 1;
	f->shift.x = 0;
	f->shift.y = 0;
}

int	main(int argc, char **argv)
{
	t_fractol	fract;

	if (argc < 2 || argc > 4 || argc == 3)
		help_msg();
	handle_arg(&fract, argv);
	if (fract.type == JULIA)
		init_julia_c(&fract, argv);
	data_init(&fract);
	init_mlx(&fract);
	init_events(&fract);
	render(&fract);
	mlx_loop(fract.conn);
	return (0);
}
