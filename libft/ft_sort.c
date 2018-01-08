/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:56:27 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/08 17:35:13 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort(void *begin, void *end, size_t size, int (*f)(void *, void *))
{
	int		swaps;
	void	*seeker;
	void	*tmp;

	swaps = 1;
	tmp = ft_memalloc(size);
	while (swaps)
	{
		swaps = 0;
		seeker = begin;
		while (seeker < end - size)
		{
			if (f(seeker, seeker + size) > 0)
			{
				ft_memmove(tmp, seeker, size);
				ft_memmove(seeker, seeker + size, size);
				ft_memmove(seeker + size, tmp, size);
				swaps++;
			}
			seeker += size;
		}
		end -= size;
	}
	free(tmp);
}
