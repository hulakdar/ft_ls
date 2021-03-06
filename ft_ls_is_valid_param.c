/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_is_valid_param.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:51:18 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/10 10:00:46 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_is_valid_param(char *dir_name)
{
	t_file_info	info;

	if (lstat(dir_name, &info.stat) == -1)
		return (0);
	return (1);
}
