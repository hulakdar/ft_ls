/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <skamoza@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:30:33 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/09 20:41:20 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_recursive(t_vector vect, t_flags flags,
					void *(*ft_vec_pop)(t_vector *))
{
	t_file_info		*tmp;

	while ((tmp = (t_file_info *)ft_vec_pop(&vect)))
	{
		if (ft_strcmp(tmp->file_name, ".") && ft_strcmp(tmp->file_name, "..")
				&& S_ISDIR(tmp->stat.st_mode))
			ft_list_dir(ft_ls_construct_info(tmp->file_path, tmp->file_name),
												flags, 0, ft_vec_pop);
	}
	return (0);
}

int		ft_list_dir(t_file_info info, t_flags flags, int first,
					void *(*ft_vec_pop)(t_vector *))
{
	struct dirent	*dirent;
	DIR				*dir;
	t_vector		vect;

	if (!(dir = opendir(info.file_path)))
		return (0);
	if (!first)
		ft_putendl("");
	if (!flags.one && ft_strcmp(info.file_path, "."))
	{
		ft_putstr(info.file_path);
		ft_putendl(":");
	}
	ft_vectorinit(&vect, sizeof(t_file_info), 32);
	while ((dirent = readdir(dir)))
		if (ft_strncmp(dirent->d_name, ".", 1) || flags.all)
			ft_ls_info_push(&vect, info.file_path, dirent->d_name);
	closedir(dir);
	ft_ls_sorting(vect, flags);
	ft_ls_print_current(vect, flags, ft_vec_pop);
	if (flags.recursive)
		ft_ls_recursive(vect, flags, ft_vec_pop);
	ft_ls_destruct(&vect);
	free(info.file_path);
	return (0);
}

int		ft_ls_param_handle(t_flags *flags, char *param)
{
	while (*(++param))
	{
		if (ft_strnequ(param, "R", 1))
			flags->recursive = 1;
		else if (ft_strnequ(param, "r", 1))
			flags->reverse = 1;
		else if (ft_strnequ(param, "t", 1))
			flags->time_sort = 1;
		else if (ft_strnequ(param, "f", 1))
			flags->no_sort = 1;
		else if (ft_strnequ(param, "a", 1))
			flags->all = 1;
		else if (ft_strnequ(param, "u", 1))
			flags->time_access = 1;
		else if (ft_strnequ(param, "l", 1))
			flags->list = 1;
		else if (ft_strnequ(param, "g", 1))
			flags->l_group = 1;
		else if (ft_strnequ(param, "-", 1))
			return (0);
		else
			ft_ls_error("illegal option -- ", param);
	}
	return (1);
}

void	ft_ls_print(t_vector vect, t_flags flags,
				void *(*ft_vec_pop)(t_vector *))
{
	t_file_info		*tmp;
	int				first;

	first = 1;
	if (!vect.back)
	{
		if (!flags.recursive)
			flags.one = 1;
		ft_list_dir(ft_ls_construct_info("", "."), flags, first, ft_vec_pop);
	}
	else
		while ((tmp = (t_file_info *)ft_vec_pop(&vect)))
		{
			ft_list_dir(*tmp, flags, first, ft_vec_pop);
			first = 0;
		}
}

int		main(int argc, char **argv)
{
	t_flags			flags;
	t_vector		vect;
	int				i;

	ft_bzero(&flags, sizeof(t_flags));
	i = 1;
	while (i < argc && *argv[i] == '-' && ft_ls_param_handle(&flags, argv[i++]))
		continue ;
	ft_vectorinit(&vect, sizeof(t_file_info), 32);
	while (i < argc)
	{
		if (ft_ls_is_valid_param(argv[i]))
			ft_ls_info_push(&vect, argv[i], argv[i]);
		else
			ft_ls_error_manager("No such file or directory: ", argv[i], 0);
		i++;
	}
	ft_vectordel(&vect);
	ft_ls_print(vect, flags, flags.reverse ? ft_vec_popback : ft_vec_popfront);
	//system("leaks ft_ls");
	return 0;
}
