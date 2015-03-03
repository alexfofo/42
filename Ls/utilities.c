#include "libft.h"
#include "ft_ls.h"

char	*createStrSuffix(char *s1, char *s2)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	ft_bzero(ret, ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strcat(ret, s1);
	ft_strcat(ret, s2);

	return (ret);
}

int		ft_isDir(char *entityPath)
{
	struct stat		st;

// ft_putendl("is in ftisdir");
	if (lstat(entityPath, &st) == -1)
	{
		ft_putendl(entityPath);
		perror("stat in ft_isDir in utilities.c");
		exit(EXIT_SUCCESS);
	}
// ft_putendl("ret1?");
	if (S_ISDIR(st.st_mode))
	{
		// ft_putendl("LA");
		return (1);
	}
// ft_putendl("ret0");
	return (0);
}

char	*duplicateStr(char *str)
{
	char	*dup;
	int		strSize;
	int		size;

	strSize = ft_strlen(str);
	size =  strSize + 1;
	dup = (char *)malloc(sizeof(char) * size);
	ft_bzero(dup, size);
	if (strSize > 0)
		ft_strcat(dup, str);
	return dup;
}

char	**extendTabStr(char **tab, char *str)
{
	char	**extended;
	int		sizeTab;
	int		count;

	sizeTab = -1;
	count = -1;
	if (tab == NULL || tab[0] == NULL)
	{
		extended = (char **)malloc(sizeof(char *) * 2);
		extended[0] = duplicateStr(str);
		extended[1] = duplicateStr("\0");
		return (extended);
	}
	while (tab[++sizeTab][0] != '\0')
		;
	extended = (char **)malloc(sizeof(char *) * (sizeTab + 2));
	while (++count < sizeTab)
	{
		extended[count] = duplicateStr(tab[count]);
		free(tab[count]);
	}
	extended[count] = duplicateStr(str);
	extended[++count] = duplicateStr("\0");
	free(tab);
	return (extended);
}

void	printTabStr(char **tab)
{
	int		i;

	ft_putstr("	in printTabStr\n");
	i = -1;
	while (tab[++i][0])
	{
		ft_putstr("		tab[");
		ft_putnbr(i);
		ft_putstr("] : ");
		ft_putendl(tab[i]);
	}
	ft_putstr("	out printTabStr\n");
	return ;
}



