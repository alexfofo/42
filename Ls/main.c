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
// ft_putendl("	Directory n'est pas NULL");
	i = 0;
	while ((drnt = readdir(directory)) != NULL)
	{
// ft_putendl("	passe dans readdir");
		pathName = (char *)malloc(sizeof(char) * (ft_strlen(name) + ft_strlen(drnt->d_name) + 1));
		ft_bzero(pathName, ft_strlen(pathName));
		ft_strcat(pathName, name);
		ft_strcat(pathName, drnt->d_name);
		elemSorted = sortOptionA(options, drnt->d_name, elemSorted, &i);
		//free(pathName);
	}
	*nbElem = i;
	closedir(directory);
	return elemSorted;
}

char	**sortElems(char *options, char **elemToSort, char *path)
{
	int			count;

	int i = -1;
	count = 0;
// ft_putendl("	THERE");
	while (elemToSort[count] && elemToSort[count][0])
		++count;

// ft_putendl("	THERE");
	elemToSort = sortInAscii(elemToSort, NULL, count);
// ft_putendl("	THERE");
	if (options && ft_strchr(options, 't'))
		elemToSort = sortOptionLilT(elemToSort, path, count);

// ft_putendl("	THERE");
	if (options && ft_strchr(options, 'r'))
		elemToSort = sortOptionLilR(elemToSort, NULL, count);
// ft_putendl("	THERE");

	return elemToSort;
}

void	ft_ls(char *options, char **args, int ac, char *oldPath)
{
	struct stat		st;
	int				totBlock;
	char			**elemsToShow;
	char			*path;
	int				i;
	int				nbElem;

// ft_putendl("In ftls");
	path = args[0];

	nbElem = 0;
	if (lstat(args[0], &st) == -1)
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
// ft_putendl("THERE");
		elemsToShow = sortElems(options, elemsToShow, path); // doit mettre les fichies en premiers, puis les dossiers
	// ft_putendl("BLABLA4");

// ft_putendl("THERE");
		ft_putstr(path);
		ft_putendl(":");
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
	char	**args;

	index = 0;

//getOptions
	options = getOptions(argc, argv, &index);
	ft_putstr("Options recuperées :   ");
	if (*options == '\0')
		ft_putendl("No options, array is empty");
	else
		ft_putendl(options);

//getArgs
	args = getArgs(argc, argv, index);
	if (args == NULL)
	{
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

//tri	
	args = sortInAscii(args, NULL, argc - index);
	if (options && ft_strchr(options, 'r'))
		args = sortOptionLilR(args, NULL, argc - index);
	// faire un sort supplementaire pour trier les fichiers dabord et dossier ensuite


//ls
	ft_putendl("\n\n\n\n\n\n");
	ft_ls(options, args, argc - index, "\0");

	return (0);
}




































