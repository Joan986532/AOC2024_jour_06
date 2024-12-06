#include <stdio.h>
#include "GNL/get_next_line.h"

// depart (43,52)

void mouvement(char **map, int *i, int *j)
{

	if (map[*i][*j] == '^')
	{
		while (map[*i][*j] != '#' && *i >= 0)
		{
			map[*i][*j] = 'X';
			(*i)--;
		}
		(*i)++;
		map[*i][*j] = '>';
	}
	else if (map[*i][*j] == '>')
	{
		while (map[*i][*j] != '#' && *j <= 130)
		{
			map[*i][*j] = 'X';
			(*j)++;
		}
		(*j)--;
		map[*i][*j] = 'v';
	}
	else if (map[*i][*j] == 'v')
	{
		while (map[*i][*j] != '#' && *i <= 130)
		{
			map[*i][*j] = 'X';
			(*i)++;
		}
		(*i)--;
		map[*i][*j] = '<';
	}
	else if (map[*i][*j] == '<')
	{
		while (map[*i][*j] != '#' && *j >= 0)
		{
			map[*i][*j] = 'X';
			(*j)--;
		}
		(*j)++;
		map[*i][*j] = '^';
	}
}

int main(void)
{
	int fd;
	char **map;
	int i = 0;
	int j = 0;
	int x = 0;
	int count = 0;

	map = malloc(sizeof(char *) * 131);
	fd = open("text", O_RDONLY);
	while (i < 130)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	i = 43;
	j = 52;
	
	while ((i != 129 && i != 0)  && (j != 129 && j != 0))
		mouvement(map, &i, &j);

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'X')
				count++;
			j++;
		}
		i++;
	}
	count += 1;
	while (x < 130)
	{
		printf("%s", map[x]);
		x++;
	}
	printf("%d", count);
}
