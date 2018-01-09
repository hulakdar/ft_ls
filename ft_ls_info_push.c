/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_info_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <skamoza@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 21:24:50 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/09 01:22:39 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_info_push(t_vector *vect, char *file_path, char *file_name)
{
	t_file_info		info;

	info = ft_ls_construct_info(file_path, file_name);
	ft_vec_pushback(vect, &info);
}
