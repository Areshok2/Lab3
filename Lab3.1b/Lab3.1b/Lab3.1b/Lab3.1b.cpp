#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Spec { KN, INF, MATHandECONOM, PHandINF, WORK };

string SpecStr[] = {
	"Комп.і науки",
	"Інформ.",
	"Матем. та еконо.",
	"Фіз. та інформ.",
	"Труд. навчання"
 };


enum Kurs { I = 1, II, III, IV, V, VI };

string KursStr[] = {
	"I", "II", "III", "IV", "V", "VI"
};

struct Student {
	string prizv;
	Kurs kurs;
	Spec spec;
	int physics, maths;
	union {
		int programming;
		int numMethods;
		int pedagogy;
	};
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


void Create(Student* s, const int N) {
	int kurs, spec;
	for (int i = 0; i < N; i++) {
		cout << "Студент № " << i + 1 << ":" << endl;
		cout << "Прізвище: "; cin >> s[i].prizv;
		cout << "Курс: "; cin >> kurs;
		s[i].kurs = (Kurs)kurs;
		cout << "Спеціальність: 0 - Комп’ютерні науки,  1 - Інформатика, \n 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання"
			<< endl << "Введіть спеціальність: ";
		cin >> spec;        s[i].spec = (Spec)spec;
		cout << "Оцінка з фізики: "; cin >> s[i].physics;
		cout << "Оцінка з математики: "; cin >> s[i].maths;
		switch (s[i].spec) {
		case KN:
			cout << "Оцінка з програмування:"; cin >> s[i].programming;
			break;
		case INF:
			cout << "Оцінка з чисельних методів:"; cin >> s[i].numMethods;
			break;
		case MATHandECONOM:
		case PHandINF:
		case WORK:
			cout << "Оцінка з педагогіки:"; cin >> s[i].pedagogy;
			break;
		}
		cout << endl;
	}
}

void Print(Student* s, const int N) {
	cout << "==================================================================================================="
		<< endl;
	cout << "| № |  Прізвище  | Курс |   Спеціальність   | Фізика | Матем. | Програм. | Чис. мет. | Педагогіка |"
		<< endl;
	cout << "---------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << right << i + 1 << " ";
		cout << "| " << setw(11) << left << s[i].prizv
			<< "| " << setw(4) << right << KursStr[(int)s[i].kurs - 1] << " "
			<< "| " << setw(18) << left << SpecStr[s[i].spec]
			<< "| " << setw(6) << right << s[i].physics << " "
			<< "| " << setw(6) << right << s[i].maths << " ";
		switch (s[i].spec) {
		case KN:
			cout << "| " << setw(8) << right
				<< s[i].programming << " | " << setw(12) << right
				<< " | " << setw(12) << right << " |" << endl;
			break;
		case INF:
			cout << "| " << setw(11) << right
				<< " | " << setw(9) << right << s[i].numMethods
				<< " | " << setw(12) << right << " |" << endl;
			break;
		case MATHandECONOM:
		case PHandINF:
		case WORK:
			cout << "| " << setw(11) << right
				<< " | " << setw(12) << right
				<< " | " << setw(10) << right << s[i].pedagogy << " |" << endl;
			break;
		}
	}
	cout << "===================================================================================================" << endl;
	cout << endl;
}

int Count(Student* s, const int n)
{
	double d;
	int  counter = 0;
	for (int i = 0; i < n; i++)
	{
			d = (s[i].physics + s[i].maths + s[i].programming) / 3.;
			if (d > 4.5)
				counter++;
	}
	return counter;
}

string Highest(Student* s, const int N)
{
	double prog = 0, math = 0, phys = 0;
	double P, M, F;

	for (int i = 0; i < N; i++)
	{
		math += s[i].maths;
		phys += s[i].physics;
		prog += s[i].programming;
	}

	P = prog / N;
	M = math / N;
	F = phys / N;

	if (F == M && M == P)
		return "Всі предмети мають одинаковий середній бал";
	if (F == M || M == P || P == F)
		return "Два предмети мають одинаковий середній бал";
	if (F >= (M + P ) / 2.)
		return "physics";
	if (M >= (P + F ) / 2.)
		return "math";
	if (P >= (M + F ) / 2.)
		return "programming";
}


