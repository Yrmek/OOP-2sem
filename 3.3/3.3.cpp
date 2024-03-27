//Написать программу для работы с базой данных, содержащей записи со сведениями о студентах : ФИО, возраст, пол, курс, успеваемость, в которой должны
//выполняться следующие действия : создание файла, просмотр файла
//
//По исходному файлу определить всех неуспевающих студентов n курса.
//Сформировать файл из этих студентов.

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
