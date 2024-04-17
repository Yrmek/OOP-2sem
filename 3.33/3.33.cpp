//Написать программу для работы с базой данных, содержащей записи со сведениями о студентах : ФИО, возраст, пол, курс, успеваемость, в которой должны
//выполняться следующие действия : создание файла, просмотр файла
//
//По исходному файлу определить всех неуспевающих студентов n курса.
//Сформировать файл из этих студентов.

#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
#include <time.h>

using namespace std;

const int NAME = 10;         // количество имен в массиве
const char* names[NAME] = { "Саша", "Паша", "Коля", "Юра", "Семен", "Артем", "Петя", "Оля", "Лена", "Даша", };

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
		cout << "Name : " << name << endl
			<< "Age : " << age << endl
			<< "Sex : " << sex << endl
			<< "Course : " << course << endl
			<< "Performance : " << performance << endl;
	}
};

void AddRecord(const string& fileName, const Student& student) {
	fstream file(fileName, ios::binary| ios::in| ios::out| ios::app);
	if (!file.is_open()) {
		return;
	}
	file.write(reinterpret_cast<const char*>(&student), sizeof(Student));
	file.close();
}

void FindFailStuds(const string& infileName , const string& outfileName, int course , int min_performance) {
	ifstream infile(infileName, ios::binary );
	ofstream outfile(outfileName, ios::binary );
	Student student;
	while (infile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
		if (student.course == course && student.performance < min_performance)
			outfile.write(reinterpret_cast<char*>(&student), sizeof(Student));
	}
	infile.close();
	outfile.close();
}

void ViewFile(const string& fileName) {
	ifstream file(fileName, ios::binary);
	if (!file.is_open()) {
		return;
	}
	Student student;
	while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
		student.ShowData();
	}
}

void FillBase(const string& infilename, int amount)
{
	srand(time(NULL));
	for (int i = 0; i < amount; ++i) {
		Student student;
		int name = rand() % NAME;
		strcpy_s(student.name,names[name]);
		student.age = rand() % 4 + 17;
		if (name == 7 || name == 8 || name == 9) student.sex = 'f';
		else student.sex = 'm';
		student.course = rand() % 3 + 1;
		student.performance = rand() % 10;
		AddRecord(infilename, student);
	}
}

void main()
{
	setlocale(LC_ALL, "");
	fstream infile("input.bin", ios::trunc | ios::out | ios::in | ios::binary );
	infile.clear();
	fstream outfile("output.bin", ios::trunc | ios::out | ios::in | ios::binary);
	outfile.clear();
	int course = 0;
	int min_perf = 0;
	int stud_amount = 0;
	cout << "Enter amount of students : " << endl;
	cin >> stud_amount;
	cout << "Enter minimum performance and course of failing students :" << endl;
	cin >> min_perf >> course;
	FillBase("input.bin", stud_amount);
	cout << "List of students :" << endl;
	ViewFile("input.bin");
	cout << "_____________________________" << endl;
	FindFailStuds("input.bin", "output.bin", course, min_perf);
	ViewFile("output.bin");
	infile.close();
	outfile.close();
}
