#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
struct show{
	void operator()(int val){ cout << val << " "; };
};

void mergeSort(int *arr, int size);
void mergeSort(int *&arr, int lo, int hi, int *&aux);
void merge(int *&arr, int lo, int mid, int hi, int *&aux);

int main()
{

	srand(time(0));
	const size_t size = 100;
	int arr[size];
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 100;

	cout << "Before the mergeSort: " << endl;
	for_each(arr, arr + size, show());
	cout << endl << endl;

	
	mergeSort(arr, size);
	cout << "After the mergeSort: " << endl;
	for_each(arr, arr + size, show());
	cout << endl;
}

void mergeSort(int *arr, int size)
{
	int *aux = new int[size];//辅助数组
	mergeSort(arr, 0, size-1, aux);//size-1 是最大的可访问的Index
	delete[] aux;//删除辅助数组
}

void mergeSort(int *&arr, int lo, int hi, int *&aux)
{
	if (lo >= hi)
		return;
	int mid = lo + (hi - lo) / 2;
	mergeSort(arr, lo, mid, aux); //sort左边
	mergeSort(arr, mid + 1, hi, aux);//sort右边
	merge(arr, lo, mid, hi, aux);//merge
}
//the arr was already sorted from lo to mid, from mid+1 to hi
void merge(int *&arr, int lo, int mid, int hi, int *&aux)
{
	int i = lo, j = mid + 1;
	for (int k = lo; k <= hi; k++)
		aux[k] = arr[k];

	int k = lo;
	while (i <= mid && j <= hi)
	{
		if (aux[i] < aux[j])
			arr[k++] = aux[i++];
		else
			arr[k++] = aux[j++];
	}
	while (i <= mid)
		arr[k++] = aux[i++];
	while (j <= hi)
		arr[k++] = aux[j++];
}
