# include "ft_ls.h"

void	alpha_sort(t_dir_content **dir)
{
	t_dir_content	*sorted = NULL;
	t_dir_content	*cur;
	t_dir_content	*prev;
	t_dir_content	*lowest;
	t_dir_content	*tmp;

	while (*dir)
	{
        cur = *dir;
        lowest = cur;
        prev = NULL;
        tmp = NULL;
        
        while (cur)
        {
            if (ft_strcmp(cur->name, lowest->name) < 0)
            {
                lowest = cur;
                prev = tmp;
            }
            tmp = cur;
            cur = cur->next;
        }
        if (prev)
            prev->next = lowest->next;
        else
            *dir = lowest->next;

		lowest->next = NULL;
		ft_lstadd_back(sorted, lowest);
		cur = cur->next;
	}
	*dir = sorted;
}

void	time_sort(t_dir_content **dir)
{
	t_dir_content	*sorted = NULL;
	t_dir_content	*cur;
	t_dir_content	*prev;
	t_dir_content	*lowest;
	t_dir_content	*tmp;

	while (*dir)
	{
        cur = *dir;
        lowest = cur;
        prev = NULL;
        tmp = NULL;
        
        while (cur)
        {
            if ()
            {
                lowest = cur;
                prev = tmp;
            }
            tmp = cur;
            cur = cur->next;
        }
        if (prev)
            prev->next = lowest->next;
        else
            *dir = lowest->next;

		lowest->next = NULL;
		ft_lstadd_back(sorted, lowest);
		cur = cur->next;
	}
	*dir = sorted;
}

void	rev_sort(t_dir_content **dir)
{

}