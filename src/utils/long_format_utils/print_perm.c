# include "ft_ls.h"

void	print_link(t_dir_content *cur)
{
	char	*buf;
	ssize_t		len;

	buf = malloc(cur->file_info.st_size + 1);
    if (!buf) {
        perror("malloc");
        return;
    }

	len = readlink(cur->path, buf, cur->file_info.st_size);
	if (len == -1) {
		perror("readlink");
		free(buf);
		return ;
	}

	buf[len] = '\0';
	ft_printf(" -> %s", buf);
	free(buf);
	return ;
}

void	print_perm(struct stat file_info)
{
	int	mode[] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH};
	char	perm_char[] = {'r', 'w', 'x'};

	if (S_ISDIR(file_info.st_mode)) {
		write(1, "d", 1);
	}
	else if (S_ISLNK(file_info.st_mode)) {
		write(1, "l", 1);
	}
	else {
		write(1, "-", 1);
	}
	for (int i = 0; i < 9; i++)
	{
		if (file_info.st_mode & mode[i]) {
			write(1, &perm_char[i % 3], 1);
		}
		else {
			write(1, "-", 1);
		}
	}
	write(1, " ", 1);
}