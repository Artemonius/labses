#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main() {
	setlocale(LC_ALL, "RUS");
	system("color F0");
	cout << "������� ����������� �������" << endl;
	int n;
	cin >> n;
	while (n <= 0) {
		cout << "����������� ����� ���� ������ �������������, ���������� ��� ���";
		cin >> n;
	}
	int* arr = new int[n];
	for (int i = 1; i <= n; i++) {
		arr[i] = rand() % 100 + 1;
		cout << arr[i] << " ";
	}
	cout << endl << "������� ����� ��������, � �������� ����� ������ ��������" << endl;
	int nk;
	cin >> nk;
	while (nk > n) {
		cout << "������� ���������� ����� t�������";
		cin >> nk;
	}
	while (nk <= 0) {
		cout << "������� ���������� ����� ��������";
		cin >> nk;
	}
	cout << endl << "������� ���������� ��������� ���������" << endl;
	int nd;
	cin >> nd;
	while ((nd <= 0)||(nk+nd>n)) {
		cout << "������� ���������� ��������� ��������� ����� ";
		cin >> nd;
	}
	while (nk <= 0) {
		cout << "������� ����� �������� ����� ";
		cin >> nk;
	}
	int* newarr = new int[n];
	for (int i = 1; i <= n - nd; i++) {
		newarr[i] = arr[i];
	}
	//������� ���������, ����  ������ ��� ��������� �������
	for (int i = nk; i < nk + nd; i++) {
		cout << endl << "������� ����� ��������" << endl;
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