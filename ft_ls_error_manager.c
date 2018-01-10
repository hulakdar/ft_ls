/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_error_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:10:16 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/10 10:07:02 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_error(char *message, char *spec)
{
	ft_putstr_fd("./ft_ls: ", 2);
	ft_putstr_fd(message, 2);
	ft_putchar_fd(*spec, 2);
	ft_putendl("");
	exit(1);
}

int		ft_ls_error_manager(char *message, char *spec)
{
	ft_putstr_fd("./ft_ls:", 2);
	ft_putstr_fd(message, 2);
	if (spec)
		ft_putendl_fd(spec, 2);
	return (0);
}
