# include "ft_ls.h"

void	handler_long(t_dir_content **dir_c)
{
	t_dir_content	*cur;
	struct passwd	*user = NULL;
	struct group	*group = NULL;
	

	cur = *dir_c;
	ft_printf("total %l\n", get_total_size(dir_c));
	while (cur)
	{
		// perm
		print_perm(cur->file_info);
		// Nombre de liens
        ft_printf("%d ", cur->file_info.st_nlink);
		// owner
		user = getpwuid(cur->file_info.st_uid);
		if (user) {
			ft_printf("%s\t", user->pw_name);
		}
		else {
			ft_printf("%d\t", cur->file_info.st_uid);
		}
		// group
		group = getgrgid(cur->file_info.st_uid);
		if (group) {
			ft_printf("%s\t", group->gr_name);
		}
		else {
			ft_printf("%d\t", cur->file_info.st_uid);
		}
		// size
		ft_printf("%l\t", cur->file_info.st_size);
		// last modification hour and date
		print_time_info(cur->file_info);
		// file name
		ft_printf("%s\n", cur->name);
		cur = cur->next;
	}
}

void	classic_way(t_dir_content **dir_c)
{
	t_dir_content	*cur;

	cur = *dir_c;
	while (cur)
	{
		ft_printf("%s ", cur->name);
		cur = cur->next;
	}
	ft_printf("\n");
}

void	general_handler(int argc, t_dir_content **dir_c, t_flags *flags)
{
	t_dir_content	*tmp;

	sort_content(dir_c, flags);

	if (flags->f_rec)
	{
		if (flags->f_long) {
			handler_long(dir_c);
			ft_printf("\n");
		}
		else {
			classic_way(dir_c);
			ft_printf("\n");
		}

		tmp = *dir_c;
		while (tmp)
		{
			if (S_ISDIR(tmp->file_info.st_mode) && ft_strcmp(tmp->name, ".") && ft_strcmp(tmp->name, "..")) {
				exec(argc, tmp->path, flags); // need to pass the path not only the name of file
			}
			tmp = tmp->next;
		}
	}
	else if (flags->f_long) {
		handler_long(dir_c);
	}
	else {
		classic_way(dir_c);
	}
	lst_free(dir_c);
}