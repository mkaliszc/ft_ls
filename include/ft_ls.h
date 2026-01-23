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
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>

/* This struct will contain the content of each dir*/

typedef struct s_dir_content
{
	char					*path;
	char					*name;
	struct s_dir_content	*next;
	struct stat				file_info;
}	t_dir_content;

/* this struct contain every flag checked after the parsing to be faster */

typedef struct s_flags {
	bool	f_rec;
	bool	f_all;
	bool	f_rev;
	bool	f_time;
	bool	f_long;
}	t_flags;

/* Parsing */
t_flags			*init_struct(void);
void			checker_flags(char *str, t_flags *flags);

/* handler */
t_dir_content	**read_dir_content(char *dir, t_flags *flags);
void			general_handler(int argc, t_dir_content **dir_c, t_flags *flags);
void			sort_content(t_dir_content **dir_c, t_flags *flags);
void			alpha_sort(t_dir_content **dir);
void			time_sort(t_dir_content **dir);
void			rev_sort(t_dir_content **dir);
void			exec(int argc, char *name, t_flags *flags);

/* utils */
t_dir_content	*lst_new_node(char *dir, char *name);
void			lst_add_back(t_dir_content **lst, t_dir_content *node);
void			lst_add_front(t_dir_content **lst, t_dir_content *new);
void			lst_free(t_dir_content **content);
void			print_perm(struct stat file_info);
void			print_time_info(struct stat file_info);
long			get_total_size(t_dir_content **dir_c);

#endif