// Lab10.1(Rekurs).cpp 
// Михайлов Олександр
// Пошук та заміна символів у літерному рядку
// Варіант 24

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>

using namespace std;

int Count(char* str, int i)
{
    if (sizeof(str) < 3)
        return 0;
    if (str[i + 1] != 0)
        if (str[i - 1] == 'a' && str[i] == 'b' && str[i + 1] == 'c')
            return 1 + Count(str, i + 1);
        else
            return Count(str, i + 1);
    else
        return 0;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FILE* f;

    f = fopen("t.txt", "r");

    if (f == NULL)
    {
        cerr << "Помилка при відкритті файлу.\n";
        exit(1);
    }

    char tchar[100];

    fgets(tchar, 100, f);

    if (Count(tchar, 1) == 1) {
        cout << endl << "String contained " << Count(tchar, 1) << " group of 'abc'." << endl;
    }
    else {
        cout << endl << "String contained " << Count(tchar, 1) << " groups of 'abc'." << endl;
    }

    fclose(f);

    return 0;
}