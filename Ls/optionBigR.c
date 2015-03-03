#include "libft.h"
#include "ft_ls.h"

void	optionBigR(char *path, char *options)
{
	DIR				*directory;
	struct dirent	*drnt;
	struct stat		st;
	char			**tmp;
	// char			**tmp2;
	char			*tmpSuffix;
	int				count;

// ft_putendl("rentre dans bigR");
	count = 0;
	directory = opendir(path);
	tmp = NULL;
	if (directory == NULL)
	{
		perror("el problemo ");
		return ;
	}
	while ((drnt = readdir(directory)) != NULL)
	{
		tmpSuffix = createStrSuffix(path, drnt->d_name);
		if (lstat(tmpSuffix, &st) == -1)
		{
			ft_putstr("	path = ");
			ft_putendl(path);
			ft_putstr("	tmpSuffix = ");
			ft_putendl(tmpSuffix);
			perror("stat in BigR");
			exit(EXIT_SUCCESS);
		}
		if (ft_isDir(tmpSuffix) && ft_strcmp(drnt->d_name, ".") && ft_strcmp(drnt->d_name, ".."))
		{
			tmp = extendTabStr(tmp, tmpSuffix);
			// free(tmp);
			// tmp = tmp2;
			++count;
		}
	}
	if (tmp == NULL)
		return ;
	tmp = sortInAscii(tmp, NULL, count);
	if (options && ft_strchr(options, 'r'))
		tmp = sortOptionLilR(tmp, NULL, count);
	if (options && ft_strchr(options, 't'))
		tmp = sortOptionLilT(tmp, NULL, count);
	ft_putstr("\n");
	ft_ls(options, tmp, count, path);
	closedir(directory);
	return ;
}