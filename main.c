/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <skamoza@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:30:33 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/08 18:51:10 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_recursive(char *dir_name, t_flags *flags)
{
	char *half;
	char *whole;
	struct dirent	*dirent;
	DIR				*dir;

	if (ft_strequ(dir_name, ".") || ft_strequ(dir_name, "..") ||
			!(dir = opendir(dir_name)))
		return (1);
	while ((dirent = readdir(dir)))
		if (ft_strcmp(dirent->d_name, ".") || ft_strcmp(dirent->d_name, ".."))
		{
			half = ft_strjoin(dir_name, "/");
			whole = ft_strjoin(half, dirent->d_name);
			free(half);
			ft_list_dir(whole, flags, 0);
			free(whole);
		}
	closedir(dir);
	return (0);
}

int		ft_list_dir(char *dir_name, t_flags *flags, int first)
{
	struct dirent	*dirent;
	DIR				*dir;
	t_vector		vect;

	if (!(dir = opendir(dir_name)))
		return (0);
	if (!first)
		ft_putendl("");
	if (!flags->one)
	{
		ft_putstr(dir_name);
		ft_putendl(":");
	}
	ft_vectorinit(&vect, sizeof(char *), 32);
	while ((dirent = readdir(dir)))
		if (ft_strncmp(dirent->d_name, ".", 1) || flags->all)
			ft_vectorpushback(&vect, &dirent->d_name);
	closedir(dir);
	ft_ls_sorting(vect, flags);
	ft_ls_print_current(vect, *flags);
	if (flags->recursive)
		ft_ls_recursive(dir_name, flags);
	return (0);
}

int		ft_ls_param_handler(t_flags *flags, char *param)
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
			return (ft_ls_error_manager("illegal option -- ", param, 1));
	}
	return (1);
}

void	ft_ls_print(t_vector vect, t_flags flags)
{
	char	**tmp;
	int		first;

	first = 1;
	if (!vect.back)
	{
		if (!flags.recursive)
			flags.one = 1;
		ft_list_dir(".", &flags, first);
	}
	else
	{
		if (flags.reverse)
			while ((tmp = (char **)ft_vectorpopback(&vect)))
			{
				ft_list_dir(*tmp, &flags, first);
				first = 0;
			}
		else
			while ((tmp = (char **)ft_vectorpopfront(&vect)))
			{
				ft_list_dir(*tmp, &flags, first);
				first = 0;
			}
	}
}

int		main(int argc, char **argv)
{
	t_flags			flags;
	t_vector		vect;
	int				i;

	ft_bzero(&flags, sizeof(t_flags));
	i = 1;
	while (i < argc && *argv[i] == '-' && ft_ls_param_handler(&flags, argv[i++]))
		continue ;
	ft_vectorinit(&vect, sizeof(char *), 32);
	while (i < argc)
	{
		if (ft_ls_is_valid_param(argv[i]))
			ft_vectorpushback(&vect, &argv[i]);
		else
			ft_ls_error_manager("No such file or directory: ", argv[i], 0);
		i++;
	}
	ft_ls_print(vect, flags);
	return 0;
}
