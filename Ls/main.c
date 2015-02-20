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


// void	printLastModifTime(time_t mtime)
// {
// 	time_t		curTime;
// 	struct tm	*timeinfo;
// 	char		buffer[80];

// 	time(&curTime);
// 	timeinfo = localtime(&mtime);
// 	if ((mtime + 15778463) < curTime || (mtime - 3600) > curTime)
// 		strftime(buffer, 80, "%b %d %Y", timeinfo);
// 	else
// 		strftime(buffer, 80, "%b %d %H:%M", timeinfo);
// 	ft_putstr(buffer);
// 	return ;
// }

// void	printOptionL(char *path, char *name)
// {
// 	struct stat		sb;
// 	char			*pathName;

// 	pathName = (char *)malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(name) + 1));
// 	ft_bzero(pathName, ft_strlen(pathName));
// 	ft_strcat(pathName, path);
// 	ft_strcat(pathName, name);
// 	if (stat(pathName, &sb) == -1)
// 	{
// 		perror("stat");
// 		exit(EXIT_SUCCESS);
// 	}

//     ft_putstr( (S_ISDIR(sb.st_mode)) ? "d" : "-");
//     ft_putstr( (sb.st_mode & S_IRUSR) ? "r" : "-");
//     ft_putstr( (sb.st_mode & S_IWUSR) ? "w" : "-");
//     ft_putstr( (sb.st_mode & S_IXUSR) ? "x" : "-");
//     ft_putstr( (sb.st_mode & S_IRGRP) ? "r" : "-");
//     ft_putstr( (sb.st_mode & S_IWGRP) ? "w" : "-");
//     ft_putstr( (sb.st_mode & S_IXGRP) ? "x" : "-");
//     ft_putstr( (sb.st_mode & S_IROTH) ? "r" : "-");
//     ft_putstr( (sb.st_mode & S_IWOTH) ? "w" : "-");
//     ft_putstr( (sb.st_mode & S_IXOTH) ? "x" : "-");
//     ft_putstr(" ");
//     ft_putnbr(sb.st_nlink);
//     ft_putstr("\t");
//     ft_putstr((getpwuid(sb.st_uid))->pw_name);
//     ft_putstr("  ");
//     ft_putstr((getgrgid(sb.st_gid))->gr_name);
//     ft_putstr("\t");
//     ft_putnbr(sb.st_size);
//     ft_putstr("\t");
//     printLastModifTime(sb.st_mtime);
// 	ft_putstr(" ");
//     ft_putstr(name);
//     ft_putstr("\n");

//     free(pathName);
// 	return ;
// }

// int		computeBlocks(char *path, char *options)
// {
// 	DIR				*directory;
// 	struct dirent	*drnt;
// 	struct stat		sa;
// 	char			*pathName;
// 	int				totBlock;

// 	totBlock = 0;
// 	directory = opendir(path);
// 	while ((drnt = readdir(directory)) != NULL)
// 	{
// 		if (!ft_strchr(options, 'a') && drnt->d_name[0] == '.')
// 			continue ;
// 		pathName = (char *)malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(drnt->d_name) + 1));
// 		ft_bzero(pathName, ft_strlen(pathName));
// 		ft_strcat(pathName, path);
// 		ft_strcat(pathName, drnt->d_name);
// 		if (stat(pathName, &sa) == -1)
// 		{
// 			perror("stat in computeBlocks");
// 			exit(EXIT_SUCCESS);
// 		}
// 		totBlock += sa.st_blocks;
// 		free(pathName);
// 	}
// 	return totBlock;
// }

char	**extendTab(char **tab, char *name)
{
	int		count;
	int		i;
	char	**ret;

	count = 0;
	if (tab == NULL)
	{
		ret = (char **)malloc(sizeof(char *) * 2);
		ret[0] = (char *)malloc(sizeof(char) * (ft_strlen(name) + 1));
		ft_bzero(ret[0], ft_strlen(name) + 1);
		ft_strcat(ret[0], name);

		ret[1] = (char *)malloc(sizeof(char));
		ft_bzero(ret[1], 1);
	}
	else
	{
		while (tab[count] && tab[count][0])
		{
			++count;
		}
		ret = (char **)malloc(sizeof(char *) * (count + 2));//+2 pour name et potentiel \0 quil faut ajouter
		count = -1;
		while (tab[++count] && tab[count][0])
		{
			i = 0;
			while (tab[count][i])
				++i;
			ret[count] = (char *)malloc(sizeof(char) * (i + 1));
			ft_bzero(ret[count], i + 1);
			ft_strcat(ret[count], tab[count]);
		}
		ret[count] = (char *)malloc(sizeof(char) * (ft_strlen(name) + 1));
		ft_bzero(ret[count], ft_strlen(name) + 1);
		ft_strcat(ret[count], name);

		ret[count + 1] = (char *)malloc(sizeof(char));//lol
		ft_bzero(ret[count + 1], 1);//lol
	}
	//free tab
	return ret;
}

char	**sortOptionA(char *options, char *name, char **elemSorted, int *i)
{
	int			toAdd;

	toAdd = 0;
	if (options && ft_strchr(options, 'a'))
		toAdd = 1;
	else if (name && name[0] != '.')
		toAdd = 1;
	if (toAdd == 1)
	{
		elemSorted = extendTab(elemSorted, name);
		*i = *i + 1;
	}
	return elemSorted;
}

char	**getElemstoDisplay(char *options, char *path, int *nbElem)
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

char	**sortOptionLilT(char **oldTab, char **newTab, char *path, int count)
{
	struct stat		s;
	char			*pathName;
	int				i;
	int				j;
	int				tabInt[count];
	int				tabIntBis[count];
	int				tmp;
	int				tmpBis;

	i = -1;
	
	while (++i < count)
	{
		pathName = (char *)malloc(sizeof(char) * (ft_strlen(oldTab[i]) + 1));
		ft_bzero(pathName, ft_strlen(oldTab[i]) + 1);
		ft_strcat(pathName, path);
		ft_strcat(pathName, oldTab[i]);
		stat(pathName, &s);
		tabInt[i] = s.st_mtime;
		free(pathName);
	}
	//ci dessous: trouver le plus petit nbr dans tabint dont l'index n'est pas dans tabintbis
	j = -1;
	while (++j < count)
	{
		i = -1;
		tmp = tabInt[0];
		tmpBis = -1;
		while (++i < count)
		{
			if ((tabInt[i] > -1 && tabInt[i] > tmp) || tmpBis == -1)
			{
				tmp = tabInt[i];
				tmpBis = i;
			}
		}
		tabInt[tmpBis] = -1;
		tabIntBis[j] = tmpBis;
	}

	i = -1;
	while (++i < count)
	{
		newTab[i] = (char *)malloc(sizeof(char) * (ft_strlen(oldTab[tabIntBis[i]]) + 1));
		ft_bzero(newTab[i], ft_strlen(oldTab[tabIntBis[i]]) + 1);
		ft_strcat(newTab[i], oldTab[tabIntBis[i]]);
	}
	newTab[i] = (char *)malloc(sizeof(char));
	ft_bzero(newTab[i], 1);
	return newTab;
}

int		strInTabStr(char *str, char **tab, int sizeTab)
{
	int		i;

	if (!tab || !(tab[0]))
		return (-1);
	i = -1;
	while (++i < sizeTab)
	{
		if (ft_strcmp(tab[i], str) == 0)
			return (1);
	}
	return (0);
}

char	*getBiggerStrInTab(char **tab, int count)
{
	int		i;
	char	*big;

	i = -1;
	if (!tab || !tab[0])
		return (NULL);
	big = tab[0];
	while (++i < count)
	{
		if (ft_strcmp(big, tab[i]) < 0)
			big = tab[i];
	}
	return (big);
}

char	**sortInAscii(char **oldTab, char **newTab, int count)
{
	int				i;// il y a un probleme au niveau du sort ascci des args dans le main
	int				j;// les args passés sont ./ ../ par exemple, du coup le tri foire
	char			*small;// car il faudrait passer . et .. !!! a regler

	i = -1;
	if (oldTab == NULL)
		return (NULL);
	if (newTab == NULL)
	{
		newTab = (char **)malloc(sizeof(char *) * (count + 1));
	}
	while (++i < count)
	{
		small = getBiggerStrInTab(oldTab, count);
		j = -1;
		while (++j < count)
		{
			if ((strInTabStr(oldTab[j], newTab, i) <= 0)
				&& ft_strcmp(oldTab[j], small) < 0)
			{
				small = oldTab[j];
			}
		}
		newTab[i] = (char *)malloc(sizeof(char) * (ft_strlen(small) + 1));
		ft_bzero(newTab[i], ft_strlen(small) + 1);
		ft_strcat(newTab[i], small);
	}
	newTab[i] = (char *)malloc(sizeof(char));
	ft_bzero(newTab[i], 1);

	return newTab;
}

char	**sortOptionLilR(char **oldTab, char **newTab, int count)
{
	int				i;
	int				j;
	char			*small;

	if (newTab == NULL)
	{
		newTab = (char **)malloc(sizeof(char *) * (count + 1));

	}
	j = -1;
	while (--count >= 0)
	{
		newTab[++j] = (char *)malloc(sizeof(char) * (ft_strlen(oldTab[count]) + 1));
		ft_bzero(newTab[j], ft_strlen(oldTab[count]) + 1);
		ft_strcat(newTab[j], oldTab[count]);
	}
	newTab[j + 1] = (char *)malloc(sizeof(char));
	ft_bzero(newTab[j + 1], 1);
	return newTab;
}

char	**sortElems(char *options, char **elemToSort, char *path)
{
	char		**newTab0;
	char		**newTab;
	char		**newTab2;
	int			count;

	int i = -1;
		

	count = 0;
	while (elemToSort[count] && elemToSort[count][0])
		++count;

	newTab0 = (char **)malloc(sizeof(char *) * (count + 1));// a mettre dans sortinascii()
	elemToSort = sortInAscii(elemToSort, newTab0, count);

	newTab = (char **)malloc(sizeof(char *) * (count + 1));// a mettre dans solt()
	if (options && ft_strchr(options, 't'))
		elemToSort = sortOptionLilT(elemToSort, newTab, path, count);

	newTab2 = (char **)malloc(sizeof(char *) * (count + 1));// a mettre dans solr()
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




void	ft_ls(char *options, char **args, int ac)
{
	DIR				*directory;
	struct dirent	*drnt;
	struct stat		st;
	int				totBlock;
	char			**elemsToShow;
	char			*path;
	int				i;
	int				nbElem;

//0 handle -a
	if (args)
		path = args[0];
	else
	{
		path = (char *)malloc(sizeof(char) * 3);
		ft_bzero(path, 3);
		ft_strcat(path, "./");
	}

	// handleFileInArgs (args, ac)
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
	// //if path is a file, just display file
	// if (!ft_isDir(path))
	// {
	// 	// elemsToShow = (char **)malloc(sizeof(char *) * 2);
	// 	// ft_bzero(elemsToShow[0], ft_strlen(path + 1));
	// 	// ft_bzero(elemsToShow[1], 1);
	// 	// ft_strcat(elemsToShow[0], path);
	// 	ft_putendl(path);
	// 	if (--ac > 0)
	// 	{
	// 		ft_putstr("\n");
	// 		ft_ls(options, ++args, ac);
	// 	}
	// 	return ;
	// }
	// else
		elemsToShow = getElemstoDisplay(options, path, &nbElem);
	elemsToShow = sortElems(options, elemsToShow, path);

	totBlock = computeBlocks(path, options);

	// if (args && *args)
	// {
	// 	directory = opendir(args[0]);
	// 	ft_putstr(args[0]);
	// 	ft_putendl(":");
	// }
	// else
	// {
	// 	directory = opendir(".");
	// 	ft_putendl(".:");
	// }

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

	// closedir(directory);

	//cas particulier -R a faire here

	// si il y a des sous dossier:
	// 	alors tq on a pas parcouru ts les sous dosiers, ftls(options, X, Xc)
	// 	avec X un char** des sous-dossiers direct , et Xc le nombre de sous-dossiers direct

	// getAllDir();

	if (--ac > 0)
	{
		ft_putstr("\n");
		ft_ls(options, ++args, ac);
	}

	return ;
}



int		main(int argc, char **argv)
{
	char	*options;
	int		index; // cet index est passé a getoptions() qui le set a l'index du premier argument
	int 	i = 0;
	char	*argsType;

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
	args = sortInAscii(args, NULL, argc - index); // probleme ici, expliqué dans sortInAscii()
	if (options && !ft_strchr(options, 'r'))
	{
		args = sortOptionLilR(args, NULL, argc - index);
	}

	ft_putendl("\n\n\n\n\n\n");
	ft_ls(options, args, argc - index);


	return (0);
}




































