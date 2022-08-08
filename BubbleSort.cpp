#include <iostream>

using namespace std;

int main()
{
    int arr[] = { 43,1253,1245,42,72,621,642,8236};
	cout << "Source array: ";
	for (size_t i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	for (size_t i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
	{
		for (size_t j = i; j < (sizeof(arr) / sizeof(arr[0])); j++)
		{
			if (arr[i] > arr[j])
			{
				auto tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}

	cout << "Sorted array: ";
	for (size_t i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
