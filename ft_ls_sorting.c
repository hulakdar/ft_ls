/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:55:55 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/08 18:44:27 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_sorting(t_vector vect, t_flags *flags)
{
	if (!flags->no_sort)
		return ;
	ft_sort(vect.array, vect.array + vect.back * vect.size, vect.size,
		(int (*)())strcmp);
}
