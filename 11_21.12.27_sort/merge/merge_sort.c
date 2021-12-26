#include "sort.h"

int *arr2;

void print_arr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void mergeSort(int *arr, int l, int r)
{
	if (l == r)
		return;
	int mid = (r + l) / 2;
	mergeSort(arr, l, mid);
	mergeSort(arr, mid + 1, r);

	int st1 = l;
	int st2 = mid + 1;
	int idx = l;

	while (st1 <= mid || st2 <= r)
	{
		if (st1 <= mid && st2 <= r)
			arr2[idx++] = (arr[st1] < arr[st2] ? arr[st1++] : arr[st2++]);
		else
			arr2[idx++] = (st1 > mid ? arr[st2++] : arr[st1++]);
	}
	for (int i = l; i <= r; i++)
		arr[i] = arr2[i];
}

int main(void)
{
	int n, tmp;
	int *arr;

	printf("how many numbers: ");
	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int) * n);
	if (!arr)
		return (0);
	arr2 = (int *)malloc(sizeof(int) * n);
	if (!arr2)
		return (1);
	for (int i = 0; i < n; i++)
	{
		scanf(" %d", &tmp);
		arr[i] = tmp;
	}
	printf("before sort\n");
	print_arr(arr, n);
	mergeSort(arr, 0, n - 1);
	printf("after sort\n");
	print_arr(arr, n);
}