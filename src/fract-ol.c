/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:33:26 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/14 19:47:19 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fract-ol.h"
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int deal_key()
{
	ft_putchar('x');
	return (0);
}


int	main(int argc, char **argv)
{
//	t_fractol	*fract;

	argv[1] = "hola";
	if (argc != 2)
	{
		ft_printf("usa estos parametros ejemplos");
	//	get_next_line(0);
		exit(0);
	}
	
	
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx test");
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}

