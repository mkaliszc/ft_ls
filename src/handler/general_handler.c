# include "ft_ls.h"

void	general_handler(t_dir_content **dir_c, t_flags *flags)
{ 
	sort_lst(dir_c, flags);
}