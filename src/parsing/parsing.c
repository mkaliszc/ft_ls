# include "ft_ls.h"

void	checker_flags(char *str, t_flags *flags)
{
	int	i = 1;

	while (str[i])
	{
		if (str[i] == 'R') {
			flags->f_rec = true;
		}
		else if (str[i] == 'a') {
			flags->f_all = true;
		}
		else if (str[i] == 'r') {
			flags->f_rev = true;
		}
		else if (str[i] == 't') {
			flags->f_time = true;
		}
		else if (str[i] == 'l') {
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