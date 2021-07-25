#include <iostream>

void FillArray(int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

void ShowArray(const int* arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
}

void push_back(int*& arr, int &size, const int value)
{
	int* newArray = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}
	newArray[size++] = value;

	delete[] arr;

	arr = newArray;
}

void pop_back(int*& arr, int& size, const int value)
{
	size--;
	int* newArray = new int[size];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}

	newArray[value] = arr[size];

	delete[] arr;

	arr = newArray;
}


int main()
{
	setlocale(LC_ALL, "Rus");
	using namespace std;
	int size = 5;
	int *arr = new int[size];
	FillArray(arr, size);
	ShowArray(arr, size);
	push_back(arr, size, 101);
	ShowArray(arr, size);
	pop_back(arr, size, 4);
	ShowArray(arr, size);
	cin.get();

	delete[] arr;
}