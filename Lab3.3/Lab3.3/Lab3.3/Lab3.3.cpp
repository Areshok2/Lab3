/*
Варіант 16.
Описати структуру з іменем Zodiac, що містить наступні поля :
 прізвище, ім’я;
 знак Зодіаку;
 день народження(масив з трьох чисел).

Написати програму, що виконує наступні дії :
 введення даних з клавіатури в масив, що складається з елементів типу Zodiас;
 впорядкування масиву структур за прізвищами(в алфавітному порядку).
 вивід на екран інформації про людей, що народилися під знаком, найменування
якого введене з клавіатури; якщо таких немає, вивести на екран відповідне
повідомлення.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

struct Bday
{
    int day;
    int month;
    int year;
};

struct Zodiac
{
    string surname;
    string name;
    string zodiac_sign;
};

void Create(Zodiac* S, Bday* B, const int N);
void Print(Zodiac* S, Bday* B, const int N);
void sort(Zodiac* S, Bday* B, const int N);
void search(Zodiac* S, Bday* B, const int N, const string);
void SaveToFile(Zodiac* p, Bday* B, const int N, const char* filename);
void LoadFromFile(Zodiac*& p, Bday*& B, int& N, const char* filename);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість людей: "; cin >> N;

    Bday* B = new Bday[3];
    Zodiac* S = new Zodiac[N];

    char filename[100];
    string f_zod;

    int MenuItem;

    while (true)
    {
        cout << endl << endl << endl;
        cout << "Виберіть дію:" << endl;
        cout << "1 - введення даних з клавіатури" << endl;
        cout << "2 - вивід даних на екран" << endl;
        cout << "3 - сортування за прізвищем" << endl;
        cout << "4 - інформація про людину" << endl;
        cout << "5 - запис у файл" << endl;
        cout << "6 - зчитування з файлу" << endl;
        cout << "0 - вихід та завершення роботи програми" << endl;
        cout << "Введіть значення: "; cin >> MenuItem; cout << endl;

        switch (MenuItem)
        {
        case 1:
            Create(S, B, N);
            break;
        case 2:
            Print(S, B, N);
            break;
        case 3:
            sort(S, B, N);
            Print(S, B, N);
            break;
        case 4:
            cout << "Введіть знак зодіаку: " << endl;
            cin.get();
            cin.sync();
            getline(cin, f_zod); cout << endl;
            search(S, B, N, f_zod);
            break;
        case 5:
            cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
            cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

            cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
            SaveToFile(S, B, N, filename);
            break;
        case 6:
            cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
            cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

            cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
            LoadFromFile(S, B, N, filename);
            break;
        }
        

        if (MenuItem == 0) break;
    }

    return 0;
}

void Create(Zodiac* S, Bday* B, const int N)
{
    for (int i = 0; i < N; i++)
    {

        int speciality;
        cout << "Особа: " << i + 1 << endl;
        cin.get();
        cin.sync();
        cout << "Прізвище: "; getline(cin, S[i].surname); 
        cout << "Імя: "; getline(cin, S[i].name);
        cout << "Знак зодіаку: "; getline(cin, S[i].zodiac_sign);
        do
        {
            cout << "День народження: "; cin >> B[i].day;
        } while (B[i].day < 1 || B[i].day > 31);

        do
        {
            cout << "Місяць народження: "; cin >> B[i].month;
        } while (B[i].month < 1 || B[i].month > 12);

        cout << "Рік народження: "; cin >> B[i].year;

        cout << endl;
    }
}

void Print(Zodiac* S, Bday* B, const int N)
{
    cout << "=========================================================================================" << endl;
    cout << "|  №  |  Прізвище  | Імя | Знак зодіаку  |  День народження  |  Місяць  |  Рік          |" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(3) << i + 1 << setw(3);
        cout << "|" << setw(4) << S[i].surname << setw(8);
        cout << "|" << setw(6) << S[i].name << setw(3);
        cout << "|" << setw(6) << S[i].zodiac_sign << setw(6);
        cout << "|" << setw(6) << B[i].day << setw(12);
        cout << "|" << setw(6) << B[i].month << setw(6);
        cout << "|" << setw(10) << B[i].year << setw(6) << "|" << endl;
    }
    cout << "=========================================================================================" << endl << endl;
}
void sort(Zodiac* S, Bday* B, int N)
{
    Zodiac temp;
    Bday btemp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if ((S[j].surname > S[j + 1].surname)
                ||
                (S[j].surname == S[j + 1].surname))
            {
                temp = S[j];
                S[j] = S[j + 1];
                S[j + 1] = temp;

                btemp = B[j];
                B[j] = B[j + 1];
                B[j + 1] = btemp;
            }

        }
    }
}

void search(Zodiac* S, Bday* B, const int N, const string f_zod)
{
    int flag = 0;
    for (int i = 0; i < N; i++) {
        if (S[i].zodiac_sign == f_zod)
        {
            flag = 1;
            cout << "=========================================================================================" << endl;
            cout << "|  №  |  Прізвище  | Імя | Знак зодіаку  |  День народження  |  Місяць  |  Рік          |" << endl;
            cout << "-----------------------------------------------------------------------------------------" << endl;
            cout << "|" << setw(3) << i + 1 << setw(3);
            cout << "|" << setw(4) << S[i].surname << setw(8);
            cout << "|" << setw(6) << S[i].name << setw(3);
            cout << "|" << setw(6) << S[i].zodiac_sign << setw(6);
            cout << "|" << setw(6) << B[i].day << setw(12);
            cout << "|" << setw(6) << B[i].month << setw(6);
            cout << "|" << setw(10) << B[i].year << setw(6) << "|" << endl;
            cout << "=========================================================================================" << endl << endl;
        }
    }
    if (!flag)
        cout << "Немає людей які народились під таким знаком зодіаку" << endl;
}

void SaveToFile(Zodiac* p, Bday* b , const int N, const char* filename)

{
    ofstream fout(filename, ios::binary); // відкрили бінарний файл запису
    fout.write((char*)&N, sizeof(N)); // записали кількість елементів
    for (int i = 0; i < N; i++)
    {
        fout.write((char*)&p[i], sizeof(Zodiac)); // записали елементи масиву
        fout.write((char*)&b[i], sizeof(Bday));
    }
    fout.close(); // закрили файл
}

void LoadFromFile(Zodiac*& p, Bday*& b , int& N, const char* filename)
{
    delete[] p; // знищили попередні дані
    ifstream fin(filename, ios::binary); // відкрили бінарний файл зчитування
    fin.read((char*)&N, sizeof(N)); // прочитали кількість елементів
    p = new Zodiac[N]; // створили динамічний масив
    b = new Bday[N]; // створили динамічний масив
    for (int i = 0; i < N; i++)
    {
        fin.read((char*)&p[i], sizeof(Zodiac)); // прочитали елементи масиву
        fin.read((char*)&b[i], sizeof(Bday));
    }                                           
    fin.close(); // закрили файл
}
