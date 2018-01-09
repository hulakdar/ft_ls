/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_construct_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <skamoza@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 21:36:15 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/09 20:09:12 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file_info	ft_ls_construct_info(char *file_path, char *file_name)
{
	t_file_info	info;
	char		*half;
	char		*whole;

	if (*file_path)
	{
		half = ft_strjoin(file_path, "/");
		whole = ft_strjoin(half, file_name);
		free(half);
		info.file_path = whole;
	}
	else
		info.file_path = ft_strdup(file_name);
	info.file_name = file_name;
	if (lstat(info.file_path, &info.stat) == -1)
	{
		ft_bzero(&info, sizeof(t_file_info));
		free(whole);
	}
	return (info);
}
