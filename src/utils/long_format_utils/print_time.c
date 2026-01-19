# include "ft_ls.h"

void	print_time_info(struct stat file_info)
{
    char *str = ctime(&file_info.st_mtime);
    time_t now = time(NULL);

    write(1, str + 4, 7);
    
    if (file_info.st_mtime > now - 15778800 && file_info.st_mtime <= now)
        write(1, str + 11, 5);
    else
    {
        write(1, " ", 1);
        write(1, str + 20, 4);
    }
}

// Mon Aug  4 19:27:02 2025
// 0123