# include "ft_ls.h"

int	main(int argc, char **argv)
{
	t_flags	*flags = init_struct();

	if (argc == 1) {
		exec(argc, ".", flags);
	}
	else if (argc == 2) {
		for (int i = 1; i < argc; i++) {	
			if (argv[i][0] == '-') {
				checker_flags(argv[1], flags);
				exec(argc, ".", flags);
			}
			else {
				exec(argc, argv[i], flags);
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
			else
				ft_printf("%s:\n", argv[i]);
			exec(argc, argv[i], flags);
			write(1, "\n", 1);
		}
	}
	free(flags);
	return(0);
}
