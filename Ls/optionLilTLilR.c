#include "libft.h"
#include "ft_ls.h"

char	**sortOptionLilT(char **oldTab, char *path, int count)
{
	struct stat		s;
	char			**newTab;
	char			*pathName;
	int				i;
	int				j;
	int				tabInt[count];
	int				tabIntBis[count];
	int				tmp;
	int				tmpBis;

ft_putendl("		THERE");
	// if (newTab == NULL)
	newTab = (char **)malloc(sizeof(char *) * (count + 1));
ft_putendl("		THERE");
	i = -1;
	while (++i < count)
	{
		pathName = (char *)malloc(sizeof(char) * (ft_strlen(oldTab[i]) + 1));
		ft_bzero(pathName, ft_strlen(oldTab[i]) + 1);
		ft_strcat(pathName, path);
		ft_strcat(pathName, oldTab[i]);
		lstat(pathName, &s);//checker le retour bordeeeel
		tabInt[i] = s.st_mtime;
		//free(pathName);
	}
ft_putendl("		THERE");
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

ft_putendl("		ToHERE");
	i = -1;
	ft_putnbr(count);
	ft_putendl(" -> count");
	while (++i < count)
	{
		ft_putnbr(i);
		ft_putendl(" -> i");
ft_putendl("		TyyyHERE");
		ft_putnbr(ft_strlen(oldTab[tabIntBis[i]]) + 1);
		ft_putendl(" -> strlen");
ft_putendl("		TyyyHERE");
		newTab[i] = (char *)malloc(sizeof(char) * (ft_strlen(oldTab[tabIntBis[i]]) + 1));
ft_putendl("		TyyyHERE");
		ft_bzero(newTab[i], ft_strlen(oldTab[tabIntBis[i]]) + 1);
ft_putendl("		TyyyHERE");
		ft_strcat(newTab[i], oldTab[tabIntBis[i]]);
	}
ft_putendl("		TyyyHERE");
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
		newTab = (char **)malloc(sizeof(char *) * (count + 1));
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