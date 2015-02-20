#include "libft.h"
#include "ft_ls.h"

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

void	printOptionL(char *path, char *name)
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

void	optionLilL(char *path, char **elemsToShow, int totBlock, int nbElem)
{
	int		i;

	i = -1;
	ft_putstr("total ");
	ft_putnbr(totBlock);
	ft_putstr("\n");

	i = -1;
	while (++i < nbElem)
	{
		printOptionL(path, elemsToShow[i]);
	}
}