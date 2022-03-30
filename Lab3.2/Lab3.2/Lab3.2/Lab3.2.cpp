/*
Сформувати масив структур, що містять інформацію про : прізвище
студента, курс, спеціальність(для представлення спеціальності використовувати переліки, а
	для представлення курсу – цілі числа) та оцінки з фізики, математики, інформатики

Варіант 16.
1. Програма має дати користувачеві можливість фізично впорядкувати масив в першу
чергу – за значенням середнього балу, в другу чергу (для однакових середніх балів) –
за значенням оцінки з третього предмету, в останню чергу (для однакових середніх
балів і оцінок з третього предмету) – за прізвищем за спаданням – в зворотному до
алфавітного порядку.
2. Програма має будувати індексний масив, який забезпечує наступне індексне
впорядкування: в першу чергу – за значенням середнього балу, в другу чергу (для
однакових середніх балів) – за значенням оцінки з третього предмету, в останню
чергу (для однакових середніх балів і оцінок з третього предмету) – за прізвищем.
3. За допомогою бінарного пошуку визначити, чи навчається студент із вказаним
користувачем прізвищем та з вказаним середнім балом і вказаною оцінкою з третього
предмету.
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
	string prizv;
	unsigned kurs;
	Specilnist spec;
	int Physical;
	int Math;
	int Informatik;
};


void Create(Student* s, const int N);
void Print(Student* s, const int N);
double SearchStudentAverageScoreAbove(Student* s, const int N);
double SearchPredmetAverageScoreHighest(Student* s, const int N);
void Sort(Student* s, const int N);
int* IndexSort(Student* s, const int N);
void PrintIndexSorted(Student* s, int* I, const int N);
int BinSearch(Student* s, const int N, const string prizv, const double serb, const double otsi);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть кількість студентів: "; cin >> N;

	Student* s = new Student[N];

	string prizv;
	unsigned kurs;
	Specilnist spec;
	int Physical;
	int Math;
	int Informatik;

	int found;
	double otsi, serb;

	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " 1 - введення даних з клавіатури" << endl;
		cout << " 2 - вивід даних на екран" << endl;
		cout << " 3 - вивід прізвище студента, у якого найбільший середній бал" << endl;
		cout << " 4 - вивід найбільший середній бал предмета" << endl;
		cout << " 5 - фізичне впорядкування даних" << endl;
		cout << " 6 - бінарний пошук студент за прізвищем, середнім балом і оцінкою з третього предмета" << endl;
		cout << " 7 - індексне впорядкування та вивід даних" << endl;
		cout << " 0 - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(s, N);
			break;
		case 2:
			Print(s, N);
			break;
		case 3:
			cout << SearchStudentAverageScoreAbove(s, N)<< endl;
			break;
		case 4:
			cout << SearchPredmetAverageScoreHighest(s, N) << endl;
			break;
		case 5:
			Sort(s, N);
			Print(s, N);
			break;
		case 6:
			cout << "Введіть ключі пошуку:" << endl;
			cout << " Прізвище: "; cin >> prizv;
			cout << " Середній бал: "; cin >> serb;
			cout << " Оцінка третього предмету: "; cin >> otsi;
			if ((found = BinSearch(s, N, prizv, serb, otsi)) != -1)
				cout << "Студент навчається під номером - " << found + 1 << endl;
			else
				cout << "Не знайдено" << endl;
			break;
		case 7:
			PrintIndexSorted(s, IndexSort(s, N), N);
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);

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
		cout << " прізвище та ім'я: "; getline(cin, s[i].prizv);
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
		cout << "| " << setw(20) << left << s[i].prizv << "| " << setw(4) << right << s[i].kurs << " ";
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

double SearchStudentAverageScoreAbove(Student* s, int n)
{
	int  counter = 0;
	for (int i = 0; i < n; i++)
	{
		double d = s[i].Informatik + s[i].Math + s[i].Physical;
		double dd = d / 3;
		if (dd > 4.5) {
			counter++;
		}
	}

	if (counter != 0)
	{
		cout << "Кількість студентів з середнім балом вище 4.5 - " << counter << endl;
	}
	else
	{
		cout << endl << "Немає студентів з балом вище 4.5" << endl;
	}
	cout << endl;

	return 0;
}

/*
Порівнюючи середні бали для кожного предмету, визначити предмет, середній бал якого найбільший.
*/

double SearchPredmetAverageScoreHighest(Student* s, const int N)
{
	double inf = 0, math = 0, phys = 0;
	double serInf, serMat, serPhy;
	for (int i = 0; i < N; i++)
	{
		inf += s[i].Informatik;
		math += s[i].Math;
		phys += s[i].Physical;
	}

	serInf = inf / N;
	serMat = math / N;
	serPhy = phys / N;

	if (serInf > serMat && serInf > serPhy)
		cout << "Informatik - " << serInf << endl;
	else
		if (serMat > serInf && serMat > serPhy)
			cout << "Math - " << serMat << endl;
		else
			if (serPhy > serInf && serPhy > serMat)
				cout << "Physic - " << serPhy << endl;
			else
				if (serInf == serMat && serMat == serPhy)
					cout << "Всі бали одинакові" << endl;
				else
					cout << "..." << endl;
	return 0;
}

/*
1. Програма має дати користувачеві можливість фізично впорядкувати масив в першу
чергу – за значенням середнього балу, в другу чергу (для однакових середніх балів) –
за значенням оцінки з третього предмету, в останню чергу (для однакових середніх
балів і оцінок з третього предмету) – за прізвищем за спаданням – в зворотному до
алфавітного порядку.
*/

void Sort(Student* s, const int N)
{
		Student tmp;
		for (int i = 0; i < N - 1; i++) // метод "бульбашки"
			for (int j = 0; j < N - i - 1; j++)
				if (((s[j].Informatik + s[j].Math + s[j].Physical) / 3) > ((s[j + 1].Informatik + s[j + 1].Math + s[j + 1].Physical) / 3)
					||
					(((s[j].Informatik + s[j].Math + s[j].Physical) / 3) == ((s[j + 1].Informatik + s[j + 1].Math + s[j + 1].Physical) / 3) &&
						s[j].Informatik > s[j + 1].Informatik)
					||
					((((s[j].Informatik + s[j].Math + s[j].Physical) / 3) == ((s[j + 1].Informatik + s[j + 1].Math + s[j + 1].Physical) / 3) &&
						s[j].Informatik == s[j + 1].Informatik) &&
						s[j].prizv < s[j + 1].prizv))
				{
					tmp = s[j];
					s[j] = s[j + 1];
					s[j + 1] = tmp;
				}
}

/*
2. Програма має будувати індексний масив, який забезпечує наступне індексне
впорядкування: в першу чергу – за значенням середнього балу, в другу чергу (для
однакових середніх балів) – за значенням оцінки з третього предмету, в останню
чергу (для однакових середніх балів і оцінок з третього предмету) – за прізвищем.
*/

int* IndexSort(Student* s, const int N) {
	int* I = new int[N]; // створили індексний масив
	for (int i = 0; i < N; i++)
		I[i] = i; // заповнили його початковими даними
	int i, j, value; // починаємо сортувати масив індексів

	for (i = 1; i < N; i++)
	{
		value = I[i];
		for (j = i - 1;
			j >= 0 && ((((s[I[j]].Informatik + s[I[j]].Math + s[I[j]].Physical) / 3) > ((s[value].Informatik + s[value].Math + s[value].Physical) / 3))
				||
				(((s[I[j]].Informatik + s[I[j]].Math + s[I[j]].Physical) / 3) == ((s[value].Informatik + s[value].Math + s[value].Physical) / 3) &&
					s[I[j]].Informatik > s[value].Informatik)
				||
				(((s[I[j]].Informatik + s[I[j]].Math + s[I[j]].Physical) / 3) == ((s[value].Informatik + s[value].Math + s[value].Physical) / 3) &&
					s[I[j]].Informatik == s[value].Informatik &&
					s[I[j]].prizv > s[value].prizv));
			j--)
		{
			I[j + 1] = I[j];
		}
		I[j + 1] = value;
	}

	
	return I;
}

void PrintIndexSorted(Student* s, int* I, const int N) {
	cout << "======================================================================================="
		<< endl;
	cout << "| № |      Прізвище       | Курс | Спеціальність | Фізика | Математика | Інфортматика | "
		<< endl;
	cout << "---------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(20) << left << s[i].prizv << "| " << setw(4) << right << s[i].kurs << " ";
		cout << "| " << setw(8) << right << predmetStr[s[i].spec] << " |";
		cout << "| " << setw(6) << setprecision(2) << fixed << right << s[i].Physical << right << " |";
		cout << " " << setw(10) << right << s[i].Math << " |";
		cout << " " << setw(12) << right << s[i].Informatik << " |" << endl;

	}
	cout << "=======================================================================================" << endl;
	cout << endl;
}

/*
3. За допомогою бінарного пошуку визначити, чи навчається студент із вказаним
користувачем прізвищем та з вказаним середнім балом і вказаною оцінкою з третього
предмету.
*/

int BinSearch(Student* s, const int N, const string prizv, const double serb, const double otsi)
{ // повертає індекс знайденого елемента або -1, якщо шуканий елемент відсутній 
	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		if (s[m].prizv == prizv && ((s[m].Informatik + s[m].Math + s[m].Physical) / 3) == serb && s[m].spec == otsi)
			return m;
		if ((((s[m].Informatik + s[m].Math + s[m].Physical) / 3) < serb)
			||
			(((s[m].Informatik + s[m].Math + s[m].Physical) / 3) == serb &&
				s[m].prizv < prizv)
			||
			(((s[m].Informatik + s[m].Math + s[m].Physical) / 3) == serb &&
				s[m].prizv == prizv &&
				s[m].Informatik < otsi))
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;
}