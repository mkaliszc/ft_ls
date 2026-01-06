# include "ft_ls.h"

int	main()
{
	char	*name = ".";
	struct dirent *pDirent;
	DIR *test = opendir(name);

    if (test == NULL) {
        printf ("Cannot open directory '%s'\n", name);
        return 1;
    }
    while ((pDirent = readdir(test)) != NULL) {
		printf ("[%s]\n", pDirent->d_name);
	}
	closedir(test);
}


// TODO :
// opendir ouvre le stream readir permet d'acceder et traverser la struct
// grace a opendir obtenir la liste des fichiers dans un dir stream
// ? regarder avec stat/lstat si ce sont des sous-dossiers ou pas (-R)
// ? get owner id etc avec les autres fonctions autorisees -l 
// * -a jsute regarder les fichier avec un .