#include "libft.h"
#include "ft_ls.h"

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
	int				i;
	int				j;
	char			*small;

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