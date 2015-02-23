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

	if (stat(entityPath, &st) == -1)
	{
		perror("stat in ft_isDir");
		exit(EXIT_SUCCESS);
	}
	if (S_ISDIR(st.st_mode))
		return (1);
	return (0);
}