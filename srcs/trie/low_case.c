#include "../../includes/prefix_tree.h"

char	**low_case(char **dictionary)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dictionary[j] != NULL)
	{
		while (dictionary[j][i] != '\0')
		{
			if (dictionary[j][i] >= 'A' && dictionary[j][i] <= 'Z')
				dictionary[j][i] = dictionary[j][i] + 32;
			i++;
		}
		i = 0;
		j++;
	}
	return (dictionary);
}
