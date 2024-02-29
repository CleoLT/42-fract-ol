/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:18:42 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/29 15:25:32 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"

void	help_msg(void)
{
	ft_printf("\n================== Fractol ==================\n\n");
	ft_printf("You must type:\n\n\n");
	ft_printf("\t./fract-ol mandelbrot\n");
	ft_printf("\t./fract-ol mandelreverse\n");
	ft_printf("\t./fract-ol burningship\n");
	ft_printf("\t./fract-ol julia\n");
	ft_printf("\t./fract-ol julia <param1> <param2>\n");
	ft_printf("\t./fract-ol julia 0.285 0.013\n");
	ft_printf("\t./fract-ol julia -0.4 0.6\n");
	ft_printf("\t./fract-ol julia -0.8 0.156\n\n");
	ft_printf("\tJulia's <param> must be between -2 and 2.\n\n\n\n\n\n");
	exit(1);
}

int	ft_exit(void)
{
	exit(0);
	return (0);
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

int	handle_julia_arg(char *arg)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	while (arg[i] && ft_isspace(arg[i]))
		i++;
	if ((arg[i] && arg[i] == '+') || (arg[i] && arg[i] == '-'))
		i++;
	while (arg[i])
	{
		if (arg[i] == '.')
		{
			point++;
			i++;
			if (point > 1)
				return (1);
		}
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	if (!ft_isdigit(arg[i - 1]))
		return (1);
	return (0);
}
