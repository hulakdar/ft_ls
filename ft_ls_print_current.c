/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_print_current.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 18:44:19 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/09 01:22:36 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_put_date(t_file_info info)
{
	ft_puttab("tupa tupa date");
}

void	ft_putinfo(t_file_info info, t_flags flags)
{
	struct group	*grp;
	struct passwd	*pwd;

	grp = getgrgid(info.stat.st_gid);
	pwd = getpwuid(info.stat.st_uid);
	ft_putchar(S_ISDIR(info.stat.st_mode) ? 'd' : '-');
	ft_putchar(info.stat.st_mode & S_IRUSR ? 'r' : '-');
	ft_putchar(info.stat.st_mode & S_IWUSR ? 'w' : '-');
	ft_putchar(info.stat.st_mode & S_IXUSR ? 'x' : '-');
	ft_putchar(info.stat.st_mode & S_IRGRP ? 'r' : '-');
	ft_putchar(info.stat.st_mode & S_IWGRP ? 'w' : '-');
	ft_putchar(info.stat.st_mode & S_IXGRP ? 'x' : '-');
	ft_putchar(info.stat.st_mode & S_IROTH ? 'r' : '-');
	ft_putchar(info.stat.st_mode & S_IWOTH ? 'w' : '-');
	ft_puttab(info.stat.st_mode & S_IXOTH ? "x" : "-");
	ft_putnbr((int)info.stat.st_nlink);
	ft_puttab("");
	ft_puttab(grp->gr_name);
	if (!flags.l_group)
		ft_puttab(pwd->pw_name);
	ft_putnbr((int)info.stat.st_size);
	ft_puttab("");
	ft_put_date(info);
	ft_putendl(info.file_name);
}

void	ft_ls_print_current(t_vector vect,
							t_flags flags,
							void *(*ft_vec_pop)(t_vector *))
{
	t_file_info *tmp;

	while ((tmp = (t_file_info *)ft_vec_pop(&vect)))
	{
		if (flags.list || flags.l_group)
			ft_putinfo(*tmp, flags);
		else
			ft_puttab(tmp->file_name);
	}
	ft_putendl("");
}
