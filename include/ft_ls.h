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

# include <sys/types.h>
# include <dirent.h>

typedef struct s_flags {
	bool	f_rec;
	bool	f_all;
	bool	f_rev;
	bool	f_time;
	bool	f_long;
}	t_flags;

#endif