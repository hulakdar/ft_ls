/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_print_current.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 18:44:19 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/08 18:53:25 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_print_current(t_vector vect, t_flags flags)
{
	char **tmp;
	if (!flags.list)
	{
		if (flags.reverse)
			while ((tmp = (char **)ft_vectorpopback(&vect)))
				ft_puttab(*tmp);
		else
			while ((tmp = (char **)ft_vectorpopfront(&vect)))
				ft_puttab(*tmp);
	}
	/*
	else
		ft_list_the_vect(vect, flags);
		*/
}
