/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afollin <afollin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 13:30:34 by afollin           #+#    #+#             */
/*   Updated: 2015/02/05 13:30:35 by afollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

#include <stdlib.h>
#include <string.h>

#include <dirent.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <grp.h>
#include <pwd.h>

char	**getElemstoDisplay(char *options, char *path, int *nbElem)// use dirent to parcourir DIR et stocker ce qui doit l'etre (-a)
{
	char			**elemSorted;
	DIR				*directory;
	struct dirent	*drnt;
	char			*pathName;
	int				i;

	elemSorted = NULL;
	directory = opendir(path);
	i = 0;
	while ((drnt = readdir(directory)) != NULL)
	{
		pathName = (char *)malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(drnt->d_name) + 1));
		ft_bzero(pathName, ft_strlen(pathName));
		ft_strcat(pathName, path);
		ft_strcat(pathName, drnt->d_name);
		elemSorted = sortOptionA(options, drnt->d_name, elemSorted, &i);
		free(pathName);
	}
	*nbElem = i;
	return elemSorted;
}

char	**sortElems(char *options, char **elemToSort, char *path)
{
	char		**newTab;
	char		**newTab2;
	int			count;

	int i = -1;
		
	// ce qu il faudrait faire
	// c'est concat path avec tous les elemtosort
	// comme ca pas besoin de trimballer le path !
	// easy

	count = 0;
	while (elemToSort[count] && elemToSort[count][0])
		++count;

	elemToSort = sortInAscii(elemToSort, NULL, count);
	newTab = (char **)malloc(sizeof(char *) * (count + 1));// a mettre dans sortOptionLilT()
	if (options && ft_strchr(options, 't'))
		elemToSort = sortOptionLilT(elemToSort, newTab, path, count);

	newTab2 = (char **)malloc(sizeof(char *) * (count + 1));// a mettre dans sortOptionLilR()
	if (options && ft_strchr(options, 'r'))
		elemToSort = sortOptionLilR(elemToSort, newTab2, count);

	return elemToSort;
}

int		ft_isDir(char *entityPath)
{
	struct stat		st;

	if (stat(entityPath, &st) == -1)
	{
		perror("stat in ft_isDir");
		exit(EXIT_SUCCESS);
	}
	if (S_ISDIR(st.st_mode))
		return (1);
	return (0);
}

void	ft_ls(char *options, char **args, int ac, char *oldPath)
{
	struct stat		st;
	int				totBlock;
	char			**elemsToShow;
	char			*path;
	int				i;
	int				nbElem;

// START: met le prefixe 'path' a tous les args, ca sert pour -R
	path = createStrSuffix(oldPath, args[0]);
// END: met le prefixe 'path' a tous les args, ca sert pour -R




	i = -1;
	while (++i < ac)
	{
		if (stat(args[i], &st) == -1)
		{
			perror("stat in ft_isDir");
			exit(EXIT_SUCCESS);
		}
		if (!ft_isDir(path))
			ft_putendl("It s not a dir");
	}

	if (ft_isDir(path))
	totBlock = computeBlocks(path, options);


//0 handle -a
ft_putendl("Ca passe ici");
	elemsToShow = getElemstoDisplay(options, path, &nbElem); // normalenent ya rien a changer pour gerer les fichiers
ft_putendl("Ca ne passe pas ici");
	elemsToShow = sortElems(options, elemsToShow, path); // doit mettre les fichies en premiers, puis les dossiers // createstrsuffix ne se fera pas ici, mais directement dans les check, comme ca ca affichera le bon name direct pas besoin d'enlever un suffix rajouté


	if (ft_strchr(options, 'l'))
	{
		optionLilL(path, elemsToShow, totBlock, nbElem);
	}
	else
	{
		i = -1;
		while (elemsToShow && elemsToShow[++i] && elemsToShow[i][0])
			ft_putendl(elemsToShow[i]);
	}

	//cas particulier -R a faire here

	// si il y a des sous dossier:
	// 	alors tq on a pas parcouru ts les sous dosiers, ftls(options, X, Xc)
	// 	avec X un char** des sous-dossiers direct , et Xc le nombre de sous-dossiers direct

	// getAllDir();

	if (--ac > 0)
	{
		ft_putstr("\n");
		ft_ls(options, ++args, ac, path);
	}

	return ;
}

int		main(int argc, char **argv)
{
	char	*options;
	int		index; // cet index est passé a getoptions() qui le set a l'index du premier argument
	int 	i = 0;
	// char	*argsType;

	index = 0;

//getOptions
	options = getOptions(argc, argv, &index);
	ft_putstr("Options recuperées :   ");
	if (!options)
	{
		ft_putendl("No options, options == NULL");
		options = (char *)malloc(sizeof(char));
		ft_bzero(options, 1);
	}
	if (*options == '\0')
		ft_putendl("No options, array is empty");
	else
		ft_putendl(options);
	// free(options);

	ft_putstr("\nindex auquel commencent les args : ");
	ft_putnbr(index); // TEST DE GETOPTIONS()

//getArgs
ft_putendl("\n\n\n");
	ft_putendl(".  ## TEST GET_ARGS ##  .");
	char	**args;

	args = getArgs(argc, argv, index);
	if (args == NULL)
	{
		ft_putendl("args == NULL");
		args = (char **)malloc(sizeof(char *) * 2);
		args[0] = (char *)malloc(sizeof(char) * 3);
		args[1] = (char *)malloc(sizeof(char));
		ft_bzero(args[0], 3);
		ft_strcat(args[0], "./");
		ft_bzero(args[1], 1);
		++argc;
		if (index == 0)
			++index;
	}
	while (args && i < argc - index) // affichage des args recupérés
	{
		ft_putendl(args[i]);
		++i;
	} // TEST GETARGS()
	args = sortInAscii(args, NULL, argc - index);
	if (options && ft_strchr(options, 'r'))
		args = sortOptionLilR(args, NULL, argc - index);

i = -1;
while (args && i < argc - index) // affichage des args recupérés
	{
		ft_putendl(args[i]);
		++i;
	} // AFFICHAGE

	ft_putendl("\n\n\n\n\n\n");
	ft_ls(options, args, argc - index, "./");


	return (0);
}




































