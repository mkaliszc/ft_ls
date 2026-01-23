# include "ft_ls.h"

// here we want to cycle and handle the -R + -l options

void	exec(int argc, char *name, t_flags *flags)
{
	(void)argc; // temp
	t_dir_content	**dir_c;
	DIR				*dir = opendir(name);

	if (dir == NULL) {
		printf_fd(2, "ft_ls: cannot open directory '%s': %s\n", name, strerror(errno));
		return ;
	}

	if (flags->f_rec) {
		ft_printf("%s:\n", name);
	}
	dir_c = read_dir_content(name, flags);
	closedir(dir);
	general_handler(argc, dir_c, flags);
}