# include "ft_ls.h"

void	parsing_flags(char *name, t_flags *flags)
{
	int	i = 1;

	while (name[i])
	{
		if (name[i] == 'R') {
			flags->f_rec = true;
		}
		else if (name[i] == 'a') {
			flags->f_all = true;
		}
		else if (name[i] == 'a') {
			flags->f_rev = true;
		}
		else if (name[i] == 'a') {
			flags->f_time = true;
		}
		else if (name[i] == 'a') {
			flags->f_long = true;
		}
		else {
			perror("invalid flag.\n");
			free(flags);
			exit(1);
		}
		i++;
	}
	return ;
}