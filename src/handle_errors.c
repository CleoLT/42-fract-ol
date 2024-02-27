/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:18:42 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/27 12:48:08 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"

void	print_error(char *error)
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

int	ft_exit(void)
{
	exit(0);
	return (0);
}
