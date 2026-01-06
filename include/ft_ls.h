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

typedef enum s_param {
	ALL,
	REV,
	TIME,
	LONG,
}	t_param;

typedef struct s_data {
	bool	R_param;
	t_param	*flags;
}	t_data;

#endif