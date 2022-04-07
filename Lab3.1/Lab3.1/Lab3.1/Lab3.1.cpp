/*
Сформувати масив структур, що містять інформацію про : прізвище
студента, курс, спеціальність(для представлення спеціальності використовувати переліки, а
    для представлення курсу – цілі числа) та оцінки з фізики, математики, інформатики

    Варіант 16.
1. Обчислити кількість студентів, середній бал яких вищий за 4,5.
2. Порівнюючи середні бали для кожного предмету, визначити предмет, середній бал 
якого найбільший.
*/


#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Specilnist { KN, INF, MathEcon, PhysInf, WORK };

string predmetStr[] = { " Комп. науки  ", " Інформатика  ", "Мат. та економ", " Фіз. та інф. ", " Труд. навч.  " };


struct Student
{
	string prizvandname;
	unsigned kurs;
	Specilnist spec;
	int Physical;
	int Math;
	int Informatik;
};



void Create(Student* s, const int N);
void Print(Student* s, const int N);
int Count(Student* s, const int N);
string Highest(Student* s, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть кількість студентів: "; cin >> N;

	Student* s = new Student[N];

	string prizvandname;
	unsigned kurs;
	Specilnist spec;
	int Physical;
	int Math;
	int Informatik;


	Create(s, N);
	Print(s, N);

	int counter = Count(s, N);

	if (counter != 0)
		cout << "Кількість студентів з середнім балом вище 4.5 - " << counter << endl;
	else
		cout << endl << "Немає студентів з балом вище 4.5" << endl;
	
	cout << endl;

	cout << Highest(s, N) << endl;
	

	return 0;
}


void Create(Student* s, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
		cout << " прізвище: "; getline(cin, s[i].prizvandname);
		cout << " курс: "; cin >> s[i].kurs;
		cout << "  Виберіть спеціальність (0 - Комп. науки , 1 - Інформатика , 2 - Мат. та економ , 3 - Фіз. та інф. , 4 - Труд. навч. ): "; cin >> spec;
		s[i].spec = (Specilnist)spec;
		cout << " Оцінка з Фізики: "; cin >> s[i].Physical;
		cout << " Оцінка з Математики: "; cin >> s[i].Math;
		cout << " Оцінка з Інфортматики: "; cin >> s[i].Informatik;


		cout << endl;
	}
}
void Print(Student* s, const int N)
{
	cout << "======================================================================================="
		<< endl;
	cout << "| № |      Прізвище       | Курс | Спеціальність | Фізика | Математика | Інфортматика | "
		<< endl;
	cout << "---------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(20) << left << s[i].prizvandname << "| " << setw(4) << right << s[i].kurs << " ";
		cout << "| " << setw(8) << right << predmetStr[s[i].spec] << " |";
		cout << "| " << setw(6) << setprecision(2) << fixed << right << s[i].Physical << right << " |";
		cout << " " << setw(10) << right << s[i].Math << " |";
		cout << " " << setw(12) << right << s[i].Informatik << " |" << endl;
		
	}
	cout << "=======================================================================================" << endl;
	cout << endl;
}
/* 
Обчислити кількість студентів, середній бал яких вищий за 4,5.
*/
int Count(Student* s, int n)
{
	int  counter = 0;
	for (int i = 0; i < n; i++)
	{
		double d = s[i].Informatik + s[i].Math + s[i].Physical;
		double dd = d / 3;
		if (dd > 4.5) 
			counter++;	
	}
	return counter;
}

/*
Порівнюючи середні бали для кожного предмету, визначити предмет, середній бал якого найбільший.
*/
string Highest(Student* s, const int N)
{
	double inf = 0, math = 0, phys = 0;
	double I, M, F;
	for (int i = 0; i < N; i++)
	{
		inf += s[i].Informatik;
		math += s[i].Math;
		phys += s[i].Physical;
	}

	I = inf / N;
	M = math / N;
	F = phys / N;

		if (I == F && F == M && I == M)
			return "Всі предмети мають одинаковий середній бал";
		if (I == F || I == M || M == F)
			return "два предмети мають одинаковий середній бал";
		if (F > M && F > I)
			return "physics";
		if (M > F && M > I)
			return "math";
		if (I > F && I > M)
			return "informatik";

}


