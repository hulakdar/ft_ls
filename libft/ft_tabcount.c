/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:51:44 by skamoza           #+#    #+#             */
/*   Updated: 2017/12/05 12:22:32 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_tabcount(char **tab)
{
	int cunt;

	cunt = 0;
	while (tab[cunt])
		cunt++;
	return (cunt);
}
