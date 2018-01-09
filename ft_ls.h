/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:15:28 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/09 20:41:19 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/includes/libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# define ANSI_RED "\033[1;31m"
# define ANSI_GREEN "\033[36m"
# define ANSI_PINK "\033[35m"
# define ANSI_RESET "\033[0m"
typedef	struct stat	t_stat;
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
typedef struct	s_file_info
{
	t_stat		stat;
	char		*file_name;
	char		*file_path;
}				t_file_info;

void			ft_ls_error(char *error, char *param);
int				ft_ls_error_manager(char *error, char *vec, size_t size);
void			ft_ls_usage(void);
int				ft_list_dir(t_file_info info, t_flags flags, int first,
											void *(*ft_vec_pop)(t_vector *));
int				ft_ls_is_valid_param(char *param);
void			ft_ls_sorting(t_vector vect, t_flags flags);
void			ft_ls_print_current(t_vector vect, t_flags flags,
											void *(*ft_vec_pop)(t_vector *));
t_file_info		ft_ls_construct_info(char *file_path, char *file_name);
void			ft_ls_info_push(t_vector *vect, char *file_path,
												char *file_name);
void			ft_ls_destruct(t_vector *vect);
#endif
