# include "ft_ls.h"

int	main()
{
	struct stat	test;

	stat("./../carte_mentale/conditional_instructions_mindmap.html", &test);

	printf("%ld && %s\n", test.st_mtime, ctime(&test.st_mtime));
	return(0);
	//argc, (void)argv;
	// char	*name = ".";
	// struct dirent *pDirent;
	// DIR *test = opendir(name);

    // if (test == NULL) {
    //     printf ("Cannot open directory '%s'\n", name);
    //     return 1;
    // }
    // while ((pDirent = readdir(test)) != NULL) {
	// 	printf ("[%s] ", pDirent->d_name);
	// 	if (pDirent->d_type == DT_REG)
	// 	{
	// 		printf("is a file\n");
	// 	}
	// 	else
	// 	{
	// 		printf("\n");
	// 	}
	// }
	// closedir(test);
}


// TODO :
// opendir ouvre le stream readir permet d'acceder et traverser la struct
// grace a opendir obtenir la liste des fichiers dans un dir stream
// ? get owner id etc avec les autres fonctions autorisees -l 
