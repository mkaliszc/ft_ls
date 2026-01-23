# include "ft_ls.h"

void	alpha_sort(t_dir_content **dir)
{
    t_dir_content   *sorted = NULL;
    t_dir_content   *cur;
    t_dir_content   *prev;
    t_dir_content   *lowest;
    
    while (*dir)
    {
        cur = *dir;
        lowest = cur;
        prev = NULL;
        
        while (cur->next)
        {
            if (ft_strcmp(cur->next->name, lowest->name) < 0)
            {
                lowest = cur->next;
                prev = cur;
            }
            cur = cur->next;
        }
        
        if (prev)
            prev->next = lowest->next;
        else
            *dir = lowest->next;
        
        lowest->next = NULL;
        lst_add_back(&sorted, lowest);
    }
    
    *dir = sorted;
}

void	time_sort(t_dir_content **dir)
{
    t_dir_content   *sorted = NULL;
    t_dir_content   *cur;
    t_dir_content   *prev;
    t_dir_content   *lowest;
    
    while (*dir)
    {
        cur = *dir;
        lowest = cur;
        prev = NULL;
        
        while (cur->next)
        {
            if (ft_strcmp(cur->next->name, lowest->name) < 0)
            {
                lowest = cur->next;
                prev = cur;
            }
            cur = cur->next;
        }
        
        if (prev)
            prev->next = lowest->next;
        else
            *dir = lowest->next;
        
        lowest->next = NULL;
        lst_add_back(&sorted, lowest);
    }
    
    *dir = sorted;
}

void	rev_sort(t_dir_content **dir)
{
    t_dir_content   *sorted = NULL;
    t_dir_content   *cur;

    while (*dir)
    {
        cur = *dir;
        *dir = cur->next;
        cur->next = NULL;

        lst_add_front(&sorted, cur);
    }
    *dir = sorted;
}

/* Here we sort the content of a dir to get the output order of it*/

void	sort_content(t_dir_content **dir_c, t_flags *flags)
{
	alpha_sort(dir_c);

	if (flags->f_time) {
		time_sort(dir_c);
	}

	if (flags->f_rev) {
		rev_sort(dir_c);
	}
}