/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_total.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <skamoza@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 21:07:21 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/09 21:34:17 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_put_total(t_vector	vect, void *(*ft_vec_pop)(t_vector *))
{
	t_file_info *tmp;
	size_t		total;

	total = 0;
	while ((tmp = (t_file_info *)ft_vec_pop(&vect)))
		total += tmp->stat.st_blocks >> 1;
	ft_putstr("total ");
	ft_put_size_t(total);
	ft_putendl("");
}
