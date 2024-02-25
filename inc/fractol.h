/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:28:10 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/25 15:17:26 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include <math.h>
# include <stdio.h>
# include <float.h>

# define WIDTH	900
# define HEIGHT	900
# define MANDELBROT 1
# define JULIA 2

# define BLACK       0x000000
# define WHITE       0xFFFFFF
# define YELLOW      0xCCFF00  // A blinding lime

/*
typedef struct s_img
{
	void	*img_ptr;
	char	*img_addr;
	int		*bits_per_pixel;
	int		*size_line;
	int		*endian;
}
*/
typedef struct s_offset
{
	int	old_min;
	int	old_max;
	int	new_min;
	int	new_max;
}	t_offset;

typedef struct s_number
{
	double	x;
	double	y;
}	t_number;

typedef struct s_fractol
{
	int			type;
	void		*conn;
	void		*win;
	void		*img;
	char		*img_addr;
	int			img_bpp;
	int			img_line;
	int			img_endian;
	int			iteration;
	t_number	julia_c;

}	t_fractol;

void	clean_error(char *error, t_fractol *fract, int code_exit);
int		clean_exit(t_fractol *f);

void	init_events(t_fractol *f);
void	render(t_fractol *f);

t_number	fractal_equation(t_fractol *f, t_number c, t_number z);

int		ft_exit(void);

#endif
