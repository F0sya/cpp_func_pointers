#include <iostream>
#include <ctime>
using namespace std;

template<typename T>
T* createArray(int size) {
	T* arr = new T[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 20;
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
void sum_and_multiply(T* arr, int size, int* sum, int*multiply) {
	for (int i = 0; i < size; i++) {
		*sum += *(arr+i);
		*multiply *= *(arr + i);
	}
}

int main() {
	srand(time(0));
	//creating array
	int* size = new int;
	cout << "Enter a size of array:"; cin >> *size;
	int* arr = createArray<int>(*size);
	cout << "Array:" << endl; printArray(arr, *size);
	
	//sum and multiply
	int sum = 0, multiply = 1;
	sum_and_multiply<int>(arr, *size,&sum,&multiply);
	cout << endl << "Summary: " << sum << endl << "Multiply: " << multiply << endl;
	
	return 0;
}