#include <stdio.h>
#include "GNL/get_next_line.h"

// depart (43,52)

void mouvement(char **map, int *i, int *j, int *count)
{

	if (map[*i][*j] == '^')
	{
		map[*i][*j] = '.';
		while ((map[*i][*j] != '#' && map[*i][*j] != 'O') && *i > 0)
		{
			(*i)--;
			(*count)++;
		}
		if (*i == 0)
			return ;
		(*i)++;
		map[*i][*j] = '>';
	}
	else if (map[*i][*j] == '>')
	{
		map[*i][*j] = '.';
		while ((map[*i][*j] != '#' && map[*i][*j] != 'O') && *j < 129)
		{
			(*j)++;
			(*count)++;
		}
		if (*j == 129)
			return ;
		(*j)--;
		map[*i][*j] = 'v';
	}
	else if (map[*i][*j] == 'v')
	{
		map[*i][*j] = '.';
		while ((map[*i][*j] != '#' && map[*i][*j] != 'O') && *i < 129)
		{
			(*i)++;
			(*count)++;
		}
		if (*i == 129)
			return ;
		(*i)--;
		map[*i][*j] = '<';
	}
	else if (map[*i][*j] == '<')
	{
		map[*i][*j] = '.';
		while ((map[*i][*j] != '#' && map[*i][*j] != 'O') && *j > 0)
		{
			(*j)--;
			(*count)++;
		}
		if (*j == 0)
			return ;
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
	int y = 0;
	int count = 0;
	int total = 0;
	int num_loop = 0;
	int temp;

	temp = 0;
	map = malloc(sizeof(char *) * 131);
	fd = open("text", O_RDONLY);
	while (i < 130)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	
	while (x < 130)
	{
		y = 0;
		while (y < 130)
		{
			if (x == 43 && y == 52)
				y++;
			temp = map[x][y];
			map[x][y] = 'O';
			i = 43;
			j = 52;
			count = 0;
			map[i][j] = '^';
			while ((i != 129 && i != 0)  && (j != 129 && j != 0) && count < 10000)
				mouvement(map, &i, &j, &count);
			map[i][j] = '.';
			if (count >= 10000)
				total++;
			map[x][y] = temp;
			y++;
		}
		x++;
	}
	map[43][52] = '^';
	x = 0;
	while (x < 130)
	{
		printf("%s", map[x]);
		x++;
	}
	printf("%d", total);
}
