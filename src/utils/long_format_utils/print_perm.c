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
	char	perms[10];

	if (S_ISDIR(file_info.st_mode))
		write(1, "d", 1);
	else if (S_ISLNK(file_info.st_mode))
		write(1, "l", 1);
	else if (S_ISBLK(file_info.st_mode))
		write(1, "b", 1);
	else if (S_ISCHR(file_info.st_mode))
		write(1, "c", 1);
	else if (S_ISFIFO(file_info.st_mode))
		write(1, "p", 1);
	else if (S_ISSOCK(file_info.st_mode))
		write(1, "s", 1);
	else
		write(1, "-", 1);

	perms[0] = (file_info.st_mode & S_IRUSR) ? 'r' : '-';
	perms[1] = (file_info.st_mode & S_IWUSR) ? 'w' : '-';
	perms[2] = (file_info.st_mode & S_IXUSR) ? 'x' : '-';
	perms[3] = (file_info.st_mode & S_IRGRP) ? 'r' : '-';
	perms[4] = (file_info.st_mode & S_IWGRP) ? 'w' : '-';
	perms[5] = (file_info.st_mode & S_IXGRP) ? 'x' : '-';
	perms[6] = (file_info.st_mode & S_IROTH) ? 'r' : '-';
	perms[7] = (file_info.st_mode & S_IWOTH) ? 'w' : '-';
	perms[8] = (file_info.st_mode & S_IXOTH) ? 'x' : '-';
	perms[9] = '\0';

	if (file_info.st_mode & S_ISUID)
		perms[2] = (file_info.st_mode & S_IXUSR) ? 's' : 'S';
	if (file_info.st_mode & S_ISGID)
		perms[5] = (file_info.st_mode & S_IXGRP) ? 's' : 'S';
	if (file_info.st_mode & S_ISVTX)
		perms[8] = (file_info.st_mode & S_IXOTH) ? 't' : 'T';

	ft_printf("%s ", perms);
}