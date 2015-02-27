#include "libft.h"
#include "ft_ls.h"

void	optionBigR(char *path, char *options)
{
	DIR				*directory;
	struct dirent	*drnt;
	struct stat		st;
	char			**tmp;
	char			*tmpSuffix;

	directory = opendir(path);
	if (directory == NULL)
	{
		ft_putstr("test path : ");
		ft_putendl(path);
		ft_putendl("Pequeño problemo en la functina optionBigR");
		ft_putendl("Dans ton boule batard");
		perror("el problemo ");
		return ;
		exit(EXIT_SUCCESS);
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
			tmp = (char **)malloc(sizeof(char *) * 2);
			tmp[0] = (char *)malloc(sizeof(char) * (ft_strlen(tmpSuffix) + 1));
			ft_bzero(tmp[0], (ft_strlen(tmpSuffix) + 1));
			ft_strcat(tmp[0], tmpSuffix);
			tmp[1] = (char *)malloc(sizeof(char));
			ft_bzero(tmp[1], 1);


			ft_putstr("\n");

			ft_ls(options, tmp, 1, path); // soit ce ft_ls, soit celui de la ligne !@# mais dans ce dernier cas on com +6lignes
		}
	}
	closedir(directory);
	return ;
}