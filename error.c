#include "node_utils.h"
#include "struct.h"
#include <limits.h>
#include <stdio.h>
int valcmp(char *str, char *val)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] < val[i])
			break;
		if(str[i] > val[i])
			return 1;
		i++;
	}
	return (0);
}
int check_maxvalue(char *str, char *max, char *min)
{
	int size;
	int i;
	size = strlen_ps(str);
	if (*str == '-')
	{
		if( size > 11)
			return 1;
		else if (size == 11 && valcmp(str, min))
			return 1;
	}
	if (!(*str == '-'))
	{
		if (size > 10)
			return 1;
		else if (size == 10 && valcmp(str,max))
			return 1;
	}
	return 0;
}

int check_input(char *str)
{
	if (*str == '-')
		str++;
	if (*str == '0')
		return 1;
	while(*str)
	{
		if(!('0' <= *str && *str <= '9'))
			return 1;
		str++;
	}
	return 0;
}
int check_errors(char **argv, int count)
{
	int i;
	int ii;

	i = 1;
	ii = 0;
	while (i < count)
	{	
		if (check_input(argv[i]))
			return 1;
		if (check_maxvalue(argv[i],"2147483647", "-2147483648"))
			return 1;
		i++;
	}
	return (0);
}
