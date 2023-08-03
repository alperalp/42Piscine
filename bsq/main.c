#include <stdio.h>
#include <stdlib.h>
#include "read_file.c"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
	}
}

void print_int_map(int **map, int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ( i < y )
	{
		j = 0;
		while (j < x)
		{
			printf("%d,",map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}
int **create_arr(char **map, int x, int y, char* symbol)
{
	int **map_arr;
	int i = 0;
	int j;
	char c;

	map_arr = malloc(y * sizeof(int *));
	while (i < y)
	{
		j = 0;
		map_arr[i] = malloc(x * sizeof(int));
		while (j < x)
		{
			c = map[i][j];
			if (c == symbol[0])
				map_arr[i][j] = 1;
			j++;
		}
		i++;
	}
	return (map_arr);
}

int min(int a, int b, int c)
{
	int temp;
	temp = a;
	
	if (b < temp)
		temp = b;
	if (c < temp)
		temp = c;
	return(temp);
}
int **process_arr(int **sum_arr,int x, int y)
{
	int i;
	int j;
	
	i = 1;
	j = 1;
	while (i< y)
	{
		j = 1;
		while (j < x)
		{
			if (sum_arr[i][j] == 1)
				sum_arr[i][j] = min(sum_arr[i][j-1],sum_arr[i-1][j],sum_arr[i-1][j-1])+1;
			else
				sum_arr[i][j] = 0;
			j++;
		}
		i++;
	}
	return (sum_arr);

}
struct Solution
{
	int x;
	int y;
	int size;
};

struct Solution *find_solution(int **map,int x, int y)
{
	int i;
	int j;
	int max;

	struct Solution *solution; 
	
	solution= malloc(sizeof(struct Solution));
	i = 0;
	max = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if(map[i][j] > max)
			{
				max = map[i][j];
				solution->x = j;
				solution->y = i;
				solution->size = max;
			}
			j++;
		}
		i++;
	}
	return (solution);
}
void	print_solution(char **map,char *symbol,struct Solution *solution,int x, int y) // düzelt burayı
{
	int i;
	int j;
	int s_x = solution->x - (solution->size-1);
	int s_y = solution->y - (solution->size-1);


	i = 0;
	while(i < x)
	{
		j = 0;
		while (j < y)
		{
			if(j >= s_x && j < s_x + solution->size)
			{
				if(i >= s_y && i < s_y + solution->size)
				{
					ft_putchar(symbol[2]);
					j++;
					continue;
				}	
					
			}	
			ft_putchar(map[i][j]);	
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}
int main(int argc, char **argv) 
{
	int	i;

	i = 1;
	if (argc >= 2)
	{
		while (i < argc)
		{
			char *map_str = readfile(argv[i]);
			char **map_arr = ft_strtodoublepointer(map_str,find_start_pos(map_str),1,find_symbols(map_str));
			int x = find_x_byte(map_str,1);
			int y = find_y_byte(map_str,1,find_symbols(map_str));
			int **sum_arr = create_arr(map_arr,x,y,find_symbols(map_str));
			sum_arr = process_arr(sum_arr,x,y);
			struct Solution *solution = find_solution(sum_arr,x,y);
			print_solution(map_arr,find_symbols(map_str),solution,x,y);	
			free(map_str);
			free(map_arr);
			i++;
		}
	}
	
    return 0;
}

