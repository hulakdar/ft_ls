/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_print_not_dir.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:42:09 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/11 20:20:04 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_print_not_dir(t_vector vect,
							t_flags flags,
							void *(*ft_vec_pop)(t_vector *))
{
	t_file_info *tmp;

	while ((tmp = (t_file_info *)ft_vec_pop(&vect)))
	{
		if (!S_ISDIR(tmp->stat.st_mode))
		{
			if (flags.list || flags.l_group)
				ft_putinfo(*tmp, flags);
			else
				ft_puttab(tmp->file_name);
		}
	}
	ft_putendl("");
}
