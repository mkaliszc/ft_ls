#ifndef FT_LS
# define FT_LS

# include "../OctoLIB/include/libft.h"

// * included by libft.h :
// # include <stdlib.h>
// # include <stdio.h>
// # include <ctype.h>
// # include <unistd.h>
// # include <stdarg.h>
// # include <fcntl.h>
// # include <stdbool.h>

# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>

typedef struct s_dir_content
{
	char			*name;
	t_dir_content	*next;
	struct stat		file_info;
}	t_dir_content;


typedef struct s_flags {
	bool	f_rec;
	bool	f_all;
	bool	f_rev;
	bool	f_time;
	bool	f_long;
}	t_flags;

t_flags	*init_struct(void);

void	checker_flags(char *name, t_flags *flags);

t_dir_content	*lst_new_node(char *dir, char *name);
void			lst_add_back(t_dir_content **lst, t_dir_content *node);

#endif