#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <windows.h> // Подключение библиотеки для работы с Windows API (нужно для установки кодировки UTF-8 в PowerShell или CMD)

using namespace std;

// Определяем тип для комплексных чисел
typedef complex<double> Complex;
typedef vector<Complex> CArray;

// Функция для выполнения БПФ
void fft(CArray &x) {
    int N = x.size();
    if (N <= 1) return; // Базовый случай

    // Разделяем массив на четные и нечетные элементы
    CArray even(N / 2), odd(N / 2);
    for (int i = 0; i < N / 2; ++i) {
        even[i] = x[i * 2];
        odd[i] = x[i * 2 + 1];
    }

    // Рекурсивно применяем БПФ к четным и нечетным частям
    fft(even);
    fft(odd);

    // Объединяем результаты
    for (int k = 0; k < N / 2; ++k) {
        Complex t = polar(1.0, -2 * M_PI * k / N) * odd[k]; // e^(-2πik/N)
        x[k] = even[k] + t; // Четные элементы
        x[k + N / 2] = even[k] - t; // Нечетные элементы
    }
}

// Функция для вычисления модуля спектра
vector<double> computeMagnitude(const CArray &x) {
    vector<double> magnitude(x.size());
    for (size_t i = 0; i < x.size(); ++i) {
        magnitude[i] = abs(x[i]); // Вычисляем модуль
    }
    return magnitude;
}

// Функция для вывода массива комплексных чисел
void printArray(const CArray &x) {
    for (const auto &c : x) {
        cout << c << " ";
    }
    cout << endl;
}

// Функция для вывода массива действительных чисел
void printMagnitude(const vector<double> &magnitude) {
    for (const auto &m : magnitude) {
        cout << m << " ";
    }
    cout << endl;
}

int main() {
    // Устанавливаем кодовую страницу консоли на UTF-8
    SetConsoleOutputCP(CP_UTF8);
    // Создаем массив комплексных чисел
    CArray data = {
        {0, 0}, {1, 0}, {2, 0}, {3, 0},
        {4, 0}, {5, 0}, {6, 0}, {7, 0}
    };

    cout << "Исходные данные:" << endl;
    printArray(data);

    // Применяем БПФ
    fft(data);

    cout << "Результат БПФ:" << endl;
    printArray(data);

    // Вычисляем и выводим модуль спектра
    vector<double> magnitude = computeMagnitude(data);
    cout << "Модуль спектра:" << endl;
    printMagnitude(magnitude);

    return 0;
}
