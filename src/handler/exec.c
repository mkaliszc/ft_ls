# include "ft_ls.h"

// here we want to cycle and handle the -R + -l options

void	exec(char *name, t_flags *flags)
{
	t_dir_content	**dir_c;
	struct dirent	*cur;
	DIR				*dir = opendir(name);

	if (dir == NULL) {
		ft_printf_fd(2, "ft_ls: cannot open directory '%s': %s\n", name, strerror(errno));
		return ;
	}

	if (flags->f_rec) {
		ft_printf("%s:\n", name);
	}
	dir_c = read_dir_content(name, flags);
	general_handler(dir_c, flags);
	closedir(dir);
}