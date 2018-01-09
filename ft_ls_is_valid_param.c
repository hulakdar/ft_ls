/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_is_valid_param.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:51:18 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/09 01:22:41 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_is_valid_param(char *dir_name)
{
	int fd;

	if (!(fd = open(dir_name, O_RDONLY)))
		return (0);
	close(fd);
	return (1);
}
