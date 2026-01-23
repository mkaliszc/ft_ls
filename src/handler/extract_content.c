# include "ft_ls.h"

/* Here we put the content of the dir in a linked list to use it after*/

t_dir_content	**read_dir_content(char *dir, t_flags *flags)
{
    t_dir_content   **file_list;
    t_dir_content   *cur;
    struct dirent   *tmp;
    DIR             *dir_stream = opendir(dir);
    
    if (dir_stream == NULL) {
        printf("Cannot open directory '%s'\n", dir);
        return (NULL);
    }

    file_list = malloc(sizeof(t_dir_content *));
    if (!file_list)
        return (NULL);
    *file_list = NULL;
    
    while ((tmp = readdir(dir_stream)) != NULL)
    {
        if (!flags->f_all && tmp->d_name[0] == '.') {
            continue;
        }
        cur = lst_new_node(dir, tmp->d_name);
        lst_add_back(file_list, cur);
    }
    
    closedir(dir_stream);
    return (file_list);
}