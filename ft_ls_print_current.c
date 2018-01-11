/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_print_current.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skamoza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 18:44:19 by skamoza           #+#    #+#             */
/*   Updated: 2018/01/11 20:20:06 by skamoza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_put_date(time_t time_file)
{
	char	*str;
	time_t	cur_time;

	time(&cur_time);
	str = ctime(&time_file);
	write(1, str + 4, 7);
	if (cur_time < time_file || cur_time - 15768000 > time_file)
		write(1, str + 20, 4);
	else
		write(1, str + 11, 5);
}

void	ft_put_type(t_file_info info)
{
	if (S_ISLNK(info.stat.st_mode))
		ft_putchar('l');
	else if (S_ISDIR(info.stat.st_mode))
		ft_putchar('d');
	else if (S_ISCHR(info.stat.st_mode))
		ft_putchar('c');
	else if (S_ISBLK(info.stat.st_mode))
		ft_putchar('b');
	else if (S_ISFIFO(info.stat.st_mode))
		ft_putchar('p');
	else if (S_ISSOCK(info.stat.st_mode))
		ft_putchar('s');
	else
		ft_putchar('-');
}

void	ft_put_permissions(t_file_info info, t_flags flags)
{
	struct group	*grp;
	struct passwd	*pwd;
	char			buffer[256];

	grp = getgrgid(info.stat.st_gid);
	ft_put_type(info);
	ft_putchar(info.stat.st_mode & S_IRUSR ? 'r' : '-');
	ft_putchar(info.stat.st_mode & S_IWUSR ? 'w' : '-');
	ft_putchar(info.stat.st_mode & S_IXUSR ? 'x' : '-');
	ft_putchar(info.stat.st_mode & S_IRGRP ? 'r' : '-');
	ft_putchar(info.stat.st_mode & S_IWGRP ? 'w' : '-');
	ft_putchar(info.stat.st_mode & S_IXGRP ? 'x' : '-');
	ft_putchar(info.stat.st_mode & S_IROTH ? 'r' : '-');
	ft_putchar(info.stat.st_mode & S_IWOTH ? 'w' : '-');
	ft_putchar(info.stat.st_mode & S_IXOTH ? 'x' : '-');
	ft_puttab(listxattr(info.file_path, buffer, 256, XATTR_NOFOLLOW) > 0 ?
			"@" : " ");
	pwd = getpwuid(info.stat.st_uid);
	ft_put_size_t(info.stat.st_nlink);
	ft_puttab("");
	if (!flags.l_group)
		ft_puttab(pwd->pw_name);
	if (!flags.no_group)
		ft_puttab(grp->gr_name);
}

void	ft_putinfo(t_file_info info, t_flags flags)
{
	char name[256];

	ft_put_permissions(info, flags);
	ft_putnbr((int)info.stat.st_size);
	ft_puttab("");
	ft_put_date(flags.time_access ? info.stat.st_atime : info.stat.st_mtime);
	ft_puttab("");
	if (S_ISLNK(info.stat.st_mode))
		ft_putstr(ANSI_PINK);
	else if (info.stat.st_mode & S_IXUSR && !S_ISDIR(info.stat.st_mode))
		ft_putstr(ANSI_RED);
	else if (S_ISDIR(info.stat.st_mode))
		ft_putstr(ANSI_GREEN);
	ft_putstr(info.file_name);
	if (S_ISLNK(info.stat.st_mode))
	{
		name[readlink(info.file_path, &name[0], 256)] = '\0';
		ft_putstr(" -> ");
		ft_putstr(name);
	}
	ft_putendl(ANSI_RESET);
}

void	ft_ls_print_current(t_vector vect,
							t_flags flags,
							void *(*ft_vec_pop)(t_vector *))
{
	t_file_info *tmp;

	if (flags.list)
		ft_put_total(vect, ft_vec_pop);
	while ((tmp = (t_file_info *)ft_vec_pop(&vect)))
	{
		if (flags.list || flags.l_group)
			ft_putinfo(*tmp, flags);
		else
			ft_puttab(tmp->file_name);
	}
	ft_putendl("");
}
