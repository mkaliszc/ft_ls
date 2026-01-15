# include "ft_ls.h"

void	handler_long(t_dir_content **dir_c)
{
	// TODO : check for perm on each file, the size, owner/creator, date and hard links
	t_dir_content	*cur;

	cur = *dir_c;
	while (cur)
	{
		// perm
		print_perm(cur->file_info);
		// owner
		ft_printf("%s ", cur->file_info.st_uid);
		// group
		ft_printf("%s ", cur->file_info.st_gid);
		// size
		ft_printf("%l ", cur->file_info.st_size);
		// last modification hour and date
		print_time_info(cur->file_info); // to implement
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
		ft_printf("%s\t", cur->name);
		cur = cur->next;
	}
	ft_printf("\n");
}

void	general_handler(t_dir_content **dir_c, t_flags *flags)
{
	t_dir_content	*tmp;

	sort_lst(dir_c, flags);

	if (flags->f_rec)
	{
		if (flags->f_long) {
			handler_long(dir_c);
		}
		else {
			classic_way(dir_c);
		}

		tmp = *dir_c;
		while (tmp)
		{
			if (S_ISDIR(tmp->file_info.st_mode)) {
				exec(tmp->name, flags);
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