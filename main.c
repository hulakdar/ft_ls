/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <skamoza@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:30:33 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/07 22:49:39 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_recursive(char *dir_name, t_flags *flags)
{
	char *half;
	char *whole;
	struct dirent	*dirent;
	DIR				*dir;

	if (!(dir = opendir(dir_name)))
		return 1;
	while ((dirent = readdir(dir)))
		if (ft_strncmp(dirent->d_name, ".", 1))
		{
			half = ft_strjoin(dir_name, "/");
			whole = ft_strjoin(half, dirent->d_name);
			free(half);
			ft_list_dir(whole, flags);
			free(whole);
		}
	closedir(dir);
	return (0);
}

int		ft_list_dir(char *dir_name, t_flags *flags)
{
	struct dirent	*dirent;
	DIR				*dir;

	if (!(dir = opendir(dir_name)))
		return 1;
	if (!flags->one)
	{
		ft_putstr(dir_name);
		ft_putendl(":");
	}
	while ((dirent = readdir(dir)))
		if (ft_strncmp(dirent->d_name, ".", 1) || flags->all)
			ft_putendl(dirent->d_name);
	closedir(dir);
	ft_putendl("");
	if (flags->recursive)
		ft_ls_recursive(dir_name, flags);
	return (0);
}

int		ft_ls_param_handler(t_flags *flags, char *param)
{
	if (ft_strequ(param, "-R"))
		flags->recursive = 1;
	else if (ft_strequ(param, "-r"))
		flags->reverse = 1;
	else if (ft_strequ(param, "-t"))
		flags->time_sort = 1;
	else if (ft_strequ(param, "-f"))
		flags->no_sort = 1;
	else if (ft_strequ(param, "-a"))
		flags->all = 1;
	else if (ft_strequ(param, "-u"))
		flags->time_access = 1;
	else if (ft_strequ(param, "-l"))
		flags->list = 1;
	else if (ft_strequ(param, "-g"))
		flags->l_group = 1;
	else
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	int				i;
	int				flag;
	t_flags			flags;

	ft_bzero(&flags, sizeof(t_flags));
	i = 1;
	flag = 1;
	while (ft_ls_param_handler(&flags, argv[i]))
		i++;
	while (i < argc)
	{
		ft_list_dir(argv[i], &flags);
		i++;
		flag = 0;
	}
	if (flag)
	{
		if (!flags.recursive)
			flags.one = 1;
		ft_list_dir(".", &flags);
	}
	return 0;
}
