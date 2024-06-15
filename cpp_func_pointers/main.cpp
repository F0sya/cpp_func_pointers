#include <iostream>
#include <ctime>
using namespace std;

template<typename T>
T* createArray(int size) {
	T* arr = new T[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 20 - 10;
	}
	return arr;
}
template<typename T>
void printArray(T* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << *(arr + i) << " ";
	}
	cout << endl;
}
template<typename T>
T* negativesDelete(T* arr, int size) {
	int new_size = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] >= 0) {
			arr[new_size] = arr[i];
			new_size++;
		}
	}
	cout << "Result array:" << endl; printArray(arr,new_size);
	return arr;
}

int main() {
	srand(time(0));
	//creating array
	int* size = new int;
	cout << "Enter a size of array:"; cin >> *size;
	int* arr = createArray<int>(*size);
	cout << "Array:" << endl; printArray(arr, *size);

	//function pointer
	int* (*func_pointer)(int*, int) = negativesDelete;
	func_pointer(arr, *size);

	return 0;
}