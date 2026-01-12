# include "ft_ls.h"

t_dir_content	*lst_new_node(char *dir, char *name)
{
	t_dir_content	*node;
	char			*tmp;
	char			*path;

	node = malloc(sizeof(t_dir_content));
	if (node == NULL)
		return (NULL);

	tmp = ft_strjoin(dir, "/");
	if (tmp == NULL)
		return(free(node), NULL);

	path = ft_strjoin(tmp, name);
	free(tmp);
	if (path == NULL)
		return(free(node), NULL);

	node->name = ft_strdup(name);

	if (stat(path, &(node->file_info)) == -1){
		free(path);
		free(node);
		perror("Stat failed.");
		return(NULL);
	}
	node->next = NULL;
		
	free(path);
	return (node);
}