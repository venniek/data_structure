#include "../mst.h"

int ft_min(int a, long long b)
{
	return (a < b ? a : (int)b);
}

int error_nullparameter(void *parameter, char *str)
{
	if (parameter == NULL)
	{
		printf("[error] Null parameter : %s.\n", str);
		return (FALSE);
	}
	return (TRUE);
}

int error_mallocfailure(void *parameter, char *str)
{
	if (parameter == NULL)
	{
		printf("[error] malloc failure : %s.\n", str);
		return (FALSE);
	}
	return (TRUE);
}

ArrayHeapNode make_element(int x, int y, int weight)
{
	ArrayHeapNode element;

	element.x = x;
	element.y = y;
	element.weight = weight;
	return (element);
}