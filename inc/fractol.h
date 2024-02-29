/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:28:10 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/29 17:58:31 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H

# include "macros.h"
# include "../mlx/mlx.h"
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include <math.h>
# include <stdio.h>

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
	int			iter;
	double		zoom;
	int			r;
	int			g;
	int			b;
	t_number	julia_c;
	t_number	shift;
}	t_fractol;

void		help_msg(void);
void		clean_error(char *error, t_fractol *fract, int code_exit);
int			ft_exit(void);
int			handle_julia_arg(char *arg);

void		init_events(t_fractol *f);

void		render(t_fractol *f);

int			fractal_equation(t_fractol *f, double c_x, double c_y);

double		ft_atod(char *str);
int			ft_isspace(int c);

#endif
