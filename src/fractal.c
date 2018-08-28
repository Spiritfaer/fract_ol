/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 20:43:50 by istalevs          #+#    #+#             */
/*   Updated: 2018/05/07 21:51:28 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void		sf_mandelbrot(t_fract *f)
{
	while (f->i < f->max_iterations)
	{
		f->old_re = f->new_re + f->xx;
		f->old_im = f->new_im + f->yy;
		f->new_re = f->old_re * f->old_re - f->old_im * f->old_im + f->pr;
		f->new_im = 2 * f->old_re * f->old_im + f->pi;
		f->is_inside = 1;
		if ((f->new_re * f->new_re + f->new_im * f->new_im) > 5)
		{
			f->is_inside = 0;
			break ;
		}
		f->i++;
	}
}

void		sf_julia(t_fract *f)
{
	while (f->i < f->max_iterations)
	{
		f->old_re = f->new_re + f->xx;
		f->old_im = f->new_im + f->yy;
		f->new_re = f->old_re * f->old_re - f->old_im * f->old_im + f->pr;
		f->new_im = 2 * f->old_re * f->old_im + f->pi;
		f->is_inside = 1;
		if ((f->new_re * f->new_re + f->new_im * f->new_im) > 5)
		{
			f->is_inside = 0;
			break ;
		}
		f->i++;
	}
}

void		sf_burning(t_fract *f)
{
	while (f->i < f->max_iterations)
	{
		f->old_re = f->new_re + f->xx;
		f->old_im = f->new_im + f->yy;
		f->new_re = f->old_re * f->old_re - f->old_im * f->old_im + f->pr;
		f->new_im = sf_d_abs(2 * f->old_re * f->old_im) + f->pi;
		f->new_re = sf_d_abs(f->new_re);
		f->is_inside = 1;
		if ((f->new_re * f->new_re + f->new_im * f->new_im) > 5)
		{
			f->is_inside = 0;
			break ;
		}
		f->i++;
	}
}

void		sf_tricorn(t_fract *f)
{
	while (f->i < f->max_iterations)
	{
		f->old_re = f->new_re + f->xx;
		f->old_im = f->new_im + f->yy;
		f->new_re = f->old_re * f->old_re - f->old_im * f->old_im + f->pr;
		f->new_im = -2 * f->old_re * f->old_im + f->pi;
		f->is_inside = 1;
		if ((f->new_re * f->new_re + f->new_im * f->new_im) > 5)
		{
			f->is_inside = 0;
			break ;
		}
		f->i++;
	}
}

void		sf_holes(t_fract *f)
{
	while (f->i < f->max_iterations)
	{
		f->old_re = tan(f->new_re) - f->pr + f->xx;
		f->old_im = cos(f->new_im) + f->pi + f->yy;
		f->new_re = f->old_re * f->old_re
					- sf_d_abs(f->old_im * f->old_im) + f->pr;
		f->new_im = tan(2 * f->old_re) * f->old_im + f->pi;
		f->is_inside = 1;
		if ((f->new_re * f->new_re + f->new_im * f->new_im) > 20)
		{
			f->is_inside = 0;
			break ;
		}
		f->i++;
	}
}
