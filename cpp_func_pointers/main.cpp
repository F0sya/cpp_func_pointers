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
void counter(T* arr, int size, int* positive, int* negative, int *zero) {
	for (int i = 0; i < size; i++) {
		if (*(arr + i) == 0) {
			(*zero)++;
		}
		else if (*(arr + i) < 0) {
			(*negative)++;
		}
		else {
			(*positive)++;
		}
	}
}

int main() {
	srand(time(0));
	//creating array
	int* size = new int;
	cout << "Enter a size of array:"; cin >> *size;
	int* arr = createArray<int>(*size);
	cout << "Array:" << endl; printArray(arr, *size);

	//amount of positive,negative and zero elements
	int positive = 0, negative = 0, zero = 0;
	counter<int>(arr, *size, &positive, &negative, &zero);
	cout << endl << "Positive: " << positive << endl << "Negative: " << negative << endl << "Zero:" << zero << endl;

	return 0;
}