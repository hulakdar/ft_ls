/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:15:28 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/07 21:42:15 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/includes/libft.h"
# include <dirent.h>
typedef struct	s_flags
{
	unsigned	recursive : 1;
	unsigned	time_sort : 1;
	unsigned	time_access : 1;
	unsigned	no_sort : 1;
	unsigned	reverse : 1;
	unsigned	all : 1;
	unsigned	one : 1;
	unsigned	list : 1;
	unsigned	l_group : 1;
}				t_flags;

void			ft_ls_error(char *error, t_vector *vec);
void			ft_ls_usage(void);
int				ft_list_dir(char *dir_name, t_flags *flags);
#endif
