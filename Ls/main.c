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

void	ft_exit(char *msg, char *options, char *word)
{
	free(options);
	ft_putstr(msg);
	ft_putendl(word);
	exit(0);
	return ;
}

int		checkOption(char *options, char c, char *ref)
{
	int flag;

	flag = -1;
	while (*ref) // le char ne fait pas parti des options supportées
	{
		if (c == *ref)
			flag = 1;
		++ref;
	}
	while (*options && flag > 0) // le char est deja dans options
	{
		if (c == *options)
			flag = 0;
		++options;
	}
	return (flag);
}

int		checkSpecialOptions(int *tmp, int *index, char *word)
{
	if (ft_strncmp(word, "-", ft_strlen(word)) == 0){
		--(*index);
		return (1);
	}
	if (ft_strncmp(word, "--", ft_strlen(word)) == 0){
		*tmp = 0;
		return (1);
	}
	return (0);
}

char	*getOptions(int argc, char **argv, int *index) // retourne un char* contenant les options passées and SET index
{
	char		*options;
	int			opt;
	int			j;
	int			tmp;
	int			breakFlag;

	if ((opt = 0) == 0 && (breakFlag = 0) == 0 && argc == 1) // economise deux lignes d'INITIALISATION
		return (NULL);
	options = (char *)malloc(sizeof(char) * 6);
	ft_bzero(options, 6);
	while (++(*index) < argc && argv[(*index)][0] == '-' && breakFlag == 0)
	{
		j = 0;
		while (argv[(*index)][++j])
		{
			if ((tmp = checkOption( options, argv[(*index)][j], "lRart\0" )) == 1)
				options[opt++] = argv[(*index)][j];
		}
		if (checkSpecialOptions(&tmp, index, argv[(*index)]) == 1)
			breakFlag = 1;
		if (tmp == -1)
			ft_exit("Problem, wrong option: ", options, argv[(*index)]);
	}
	return (options);
}

char	**getArgs(int argc, char **argv, int firstArg)
{
	char	**args;
	int		sub;
	int		i;

	if ((sub = argc - firstArg) == 0 || firstArg == 0)
		return (NULL);
	args = (char **)malloc(sizeof(char *) * (sub + 1));
	i = -1;
	while (++i + firstArg < argc)
	{
		args[i] = (char *)malloc(sizeof(char) * (ft_strlen(argv[i + firstArg]) + 1));
		ft_strcpy(args[i], argv[i + firstArg]);
	}
	// args[i] = (char *)malloc(sizeof(char));//added wednesday morning
	// args[i][0] = '\0';//added wed morning
	if (args && !(*args))
		return (NULL);
	return (args);
}

void	printLastModifTime(time_t mtime)
{
	time_t		curTime;
	struct tm	*timeinfo;
	char		buffer[80];

	time(&curTime);
	timeinfo = localtime(&mtime);
	if ((mtime + 15778463) < curTime || (mtime - 3600) > curTime)
		strftime(buffer, 80, "%b %d %Y", timeinfo);
	else
		strftime(buffer, 80, "%b %d %H:%M", timeinfo);
	ft_putstr(buffer);
	return ;
}

void	testPrintOptionL(char *path, char *name)
{
	struct stat		sb;
	char			*pathName;

	pathName = (char *)malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(name) + 1));
	ft_bzero(pathName, ft_strlen(pathName));
	ft_strcat(pathName, path);
	ft_strcat(pathName, name);
	if (stat(pathName, &sb) == -1)
	{
		perror("stat");
		exit(EXIT_SUCCESS);
	}

	// ft_putnbr(sb.st_blocks);//a additionner pour mettre dans le total
	// ft_putstr("\t");

    ft_putstr( (S_ISDIR(sb.st_mode)) ? "d" : "-");
    ft_putstr( (sb.st_mode & S_IRUSR) ? "r" : "-");
    ft_putstr( (sb.st_mode & S_IWUSR) ? "w" : "-");
    ft_putstr( (sb.st_mode & S_IXUSR) ? "x" : "-");
    ft_putstr( (sb.st_mode & S_IRGRP) ? "r" : "-");
    ft_putstr( (sb.st_mode & S_IWGRP) ? "w" : "-");
    ft_putstr( (sb.st_mode & S_IXGRP) ? "x" : "-");
    ft_putstr( (sb.st_mode & S_IROTH) ? "r" : "-");
    ft_putstr( (sb.st_mode & S_IWOTH) ? "w" : "-");
    ft_putstr( (sb.st_mode & S_IXOTH) ? "x" : "-");
    ft_putstr(" ");
    ft_putnbr(sb.st_nlink);
    ft_putstr("\t");
    ft_putstr((getpwuid(sb.st_uid))->pw_name);
    ft_putstr("  ");
    ft_putstr((getgrgid(sb.st_gid))->gr_name);
    ft_putstr("\t");
    ft_putnbr(sb.st_size);
    ft_putstr("\t");
    // ft_putstr(ctime(&(sb.st_mtime)));
    printLastModifTime(sb.st_mtime);
	ft_putstr(" ");
    ft_putstr(name);
    ft_putstr("\n");

    free(pathName);
	return ;
}

int		computeBlocks(char *path, char *options)
{
	DIR				*directory;
	struct dirent	*drnt;
	struct stat		sa;
	char			*pathName;
	int				totBlock;

	totBlock = 0;
	directory = opendir(path);
	while ((drnt = readdir(directory)) != NULL)
	{
		if (!ft_strchr(options, 'a') && drnt->d_name[0] == '.')
			continue ;
		pathName = (char *)malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(drnt->d_name) + 1));
		ft_bzero(pathName, ft_strlen(pathName));
		ft_strcat(pathName, path);
		ft_strcat(pathName, drnt->d_name);
		if (stat(pathName, &sa) == -1)
		{
			perror("stat in computeBlocks");
			exit(EXIT_SUCCESS);
		}
		totBlock += sa.st_blocks;
		free(pathName);
	}
	return totBlock;
}

char	**extendTab(char **tab, char *name)
{
	int		count;
	int		i;
	char	**ret;

	count = 0;
	// ft_putendl("   		dexter");
	if (tab == NULL)
	{
	// ft_putendl("   		rita");
		ret = (char **)malloc(sizeof(char *) * 2);
		ret[0] = (char *)malloc(sizeof(char) * (ft_strlen(name) + 1));
		ft_bzero(ret[0], ft_strlen(name) + 1);
		ft_strcat(ret[0], name);

		ret[1] = (char *)malloc(sizeof(char));//lol
		ft_bzero(ret[1], 1);//lol
	// ft_putendl("   		hoyohyoyo");
	}
	else
	{
	// ft_putendl("   		belgique");
		while (tab[count] && tab[count][0])
		{
			// ft_putstr("tab[count]:");
			// ft_putendl(tab[count]);
			++count;
		}
	// ft_putstr("   count = ");
	// ft_putnbr(count);
	// ft_putendl(" !");
		ret = (char **)malloc(sizeof(char *) * (count + 2));//+2 pour name et potentiel \0 quil faut ajouter
		count = -1;
	// ft_putendl("   		allemagne");
		while (tab[++count] && tab[count][0])
		{
	// ft_putendl("   			froid	ERR1");
			// ft_putendl(tab[count]);
	// ft_putendl("   			froid	ERR2");
			i = 0;
			while (tab[count][i])
				++i;
			ret[count] = (char *)malloc(sizeof(char) * (i + 1));
	// ft_putendl("   			vodka");
			ft_bzero(ret[count], i + 1);
			ft_strcat(ret[count], tab[count]);
	// ft_putendl("   			ice");
		}
	// ft_putendl("   		russia");
		ret[count] = (char *)malloc(sizeof(char) * (ft_strlen(name) + 1));
		ft_bzero(ret[count], ft_strlen(name) + 1);
		ft_strcat(ret[count], name);

		ret[count + 1] = (char *)malloc(sizeof(char));//lol
		ft_bzero(ret[count + 1], 1);//lol
	}
	// ft_putendl("   		e=mc2");
	//free tab
	return ret;
}

char	**sortOptionA(char *options, char *name, char **elemSorted, int *i)
{
	int			toAdd;

	toAdd = 0;
	// ft_putendl("   Jean michel");
	if (options && ft_strchr(options, 'a'))
		toAdd = 1;
	else if (name && name[0] != '.')
		toAdd = 1;
	// ft_putendl("   Jean chinois");
	if (toAdd == 1)
	{
		elemSorted = extendTab(elemSorted, name);
		*i = *i + 1;
	}
	// ft_putendl("   Jean phillipe");
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
	// ft_putendl("Mexico");
	// ft_putstr(":");
	// ft_putstr(path);
	// ft_putendl(":");
	i = 0;
	while ((drnt = readdir(directory)) != NULL)
	{
	// ft_putendl("Bob");
		pathName = (char *)malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(drnt->d_name) + 1));
	// ft_putendl("A");
		ft_bzero(pathName, ft_strlen(pathName));
	// ft_putendl("b");
		ft_strcat(pathName, path);
	// ft_putendl("c");
		ft_strcat(pathName, drnt->d_name);
	// ft_putendl("d");
		elemSorted = sortOptionA(options, drnt->d_name, elemSorted, &i);
	// ft_putendl("e");
		free(pathName);
	// ft_putendl("carl");
	}
	*nbElem = i;
	// ft_putendl("Rio");
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
	//ci dessous: trouver le plus petit nbr dans tabint donc l'index n'est pas dans tabintbis
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
	// i = -1;
		// ft_putendl(" START");
	// while (++i < count)
	// {
	// 	ft_putnbr(tabIntBis[i]);
	// 	ft_putstr("\n");
	// }
	// 	ft_putendl(" END");

	// creer new tab a partir de old dans l'ordre des index de tabintBis
	i = -1;
	while (++i < count)
	{
		newTab[i] = (char *)malloc(sizeof(char) * (ft_strlen(oldTab[tabIntBis[i]]) + 1));
		ft_bzero(newTab[i], ft_strlen(oldTab[tabIntBis[i]]) + 1);
		ft_strcat(newTab[i], oldTab[tabIntBis[i]]);
	}
	return newTab;
}

int		strInTabStr(char *str, char **tab, int sizeTab)
{
	int		i;

		// ft_putendl("	Well");
	if (!tab || !(tab[0]))
		return (-1);
	i = -1;
		// ft_putendl("	Hum");
	while (++i < sizeTab)
	{
		if (ft_strcmp(tab[i], str) == 0)
			return (1);
	}
		// ft_putendl("	Sure");
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
	int				i;
	int				j;
	char			*small;

	i = -1;
	// while (oldTab && oldTab[++i])
	if (oldTab == NULL)
		return (NULL);
	if (newTab == NULL)
	{
		newTab = (char **)malloc(sizeof(char *) * (count + 1));
	}
	while (++i < count)
	{
		// ft_putendl("isin");
		small = getBiggerStrInTab(oldTab, count);
		j = -1;
		// ft_putendl("isin2");
		while (++j < count)
		{
		// ft_putendl("isin@");
		// ft_putnbr(j);
		// ft_putstr("->j / count <-");
		// ft_putnbr(count);
		// ft_putstr("\n");
			if ((strInTabStr(oldTab[j], newTab, i) <= 0)
				&& ft_strcmp(oldTab[j], small) < 0)
			{
				small = oldTab[j];
			}
		// ft_putendl("isin#");
		}
		// ft_putendl("isout");
		newTab[i] = (char *)malloc(sizeof(char) * (ft_strlen(small) + 1));
		ft_bzero(newTab[i], ft_strlen(small) + 1);
		ft_strcat(newTab[i], small);
	}

	return newTab;
}

char	**sortOptionLilR(char **oldTab, char **newTab, int count)
{
	int				i;
	int				j;
	// int				count;
	char			*small;

	// count = 0;
	// while (oldTab && oldTab[count])
	// 	++count;
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
	newTab[j + 1] = (char *)malloc(sizeof(char));//lol
	ft_bzero(newTab[j + 1], 1);//lol
	// newTab[++j] = NULL;
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
	// ft_putendl("blaliloluuu  TEST elem ot sort");
	while (elemToSort[count] && elemToSort[count][0])
		++count;
	// ft_putendl("le TEST elem ot sort");

	newTab0 = (char **)malloc(sizeof(char *) * (count + 1));
	elemToSort = sortInAscii(elemToSort, newTab0, count);
	// ft_putendl("432 EST elem ot sort");

	// ft_putendl("     Start before -t");
	// while (++i < count)
	// {
	// 	ft_putendl(elemToSort[i]);
	// }
	// ft_putendl("     End before -t");




		newTab = (char **)malloc(sizeof(char *) * (count + 1));
		if (options && ft_strchr(options, 't'))
			elemToSort = sortOptionLilT(elemToSort, newTab, path, count);

	// ft_putendl("999  432 EST elem ot sort");
	// i = -1;
	// ft_putendl("     Start -t done");
	// while (++i < count)
	// {
	// 	ft_putendl(elemToSort[i]);
	// }
	// ft_putendl("     End -t done");
		newTab2 = (char **)malloc(sizeof(char *) * (count + 1));

		if (options && ft_strchr(options, 'r'))
			elemToSort = sortOptionLilR(elemToSort, newTab2, count);

	// ft_putendl(" dtc 432 EST elem ot sort");
	// i = -1;
	// ft_putendl("     Start -r done");
	// while (++i < count)
	// {
	// 	ft_putendl(elemToSort[i]);
	// }
	// ft_putendl("     End -r done");

	return elemToSort;
}









void	ft_ls(char *options, char **args, int ac)
{
	DIR				*directory;
	struct dirent	*drnt;
	int				totBlock;
	char			**elemsToShow;
	char			*path;
	int				i;
	int				nbElem;

//0 handle -a
	// ft_putendl("Bogota");
	if (args)
		path = args[0];
	else
	{
		path = (char *)malloc(sizeof(char) * 3);
		ft_bzero(path, 3);
		ft_strcat(path, "./");
	}
	// ft_putstr("La capital des emirat arabe unis est 			:	");
	// ft_putendl(path);
	elemsToShow = getElemstoDisplay(options, path, &nbElem);
	// int i = -1;
	// while (elemsToShow && elemsToShow[++i])
	// 	ft_putendl(elemsToShow[i]);

//0.5 handle -rt
	// ft_putendl("un truc du genre riga");
	elemsToShow = sortElems(options, elemsToShow, path);
	// ft_putendl("	wrtluihgwleutriurewytlewuytkluwerytlkweutywkluetya");

//1

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
	
	totBlock = computeBlocks(path, options);



	// closedir(directory);

//2

	if (args && *args)
	{
		directory = opendir(args[0]);
		ft_putstr(args[0]);
		ft_putendl(":");
	}
	else
	{
		directory = opendir(".");
		ft_putendl(".:");
	}
	

//faire un premier passage comme la boucle cidessous pour sotcker et trier le contenu direct du dossier
	// et en profiter pour calculer le 'total'

	if (ft_strchr(options, 'l'))
	{
		ft_putstr("total ");
		ft_putnbr(totBlock);
		ft_putstr("\n");
		// while ((drnt = readdir(directory)) != NULL)
		// {
		// 	testPrintOptionL(path, drnt->d_name);
		// }

		i = -1;
		while (++i < nbElem)
		{
			testPrintOptionL(path, elemsToShow[i]);
		}
	}
	else
	{
		i = -1;
		while (elemsToShow && elemsToShow[++i] && elemsToShow[i][0])
			ft_putendl(elemsToShow[i]);
	}

		

	closedir(directory);

	//cas particulier -R a faire here

	if (--ac > 0)
	{
		ft_putstr("\n");
	// ft_putendl("Dans ton cul");
		ft_ls(options, ++args, ac);
	}

	return ;
}



int		main(int argc, char **argv)
{
	char	*options;
	int		index; // cet index est passé a getoptions() qui le set a l'index du premier argument
	int 	i = 0;

	index = 0;

//getOptions
	options = getOptions(argc, argv, &index);
	ft_putendl("Options recuperées :");
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
		argc = 1;
	}
	while (args && i < argc - index) // affichage des args recupérés // a modifier en while (i < argc - index)
	{
		ft_putendl(args[i]);
		++i;
	} // TEST GETARGS()
	args = sortInAscii(args, NULL, argc - index);
	if (options && !ft_strchr(options, 'r'))
	{
		// ft_putnbr(argc - index);
		args = sortOptionLilR(args, NULL, argc - index);
	}

	// i = -1;
	// while (args[++i])
		// ft_putendl(args[i]);

	ft_putendl("\n\n\n\n\n\n");
	ft_ls(options, args, argc - index);


	return (0);
}




































