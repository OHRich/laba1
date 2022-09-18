// lb1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <iostream>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int** a, temp, min, max, res, n, m, sum;
    srand(time(NULL));
    cout << "Введите количество строк: ";
    cin >> n;
    cout << "Введите количество столбцов: ";
    cin >> m;
    a = (int**)malloc(n * sizeof(int*)); //выделяем память под строку указателей

    //for (int i = 0; i < n; i++) {
    //    *(a + i) = (int*)malloc(m * sizeof(int)); //выделяем память под значения столбцов
    //}

    for (int i = 0; i < n; i++)  // цикл по столбцам
    {
        *(a + i) = (int*)malloc(m * sizeof(int)); //выделяем память под значения столбцов
        for (int j = 0; j < m; j++)  // цикл по строкам
        {
            *(*(a + i) + j) = rand() % 100;
            cout.width(3);
            cout << *(*(a + i) + j);
        }
        cout << endl;
    }
    min = **a;
    max = **a;
    cout << "\nСуммы строк: " << endl;
    for (int i = 0; i < n; i++)  // цикл по столбцам
    {
        sum = 0;
        for (int j = 0; j < m; j++)  // цикл по строкам
        {
            temp = *(*(a + i) + j);
            sum = sum + temp;
            if (temp < min) {
                min = temp;
            }
            if (temp > max) {
                max = temp;
            }
        }
        cout << sum << endl;
    }
    cout << "\nСумма стобцов: " << endl;
    for (int j = 0; j < m; j++)  // цикл по строкам
    {
        sum = 0;
        for (int i = 0; i < n; i++)  // цикл по столбцам
        {
            temp = *(*(a + i) + j);
            sum = sum + temp;
            if (temp < min) {
                min = temp;
            }
            if (temp > max) {
                max = temp;
            }
        }
        cout << sum << endl;
    }
    res = max - min;
    cout << "\nРазница между максимальным и минимальным элементом массива: " << max << "-" << min << "=" << res << endl;
    for (int i = 0; i < n; i++) {
        free(*(a + i)); //освобождаем память
    }
    free(a); //освобождаем память
}