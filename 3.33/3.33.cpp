//Написать программу для работы с базой данных, содержащей записи со сведениями о студентах : ФИО, возраст, пол, курс, успеваемость, в которой должны
//выполняться следующие действия : создание файла, просмотр файла
//
//По исходному файлу определить всех неуспевающих студентов n курса.
//Сформировать файл из этих студентов.

#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <fstream>
#include <time.h>

using namespace std;
enum student_sex {
	MALE = 0,
	FEMALE = 1,
};

const int NAME = 10;         // количество имен в массиве
const char* names[NAME] = { "Алекснадр", "Павел", "Константин", "Юрий", "Влад", "Виталий", "Петр", "Ольга", "Елена", "Дарья", };
const char* surnames[NAME] = { " Бубылда", " Заводской" , " Дотер", " Бревно" , " Цаль", " Бумага" , " Пельмень", " Пахом", " Капуста2004" , " Майнкрафтер" };

struct Student
{
	char name[50]{};
	unsigned short age;
	bool sex;
	unsigned short course;
	unsigned short performance;

	void ShowData()
	{
		cout << endl;
		int i = 0;
		cout << "Name : " << name << endl
			<< "Age : " << age << endl;
		if (this->sex == student_sex::FEMALE) cout << "Female" << endl;
		else cout << "Male" << endl;
		cout << "Course : " << course << endl
		<< "Performance : " << performance << endl;
	}
};

void loadStudentDatabase() {

}
void readFromFile(const string& fileName, vector<Student>& students, int& size) {
	ifstream infile(fileName, ios::binary);
	if (!infile.is_open()) {
		return;
	}
	Student student;
	size = 0;
	while (infile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
		students[size++] = student;
	}
	infile.close();
}

void AddRecord(const string& fileName, const Student& student) {
	fstream file(fileName, ios::binary| ios::in| ios::out| ios::app);
	if (!file.is_open()) {
		return;
	}
	file.write(reinterpret_cast<const char*>(&student), sizeof(Student));
	file.close();
}

void FindFailStuds(const string& infileName, const string& outfileName, int course, int min_performance, int stud_amount) {
	vector<Student> students (stud_amount);
	Student stud;
	readFromFile(infileName, students, stud_amount);
	for (int i = 0; i < stud_amount; ++i) {
		if (students[i].course == course && students[i].performance < min_performance) {
			stud = students[i];
			AddRecord(outfileName, stud);
		}
	}
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
		strcat_s(student.name, surnames[rand() % NAME]);
		
		student.age = rand() % 4 + 17;
		if (name == 7 || name == 8 || name == 9) student.sex = student_sex::FEMALE;
		else student.sex = student_sex::MALE;
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
	cout << " Failing students " << endl;
	FindFailStuds("input.bin", "output.bin", course, min_perf, stud_amount);
	ViewFile("output.bin");
	infile.close();
	outfile.close();
}
