//Написать программу для работы с базой данных, содержащей записи со сведениями о студентах : ФИО, возраст, пол, курс, успеваемость, в которой должны
//выполняться следующие действия : создание файла, просмотр файла
//
//По исходному файлу определить всех неуспевающих студентов n курса.
//Сформировать файл из этих студентов.

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
			cout << name[++i];
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
	fstream studbase("StudBase.txt", ios::in | ios::out | ios::binary );
	fstream failbase("FailBase.txt", ios::in | ios::out | ios::binary );
	

}
