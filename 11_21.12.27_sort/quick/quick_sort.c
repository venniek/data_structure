#include "sort.h"

void print_arr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void quickSort(int *arr, int st, int ed)
{
	if (st >= ed)
		return;
	int key = st;
	int i = st + 1;
	int j = ed;
	int tmp;

	while (i <= j)
	{
		while (arr[i] <= arr[key] && i <= j)
			i++;
		while (arr[j] >= arr[key] && j >= i)
			j--;
		if (i < j)
		{
			tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
		} else {
			tmp = arr[j];
			arr[j] = arr[key];
			arr[key] = tmp;
		}
	}
	quickSort(arr, st, j - 1);
	quickSort(arr, j + 1, ed);
}

int main(void)
{
	int n, tmp;
	int *arr;

	printf("how many numbers: ");
	scanf(" %d", &n);
	arr = (int *)malloc(sizeof(int) * n);
	if (!arr)
		return (0);
	for (int i = 0; i < n; i++)
	{
		scanf(" %d", &tmp);
		arr[i] = tmp;
	}
	printf("before sort\n");
	print_arr(arr, n);
	quickSort(arr, 0, n - 1);
	printf("after sort\n");
	print_arr(arr, n);
}