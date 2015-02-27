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
