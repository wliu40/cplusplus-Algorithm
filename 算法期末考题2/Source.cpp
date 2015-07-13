/*
找到一个数组内的最大连续子数组的和。
*/

#include<iostream>
#include <vector>
using namespace std;
int main()
{
	const int size = 8;
	int arr[size] = { -2, 0, 1, 2, 3, -5, 11, 12 };

	int max = 0;
	vector <int> vec;
	for (int i = 0; i < size; i++)
	{
		max += arr[i];
		if (max < 0)
			max = 0;
		else
			vec.push_back(max);
	}

	//find the max value in the vector
	int result = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] > result)
			result = vec[i];
	}

	cout << result << endl;
}