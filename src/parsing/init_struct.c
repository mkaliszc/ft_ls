# include "ft_ls.h"

t_flags	*init_struct(void)
{
	t_flags	*return_value;

	return_value = malloc(sizeof(t_flags));
	if (!return_value)
		return(perror("INFO : struct init failed."), NULL);
	*return_value = (t_flags){0};
	return (return_value);
}