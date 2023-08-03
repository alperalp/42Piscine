#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	find_start_pos(char *str)
{
	int i = 0;
	while(str[i] != '\n')
		i++;
	i++;
	return (i);
}

char *find_symbols(char *str)
{
	int i = 0;
	int j = 0;
	int s_len = find_start_pos(str) - 1;
	char *symbols = malloc(sizeof(char) * s_len);
	while(i < s_len)
	{
		if(!(str[i] >= '0' && str[i] <= '9'))
		{
			symbols[j] = str[i];
			j++;
		}
		i++;
	}
	return (symbols);
}

int	find_x_byte(char *str, int isfile)
{
	int i = 0;
	int x_size = 0;
	while(str[i] != '\n' && isfile == 1)
		i++;
	if(isfile == 1)
		i++;
	while(1)
	{
		if(str[i] ==  '\n')
			break;
		i++;
		x_size++;
	}
	return (x_size);
}

int find_y_byte(char *str,int isfile,char *symbols)
{
	int i = 0;
	int y_len = 0;
	while(str[i] != '\n' && isfile == 1)
		i++;
	while((str[i] == symbols[1] || str[i] <= symbols[0] || str[i] == '\n'))
	{
		if(str[i] == '\n')
			y_len++;
		i++;	
	}
	return (y_len);
}

char *readfile(char *path)
{
	char *c = malloc(sizeof(char) * 1024 * 1024);
	int fd = open(path,O_RDWR);
	int sz = read(fd,c,1024*1024);
	return (c);
}

char **ft_strtodoublepointer(char *str,int start_pos,int isf,char *symbols)
{
	char **arr = malloc(sizeof(int *) * find_y_byte(str,isf,symbols));
	int i = 0;
	int j;
	int add_s = start_pos;

	while (i < find_y_byte(str,isf,symbols))
	{
		arr[i] = malloc(sizeof(char *) * (find_x_byte(str,isf) + 1));
		j = 0;
		while(j <= find_x_byte(str,isf))
		{
			if (str[add_s] != '\n')
				arr[i][j] = str[add_s];
			else
				arr[i][j] = '\0';
			add_s++;
			j++;
		}
		i++;
	}
	return arr;
}
