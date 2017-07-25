#include <iostream>
#include <map>

using namespace std;

void twoSum(int *arr, int length, int target)
{
	for (int i = 0;i < length;i++)
	{
		int first = arr[i];
		for (int j = i + 1;j < length;j++)
		{
			if (arr[j] == target - first)
			{
				cout << i << ',' << j << endl;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {2, 7, 1, 9, 23, 5, 6, 3};
	map<int, int> m;
	m[0] = 3;
	cout << m[0] << endl;
	int length = sizeof(arr) / sizeof (arr[0]);
	// twoSum(arr, length, 3);
	return 0;
}