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

struct Zodiac
{
    string surname;
    string name;
    string zodiac_sign;
    int date[3];
};

void Create(Zodiac* S, const int N);
void Print(Zodiac* S, const int N);
void Sort(Zodiac* S, const int N);
int Search(Zodiac* S, const int N, const string);
void SaveToFile(Zodiac* p, const int N, const char* filename);
void LoadFromFile(Zodiac*& p, int& N, const char* filename);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість людей: "; cin >> N;

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
            Create(S, N);
            break;
        case 2:
            Print(S, N);
            break;
        case 3:
            Sort(S, N);
            Print(S, N);
            break;
        case 4:
            cout << "Введіть знак зодіаку: " << endl;
            cin.get();
            cin.sync();
            getline(cin, f_zod); cout << endl;
            Search(S, N, f_zod);
            break;
        case 5:
            cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
            cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

            cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
            SaveToFile(S, N, filename);
            break;
        case 6:
            cin.get();
            cin.sync(); 

            cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
            LoadFromFile(S, N, filename);
            break;
        }
        

        if (MenuItem == 0) break;
    }

    return 0;
}

void Create(Zodiac* S, const int N)
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
            cout << "День народження: "; cin >> S[i].date[0];
        } while (S[i].date[0] < 1 || S[i].date[0] > 31);

        do
        {
            cout << "Місяць народження: "; cin >> S[i].date[1];
        } while (S[i].date[1] < 1 || S[i].date[1] > 12);

        cout << "Рік народження: "; cin >> S[i].date[2];

        cout << endl;
    }
}

void Print(Zodiac* S, const int N)
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
        cout << "|" << setw(6) << S[i].date[0] << setw(12);
        cout << "|" << setw(6) << S[i].date[1] << setw(6);
        cout << "|" << setw(10) << S[i].date[2] << setw(6) << "|" << endl;
    }
    cout << "=========================================================================================" << endl << endl;
}

void Sort(Zodiac* S, int N) {
    Zodiac tmp;
    for (int i = 0; i < N; i++)
    {
        for (int i0 = 0; i0 < N - 1; i0++) // метод "бульбашки"
            for (int i1 = 0; i1 < N - i0 - 1; i1++)
                if ((S[i1].surname > S[i1 + 1].surname))
                {
                    tmp = S[i1];
                    S[i1] = S[i1 + 1];
                    S[i1 + 1] = tmp;
                }
    }
}




int Search(Zodiac* S, const int N, const string f_zod)
{
    string zod;
    int flag = 0;
    cout << "=========================================================================================" << endl;
    cout << "|  №  |  Прізвище  | Імя | Знак зодіаку  |  День народження  |  Місяць  |  Рік          |" << endl;
    for (int i = 0; i < N; i++) {
        if (S[i].zodiac_sign == f_zod)
        {
            flag = 1;
           
            cout << "-----------------------------------------------------------------------------------------" << endl;
            cout << "|" << setw(3) << i + 1 << setw(3);
            cout << "|" << setw(4) << S[i].surname << setw(8);
            cout << "|" << setw(6) << S[i].name << setw(3);
            cout << "|" << setw(6) << S[i].zodiac_sign << setw(6);
            cout << "|" << setw(6) << S[i].date[0] << setw(12);
            cout << "|" << setw(6) << S[i].date[1] << setw(6);
            cout << "|" << setw(10) << S[i].date[2] << setw(6) << "|" << endl;
            
        }
    }
    cout << "=========================================================================================" << endl << endl;
    if (!flag)
        cout << "Немає людей які народились під таким знаком зодіаку" << endl;
    return flag;
}

void SaveToFile(Zodiac* p, const int N, const char* filename)

{
    ofstream fout(filename, ios::binary); // відкрили бінарний файл запису
    fout.write((char*)&N, sizeof(N)); // записали кількість елементів
    for (int i = 0; i < N; i++)
    {
        fout.write((char*)&p[i], sizeof(Zodiac)); // записали елементи масиву
    }
    fout.close(); // закрили файл
}

void LoadFromFile(Zodiac*& p, int& N, const char* filename)
{
    delete[] p; // знищили попередні дані
    ifstream fin(filename, ios::binary); // відкрили бінарний файл зчитування
    fin.read((char*)&N, sizeof(N)); // прочитали кількість елементів
    p = new Zodiac[N]; // створили динамічний масив

    for (int i = 0; i < N; i++)
    {
        fin.read((char*)&p[i], sizeof(Zodiac)); // прочитали елементи масиву
    }                                           
    fin.close(); // закрили файл
}
