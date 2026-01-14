# include "ft_ls.h"

void	lst_free(t_dir_content **content)
{
	t_dir_content	*tmp;

	while (*content)
	{
		tmp = content;
		*content = tmp->next;

		free(tmp->name);
		free(tmp);
	}
}