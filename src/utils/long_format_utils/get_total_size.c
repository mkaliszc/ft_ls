# include "ft_ls.h"

long	get_total_size(t_dir_content **dir_c)
{
	t_dir_content	*cur = *dir_c;
	long			result = 0;

	while (cur)
	{
		result += cur->file_info.st_blocks;
		cur = cur->next;
	}
	return(result / 2);
}