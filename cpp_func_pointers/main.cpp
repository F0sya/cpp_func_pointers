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
T* issubset(T* arr_A, T* arr_B, int size_A, int size_B) {
	T* check_set = new T[size_B];
	for (int i = 0; i < size_B; i++) {
		for (int j = 0; j < size_A; j++) {
			if (*(arr_B + i) == *(arr_A + j)) {
				check_set[i] = *(arr_B + i);
			}
		}
	}
	for (int k = 0; k < size_B; k++) {
		if (*(arr_B + k) != *(check_set + k)) {
			return 0;
		}
	}
	return check_set;
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
	int* (*func_pointer)(int*, int*, int, int) = issubset;

	if (func_pointer(arr_A,arr_B,*size_A,*size_B) == 0) {
		cout << "Array B isn't subset of array A" << endl;
	}
	else {
		cout << "\nArray B is subset of array A\nSubset:\n";
		printArray(func_pointer(arr_A, arr_B, *size_A, *size_B), *size_B);
		cout << endl;
	}
	return 0;
}