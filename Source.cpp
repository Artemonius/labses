#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool proverka(char x)
{
	string t = "�����Ÿ�������������";
	for (int i = 0; i < 20; i++)
	{
		if (x == t[i])return true;
	}
	return false;
}
int main() {
	system("chcp 1251>nul");
	setlocale(LC_ALL, "RUS");
	fstream file("��������.txt");
	if (!file)
	{
		cout << "���� �� ������\n\n";
		return -1;
	}
	else
	{
		cout << "��� ��! ���� ������!\n\n";
	}
	string s[20];
	for (int i = 1; i <= 12; i++) {
		getline(file, s[i]);
		cout << s[i] << endl;
	}
	cout << endl << "����� ������� ������, ������� � ������� �� ������ ����������� ������" << endl;
	int das;
	cin >> das;
	while (das <= 0) {
		cout << "����� ������ ���, �� ���� ������ ������������� ���� ������� ������";
		cin >> das;
	}
	while (das + 5 >= 13) {
		cout << "�� ����� ����� ��������, ��� ��������� �� ������� �������...";
		cin >> das;
	}
	string ds[20];
	int j = 1;
	for (int i = das; i <= das + 5; i++) {
		ds[j] = s[i];
		j++;

	}
	cout << endl << "��� ������, ������� �� ������ �����������" << endl;
	int sum = 0;
	string hlad;
	for (int i = 1; i <= 12; i++) {
		getline(file, s[i]);
		cout << ds[i] << endl;
	}
	for (int i = 1; i <= 12; i++) {
		hlad = ds[i];
		j = 0;
		while (j < hlad.size()) {
			if (proverka(hlad[j]) == true) {
				sum++;
			}
			j++;
		}
	}
	cout << "����� ������� ���� " << sum << endl;
	fstream F2("file2.txt");
	for (int i = 1; i < 13; i++) {
		F2 << ds[i] << endl;
	}
	if (!F2)
	{
		cout << "���� �� ������\n\n";
		return 0;
	}
	else
	{
		cout << "��� ��! ���� ������!\n\n";
	}
}