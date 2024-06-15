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
T* append(T* arr_A, T* arr_B, int size_A, int size_B) {
	T* result_arr = new T[size_A + size_B];
	for (int i = 0; i < size_A + size_B; i++) {
		if (i < size_A) {
			*(result_arr + i) = *(arr_A + i);
		}
		else {
			*(result_arr + i) = *(arr_B + (i - size_A));
		}
	}
	return result_arr;
}

int main() {
	srand(time(0));
	//creating arrays
	int* size_A = new int;
	cout << "Enter a size of array A:"; cin >> *size_A;

	int* size_B = new int;
	cout << "Enter a size of array B:"; cin >> *size_B;

	int* arr_A = createArray<int>(*size_A);
	cout << endl << "Array A:" << endl; printArray(arr_A, *size_A);

	int* arr_B = createArray<int>(*size_B);
	cout << "Array B:" << endl; printArray(arr_B, *size_B);
	//func_pointer
	int* (*func_pointer)(int*, int*, int, int) = append;

	int* result_arr = func_pointer(arr_A, arr_B, *size_A, *size_B);

	cout << "Result array:" << endl; printArray(result_arr, (*size_A + *size_B));

	return 0;
}