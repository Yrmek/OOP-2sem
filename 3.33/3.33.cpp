//�������� ��������� ��� ������ � ����� ������, ���������� ������ �� ���������� � ��������� : ���, �������, ���, ����, ������������, � ������� ������
//����������� ��������� �������� : �������� �����, �������� �����
//
//�� ��������� ����� ���������� ���� ������������ ��������� n �����.
//������������ ���� �� ���� ���������.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>

using namespace std;
struct Student
{
	char name[50]{};
	int age;
	char sex;
	int course;
	int performance;

	void ShowData()
	{
		cout << endl;
		int i = 0;
		while (name[i] != 0) {
			cout << name[i];
			++i;
		}
		cout << endl;
		cout << "Age : " << age << endl
			<< "Sex : " << sex << endl
			<< "Course : " << course << endl
			<< "Performance : " << performance << endl;
	}
};


void main()
{
	fstream studbase("input.bin", ios::in | ios::out | ios::binary);
	fstream failbase("output.bin", ios::in | ios::out | ios::binary);
	Student biba{"bibas", 2, 'm', 2, 10 };
	biba.ShowData();

}
