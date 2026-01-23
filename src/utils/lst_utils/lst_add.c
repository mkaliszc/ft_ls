# include "ft_ls.h"

void	lst_add_front(t_dir_content **lst, t_dir_content *new)
{
	new->next = *lst;
	*lst = new;
}

void	lst_add_back(t_dir_content **lst, t_dir_content *node)
{
	t_dir_content	*pos;

	
	if (node == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = node;
		return ;
	}
	pos = *lst;
	while (pos->next != NULL)
		pos = pos->next;
	pos->next = node;
}