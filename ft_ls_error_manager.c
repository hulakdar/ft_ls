/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_error_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:10:16 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/08 18:40:49 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_ls_error_manager(char *message, char *spec, size_t size)
{
	ft_putstr_fd("./ft_ls:", 2);
	ft_putstr_fd(message, 2);
	if (spec)
		ft_putendl_fd(spec, 2);
	else
		ft_putchar_fd((char)size, 2);
	return (0);
}
