//�������� ��������� ��� ������ � ����� ������, ���������� ������ �� ���������� � ��������� : ���, �������, ���, ����, ������������, � ������� ������
//����������� ��������� �������� : �������� �����, �������� �����
//
//�� ��������� ����� ���������� ���� ������������ ��������� n �����.
//������������ ���� �� ���� ���������.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct Student
{
	char name[50]{};
	int age;
	char sex;
	int course;
	int perfomance;

	void ShowData()
	{
		cout << "Name " << name << endl
			<< "Age " << age
	}
};

void main()
{
	fstream studbase("StudBase.txt", ios::in | ios::out | ios::binary | ios::trunc);
	fstream failbase("FailBase.txt", ios::in | ios::out | ios::binary | ios::trunc);
	

}
