/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_is_valid_param.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:51:18 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/08 16:06:20 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_is_valid_param(char *dir_name)
{
	DIR				*dir;

	if (!(dir = opendir(dir_name)))
		return (0);
	closedir(dir);
	return (1);
}
