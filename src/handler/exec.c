# include "ft_ls.h"

void	exec(char *name, t_flags *flags)
{
	t_dir_content	**dir_c;

	if (flags->f_rec) {
		ft_printf("%s:\n", name);
	}
	dir_c = read_dir_content(name, flags);
	if (!dir_c)
        return ;
	general_handler(dir_c, flags);
}