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
T* remove(T* arr_A,int size_A, int start_index, int end_index) {
	T* result_arr = new T[size_A - (end_index-start_index) - 1];
	for (int i = 0; i < size_A; i++) {
		if (i <= start_index) {
			*(result_arr + i) = *(arr_A + i);
		}
		else if (i > end_index) {
			*(result_arr + (i - (end_index - start_index) - 1)) = *(arr_A + i);
		}
	}
	return result_arr;
}

int main() {
	srand(time(0));
	//creating arrays
	int* size_A = new int;
	cout << "Enter a size of array A:"; cin >> *size_A;

	int* arr_A = createArray<int>(*size_A);
	cout << endl << "Array A:" << endl; printArray(arr_A, *size_A);

	int* start_index = new int;
	cout << "Enter a start index for removing:"; cin >> *start_index;

	int* end_index = new int;
	cout << "Enter an end index for removing:"; cin >> *end_index;

	//func_pointer
	int* (*func_pointer)(int*, int, int, int) = remove;

	int* result_arr = func_pointer(arr_A, *size_A, *start_index,*end_index);

	cout << "Result array:" << endl; printArray(result_arr, (*size_A-(*end_index-*start_index) - 1));

	return 0;
}