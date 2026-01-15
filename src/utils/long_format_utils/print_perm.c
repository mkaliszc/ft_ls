# include "ft_ls.h"

void	print_perm(struct stat file_info)
{
	int	mode[] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH};
	char	perm_char[] = {'r', 'w', 'x'};
	if (S_ISDIR(file_info.st_mode)) {
		write(1, "d", 1);
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