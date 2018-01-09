/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:55:55 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/09 19:02:03 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_sort_by_alpha(t_file_info *one, t_file_info *two)
{
	return (ft_strcmp(one->file_name, two->file_name));
}

int		ft_ls_sort_access(t_file_info *one, t_file_info *two)
{
	return (one->stat.st_atime - two->stat.st_atime);
}

int		ft_ls_sort_mod(t_file_info *one, t_file_info *two)
{
	return (one->stat.st_mtime - two->stat.st_mtime);
}

void	ft_ls_sorting(t_vector vec, t_flags flags)
{
	if (flags.no_sort)
		return ;
	ft_sort(vec.array, vec.array + vec.back * vec.size, vec.size,
			(int (*)(void *, void *))ft_ls_sort_by_alpha);
	if (flags.time_sort)
		ft_sort(vec.array, vec.array + vec.back * vec.size, vec.size,
		(int (*)(void *, void *))(flags.time_access ?
		ft_ls_sort_access : ft_ls_sort_mod));
}
