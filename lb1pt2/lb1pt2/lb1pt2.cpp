// lb1pt2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int sravnstr(char str1[20], char str2[20]) {
    for (int i = 0; i < 20; i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    return 1;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    system("cls");
    struct student
    {
        char name[20], surname[20], facult[20];
        int nomzach;
    } students[5];
    char fam[20], nam[20], flag = 0;
    for (int i = 0; i < 5; i++) {
        cout << "Введите фамилию студента: ";
        cin >> students[i].surname;
        cout << "Введите имя студента: ";
        cin >> students[i].name;
        cout << "Введите факультет: ";
        cin >> students[i].facult;
        cout << "Введите номер зачётки: ";
        cin >> students[i].nomzach;
        cout << endl;
    }
    cout << endl << "Введите фамилию студента для поиска: ";
    cin >> fam;
    cout << endl << "Введите имя студента для поиска: ";
    cin >> nam;
    for (int i = 0; i < 5; i++) {
        if (sravnstr(students[i].name, nam) && sravnstr(students[i].surname, fam)) {
            cout << endl << students[i].surname << " " << students[i].name << " " << students[i].facult << " " << students[i].nomzach;
            flag = 1;
        }
    }
    if (flag == 0) {
        cout << "Ничего не найдено";
    }
}