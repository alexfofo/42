#include "libft.h"
#include "ft_ls.h"

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