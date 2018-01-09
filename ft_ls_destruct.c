/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_destruct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:25:54 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/09 19:28:11 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_destruct(t_vector *vect)
{
	t_file_info *tmp;

	while ((tmp = (t_file_info *)ft_vec_popback(vect)))
		free(tmp->file_path);
	ft_vectordel(vect);
}
