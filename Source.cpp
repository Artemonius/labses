#include <iostream>
#include <string> 
#include <vector> 
#include <windows.h> 
#include <fstream>

using namespace std;
const string file = "myFile.txt";


struct Person
{
    string Family, Name, FatherName, FNF;
    int BornYear, Height, Weight;
    Person* Next;
};

Person NewPerson()
{
    setlocale(LC_ALL, "Russian");
    Person A;
    cin.ignore(32767, '\n');
    cout << "������� �������: "; getline(cin, A.Family);
    cout << "������� ���: "; getline(cin, A.Name);
    cout << "������� ��������: "; getline(cin, A.FatherName);
    A.FNF = A.Family + " " + A.Name + " " + A.FatherName;
    cout << "��� ��������: "; cin >> A.BornYear;
    cout << "����: "; cin >> A.Height;
    cout << "���: "; cin >> A.Weight;

    cout << endl << endl;
    return A;
}

void PrintPersons(vector<Person> Persons)
{
    setlocale(LC_ALL, "Russian");
    for (int i = 0; i < Persons.size(); i++)
    {
        cout << Persons[i].FNF << endl;
        cout << Persons[i].BornYear << endl;
        cout << Persons[i].Height << endl;
        cout << Persons[i].Weight << endl << endl;

    }
}

vector<Person> MakeVector(vector<Person> Per, int length)
{
    for (int i = 0; i < length; i++)
    {
        Person A = NewPerson();
        Per.push_back(A);
    }
    return Per;
}

void InFile(vector<Person> Persons)
{
    ofstream fout;
    fout.open(file);
    if (!fout.is_open())
    {
        cout << "������ �������� �����!";
    }
    else
    {

        for (int i = 0; i < Persons.size(); i++)
        {
            fout << Persons[i].FNF << endl;
            fout << Persons[i].BornYear << endl;
            fout << Persons[i].Height << endl;
            fout << Persons[i].Weight << endl << endl;
        }
        cout << "������ � ���� ������ �������";
    }
    fout.close();
}

vector<Person> DelPeopl(vector<Person> Persons)
{
    int  Height, Weight;
    cout << "������� ��������� �����, ������� ����� �������" << endl;
    cout << "����?"; cin >> Height;
    cout << "���?"; cin >> Weight;
    for (int i = 0; i < Persons.size(); i++)
    {
        if (Persons[i].Weight == Weight || Persons[i].Height == Height)
        {
            Persons.erase(Persons.begin() + i);
        }
    }
    return Persons;
}

bool BeInVector(vector<Person> Persons, string family)
{
    bool ok = false;
    for (int i = 0; i < Persons.size(); i++)
    {
        if (Persons[i].Family == family) ok = true;
    }
    return ok;
}


vector<Person> AddPeopl(vector<Person> Persons)
{
    int n;
    cin.ignore(32767, '\n');
    string Family;
    do
    {
        cout << "������� ������� �������� �����, �������� ������� ������ ��������" << endl;
        cout << "�������?"; getline(cin, Family);
        if (!BeInVector(Persons, Family)) cout << "������ �������� ���!" << endl;
    } while (!BeInVector(Persons, Family));

    Person A = NewPerson();

    for (int i = 0; i < Persons.size(); i++)
    {
        if (Persons[i].Family == Family)
        {
            n = i;
        }
    }
    Persons.insert(Persons.begin() + n + 1, A);
    return Persons;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Person> Persons;
    setlocale(LC_ALL, "Russian");

    int length = 0;
    cout << "\n������� ���������� �������: "; cin >> length;
    Persons = MakeVector(Persons, length);


    cout << "________________________________________________" << endl;
    PrintPersons(Persons);
    cout << "________________________________________________" << endl;
    InFile(Persons);


    cout << "\n������� ����� ����� ��� �����������...";
    cin >> length;
    system("cls");


    Persons = DelPeopl(Persons);
    cout << "________________________________________________" << endl;
    PrintPersons(Persons);
    cout << "________________________________________________" << endl;
    InFile(Persons);

    cout << "\n������� ����� ����� ��� �����������...";
    cin >> length;
    system("cls");


    Persons = AddPeopl(Persons);
    cout << "________________________________________________" << endl;
    PrintPersons(Persons);
    cout << "________________________________________________" << endl;
    InFile(Persons);

    cout << "\n������� ����� ����� ��� �����������...";
    cin >> length;
    system("cls");


}
