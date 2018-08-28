/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 22:16:02 by istalevs          #+#    #+#             */
/*   Updated: 2018/05/07 23:08:43 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "mlx.h"

typedef struct		s_image
{
	int				i_width;
	int				i_height;
	void			*image;
	char			*ptr;
	int				bpp;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_color
{
	int				red;
	int				green;
	int				blue;
}					t_color;

typedef struct		s_fract
{
	double			new_re;
	double			new_im;
	double			old_re;
	double			old_im;
	double			pr;
	double			pi;
	int				is_inside;
	int				i;
	double			max_iterations;
	double			yy;
	double			xx;
	t_color			*color;
}					t_fract;

typedef struct		s_mouse
{
	double			x;
	double			y;
	double			lastx;
	double			lasty;
	int				isdown;
	double			mov_x;
	double			mov_y;
	double			zoom;
}					t_mouse;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*win_name;
	int				w_width;
	int				w_height;
	t_image			*img;
	t_fract			*fractal;
	t_mouse			*mouse;
	int				color;
	double			index;
	int				tab_mod;
}					t_mlx;

void				sf_render(t_mlx *mlx);
void				sf_draw(t_mlx *mlx,
							void (*set_fractal)(t_mlx*, t_fract*, int, int),
							void (*fractol)(t_fract*),
							void (*drawing)(t_mlx*, t_fract*, int, int));
void				sf_drawing_one(t_mlx *mlx, t_fract *f, int x, int y);
void				sf_drawing_thecond(t_mlx *mlx, t_fract *f, int x, int y);
void				sf_drawing_third(t_mlx *mlx, t_fract *f, int x, int y);
void				sf_draw_interface(t_mlx *mlx);
double				sf_d_abs(double temp);
t_fract				*sf_new_fract(void);
t_mouse				*sf_new_mouse(t_mlx *mlx);
t_image				*sf_new_image(t_mlx *mlx);
t_mlx				*sf_new_mlx(char *name, int n);
void				sf_set_pixel(t_image *img, int x, int y, int color);
int					sf_set_color(int *red, int *green, int *blue);
int					sf_set_mouse(t_mouse *m);
void				sf_set_mandelbrot(t_mlx *mlx, t_fract *f, int x, int y);
void				sf_set_julia(t_mlx *mlx, t_fract *f, int x, int y);
void				sf_set_burning(t_mlx *mlx, t_fract *f, int x, int y);
int					exit_x(void);
int					hook_keydown(int key, t_mlx *mlx);
int					hook_mousedown(int button, int x, int y, t_mlx *mlx);
int					hook_mouseup(int button, int x, int y, t_mlx *mlx);
int					hook_mousemove(int x, int y, t_mlx *mlx);
void				sf_draw_rgb(t_mlx *mlx);
void				sf_draw_interface(t_mlx *mlx);
void				sf_mandelbrot(t_fract *f);
void				sf_julia(t_fract *f);
void				sf_burning(t_fract *f);
void				sf_tricorn(t_fract *f);
void				sf_holes(t_fract *f);
int					sf_fractal_color(t_fract *f, int color_1, int color_2);

#endif
