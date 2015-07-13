/*
找到一个数组中特定的元素，该元素的值等于它的Index，要求使用divid and conquer方法。
该数组已经是一个升序数组。
*/

#include<iostream>

using namespace std;

int fun(int *arr, int size);
int fun(int *arr, int left, int right);

//调用, function for calling in main
int fun(int *arr, int size)
{
	return fun(arr, 0, size);
}
//重载，the function who does the real job
int fun(int *arr, int left, int right)
{
	int mid = (left + right) / 2;
	if (arr[mid] == mid)//if it satisfy the requirement, return it
		return mid;
	else
	{
		if (arr[mid] > mid)//go to left half
			fun(arr, left, mid);
		else
			fun(arr, mid, right);//go to right half
	}
}


int main()
{
	const int size = 8;
	int arr[size] = {-2,0,1,2,3,5,11,12};
	int result = fun(arr, size);
	cout << result << endl;

}