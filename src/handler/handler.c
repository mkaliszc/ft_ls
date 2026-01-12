# include "ft_ls.h"

t_dir_content	**read_dir_content(char *dir)
{
	t_dir_content	**file_list;
	t_dir_content	*cur = NULL;
	struct stat		file_info;
	struct dirent	*tmp;
	DIR				*dir_stream = opendir(dir);

	if (dir_stream == NULL) {
		printf ("Cannot open directory '%s'\n", dir);
		return 1;
	}

	while ((tmp = readdir(dir_stream)) != NULL)
	{
		cur = lst_new_node(dir, tmp->d_name);
		lst_add_back(file_list, cur);
	}

	closedir(dir_stream);
	return(file_list);
}