#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main() {
	setlocale(LC_ALL, "RUS");
	system("color F0");
	cout << "введите размерность массива" << endl;
	int n;
	cin >> n;
	while (n <= 0) {
		cout << "размерность может быть только положительной, попробуйте еще раз";
		cin >> n;
	}
	int* arr = new int[n];
	for (int i = 1; i <= n; i++) {
		arr[i] = rand() % 100 + 1;
		cout << arr[i] << " ";
	}
	cout << endl << "введите номер элемента, с которого нужно начать удаление" << endl;
	int nk;
	cin >> nk;
	while (nk > n) {
		cout << "введите корректный номер tлемента";
		cin >> nk;
	}
	while (nk <= 0) {
		cout << "введите корректный номер элемента";
		cin >> nk;
	}
	cout << endl << "введите количество удаляемых элементов" << endl;
	int nd;
	cin >> nd;
	while ((nd <= 0)||(nk+nd>n)) {
		cout << "введите количество удаляемых элементов снова ";
		cin >> nd;
	}
	while (nk <= 0) {
		cout << "введите номер элемента снова ";
		cin >> nk;
	}
	int* newarr = new int[n];
	for (int i = 1; i <= n - nd; i++) {
		newarr[i] = arr[i];
	}
	//сделали переписку, надо  вконце еще прописать условие
	for (int i = nk; i < nk + nd; i++) {
		cout << endl << "введите новые элементы" << endl;
		cin >> newarr[i];
	}
	for (int i = nk + nd; i <= n; i++) {
		newarr[i] = arr[i];
	}
	cout << endl;

	for (int i = 1; i <= n; i++) {
		cout << endl << newarr[i] << endl;
	}

}