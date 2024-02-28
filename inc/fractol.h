/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:28:10 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/28 16:04:10 by ale-tron         ###   ########.fr       */
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
	double		zoom;
	t_number	julia_c;
	t_number	shift;

}	t_fractol;

void		clean_error(char *error, t_fractol *fract, int code_exit);
int			clean_exit(t_fractol *f);
int			handle_julia_arg(char *arg);

void		init_offset_win(t_offset *height, t_offset *width);
void		data_init(t_fractol *f);
void		init_events(t_fractol *f);
void		render(t_fractol *f);

t_number	fractal_equation(t_fractol *f, t_number c, t_number z);

double		ft_atod(char *str);
int			ft_isspace(int c);

int			ft_exit(void);

#endif
