/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectorpopfront.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:10:00 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/08 16:22:18 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_vectorpopfront(t_vector *vect)
{
	if (vect->front == vect->back)
		return (NULL);
	return (ft_vectorget(vect, vect->front++));
}
