# include "ft_ls.h"

int	main(int argc, char **argv)
{
	t_flags	*flags = init_struct();

	if (argc == 1) {
		exec(".", flags);
	}
	else if (argc == 2) {
		for (int i = 1; i < argc; i++) {	
			if (argv[i][0] == '-') {
				checker_flags(argv[1], flags);
				exec(".", flags);
			}
			else {
				exec(argv[i], flags);
			}
		}
	}
	else {
		for (int i = 1; i < argc; i++) {
			if (argv[i][0] == '-')
				checker_flags(argv[i], flags);
		}
		for (int i = 1; i < argc; i++) {
			if (argv[i][0] == '-')
				continue;
			else if (!flags->f_rec)
				ft_printf("%s:\n", argv[i]);

			exec(argv[i], flags);
			write(1, "\n", 1);
		}
	}
	free(flags);
	return(0);
}
