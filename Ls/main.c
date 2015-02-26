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



char	**getElemstoDisplay(char *options, char *name, int *nbElem)// use dirent to parcourir DIR et stocker ce qui doit l'etre (-a)
{
	char			**elemSorted;
	DIR				*directory;
	struct dirent	*drnt;
	char			*pathName;
	int				i;

	elemSorted = NULL;
	directory = opendir(name);
// ft_putendl("	In getElemstoDisplay");
	if (directory == NULL)
	{
// ft_putendl("	Directory == NULL");
		*nbElem = 1;
		elemSorted = (char **)malloc(sizeof(char *) * 2);
		elemSorted[0] = (char *)malloc(sizeof(char) * (ft_strlen(name) + 1));
		elemSorted[1] = (char *)malloc(sizeof(char));
		ft_bzero(elemSorted[0], ft_strlen(name) + 1);
		ft_strcat(elemSorted[0], name);
		ft_bzero(elemSorted[1], 1);
		return elemSorted;
	}
// ft_putendl("	Directory n'es tpas NULL");
	i = 0;
	while ((drnt = readdir(directory)) != NULL)
	{
// ft_putendl("	passe dans readdir");
		pathName = (char *)malloc(sizeof(char) * (ft_strlen(name) + ft_strlen(drnt->d_name) + 1));
		ft_bzero(pathName, ft_strlen(pathName));
		ft_strcat(pathName, name);
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

// void	optionBigR(char *path, char *options)
// {
// 	DIR				*directory;
// 	struct dirent	*drnt;
// 	struct stat		st;
// 	char			**tmp;
// 	char			*tmpSuffix;

// 	directory = opendir(path);
// 	if (directory == NULL)
// 	{
// 		ft_putendl("Pequeño problemo en la functina optionBigR");
// 		ft_putendl("Dans ton boule batard");
// 		exit(EXIT_SUCCESS);
// 	}
// 	while ((drnt = readdir(directory)) != NULL)
// 	{
// 		tmpSuffix = createStrSuffix(path, drnt->d_name);
// 		if (stat(tmpSuffix, &st) == -1)
// 		{
// 			ft_putstr("	path = ");
// 			ft_putendl(path);
// 			ft_putstr("	tmpSuffix = ");
// 			ft_putendl(tmpSuffix);
// 			perror("stat in BigR");
// 			exit(EXIT_SUCCESS);
// 		}
// 		if (ft_isDir(tmpSuffix) && ft_strcmp(drnt->d_name, ".") && ft_strcmp(drnt->d_name, ".."))
// 		{
// 			tmp = (char **)malloc(sizeof(char *) * 2);
// 			tmp[0] = (char *)malloc(sizeof(char) * (ft_strlen(tmpSuffix) + 1));
// 			ft_bzero(tmp[0], (ft_strlen(tmpSuffix) + 1));
// 			ft_strcat(tmp[0], tmpSuffix);
// 			tmp[1] = (char *)malloc(sizeof(char));
// 			ft_bzero(tmp[1], 1);


// 			// ft_putendl("On est bien passé dans bigR ma ptite gueule");
// 			// ft_putstr("path = ");
// 			// ft_putendl(path);
// 			// ft_putstr("tmpSuffix = ");
// 			// ft_putendl(tmpSuffix);
// 			// ft_putstr("tmp[0] = ");
// 			// ft_putendl(tmp[0]);
// 			ft_putstr("\n");
// 			ft_ls(options, tmp, 1, path); // soit ce ft_ls, soit celui de la ligne !@# mais dans ce dernier cas on com +6lignes
// 			// ft_ls(options, &(drnt->d_name), 1, path); // ceci est la ligne !@#
// 		}
// 	}
// 	return ;
// }

void	ft_ls(char *options, char **args, int ac, char *oldPath)
{
	struct stat		st;
	int				totBlock;
	char			**elemsToShow;
	char			*path;
	int				i;
	int				nbElem;

// START: met le prefixe 'path' a args[0], ca sert pour -R
	//path = createStrSuffix(oldPath, args[0]);
	path = args[0]; // remplace la ligne du dessus qui est probablement inutile vu que je le fais dans optionBigR
// END: met le prefixe 'path' a args[0], ca sert pour -R
// ft_putstr("test de args[0: ");
// ft_putendl(args[0]);
	if (stat(args[0], &st) == -1)
	{
		ft_putstr("On a args[0] = ");
		ft_putendl(args[0]);
		perror("stat in ft_ls");
		exit(EXIT_SUCCESS);
	}
// ft_putstr("test de path: ");
// ft_putendl(path);
	if (!ft_isDir(path))
		ft_putendl("It s not a dir");
	else
	{
		if (path[ft_strlen(path) - 1] != '/')
			path = createStrSuffix(path, "/");
	}
// ft_putendl("BLABLA");
	if (ft_isDir(path))
	totBlock = computeBlocks(path, options);

// ft_putendl("BLABLA2");

//0 handle -a
	elemsToShow = getElemstoDisplay(options, args[0], &nbElem); // 
// ft_putendl("BLABLA3");
// ft_putstr("test de options: ");
// ft_putendl(options);
// ft_putstr("test de path: ");
// ft_putendl(path);
// ft_putstr("test de nbElem: ");
// ft_putnbr(nbElem);
// ft_putstr("\ntest de *elemsToShow: ");
// ft_putendl(elemsToShow[0]);
	if (nbElem > 0)
	{
		elemsToShow = sortElems(options, elemsToShow, path); // doit mettre les fichies en premiers, puis les dossiers
	// ft_putendl("BLABLA4");

		if (ft_strchr(options, 'l'))
		{
			optionLilL(path, elemsToShow, totBlock, nbElem);
		}
		else
		{
			ft_putstr(path);
			ft_putendl(":");
			i = -1;
			while (elemsToShow && elemsToShow[++i] && elemsToShow[i][0])
				ft_putendl(elemsToShow[i]);
		}

		//cas particulier -R a faire here

		// si il y a des sous dossier:
		// 	alors tq on a pas parcouru ts les sous dosiers, ftls(options, X, Xc)
		// 	avec X un char** des sous-dossiers direct , et Xc le nombre de sous-dossiers direct

		if (ft_strchr(options, 'R') && ft_isDir(path))
		{
			optionBigR(path, options);
		}
	}
	else
	{
		ft_putstr(path);
		ft_putendl(":");
	}

	// getAllDir();



	if (--ac > 0)
	{
		ft_putstr("\n");
		ft_ls(options, ++args, ac, oldPath);
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
	// faire un sort supplementaire pour trier les fichiers dabord et dossier ensuite

	ft_putendl("affichage des elems apres tri");

i = -1;
while (args && ++i < argc - index) // affichage des args recupérés
	{
		ft_putendl(args[i]);
	} // AFFICHAGE

	ft_putendl("\n\n\n\n\n\n");
	ft_ls(options, args, argc - index, "\0");


	return (0);
}




































