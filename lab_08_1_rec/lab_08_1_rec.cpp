#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>

using namespace std;

// i - позиція першого символу групи з трьох (початково 0)
int Count(const char* str, int i)
{
    if (str[i] == '\0' || str[i + 1] == '\0' || str[i + 2] == '\0')
        return 0;                               // група з трьох символів уже не вміщається

    if (str[i] == ',' && str[i + 2] == '-')
        return 1 + Count(str, i + 1);
    else
        return     Count(str, i + 1);
}

// i - позиція у старому рядку str, j - позиція у новому рядку dest
char* Change(char* dest, const char* str, int i, int j)
{
    if (str[i] == '\0')                         // дійшли до кінця старого рядка
    {
        dest[j] = '\0';
        return dest;
    }

    if (str[i] == ',' && str[i + 1] != '\0' && str[i + 2] == '-')
    {
        dest[j] = '*';
        dest[j + 1] = '*';
        return Change(dest, str, i + 3, j + 2); // стрибаємо через групу
    }
    else
    {
        dest[j] = str[i];
        return Change(dest, str, i + 1, j + 1);
    }
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int k = Count(str, 0);
    if (k > 0)
        cout << "String contained " << k << " groups of ', -'" << endl;
    else
        cout << "String contained no groups of ', -'" << endl;

    char* dest1 = new char[strlen(str) + 1];
    dest1[0] = '\0';

    char* dest2 = Change(dest1, str, 0, 0);

    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;

    delete[] dest1;
    return 0;
}