// Подключаем библиотеку iostream 
#include <iostream> 
#include <fstream> // Для работы с файлами. Комбинация ofstream и ifstream: создание, чтение и запись в файлы.
#include <chrono> // Для работы с датой
#include <ctime>  // Для работы с временем
#include <iomanip> //Используется для управления форматированием ввода и вывода.
#include <string>     //getline
#include <sstream>
#include <vector> // Для работы с векторами

// Подключаем пространство имен std 
using namespace std; 

struct CalcProblemParams
{
   string filePath1;
   string filePath2;
   enum class operations {vv_sum, vv_sub, vv_scMalt};
   operations op;
};

//Структура для хранения значений векторов и их размерностей:
struct VectorData {
    vector<double> values;
    int size;
};

struct ExportConfig {
    string path; // Путь к файлу
};

struct CalcResult {
    VectorData result; // Результат сложения векторов
};

int logAll(string data)
{
    ofstream logFile("log.txt", ios::app); // Открываем файл в режиме добавления
    if (!logFile) {
        return -1;
    }
    time_t t = time(0); // Получаю текущее время
    struct tm *now = localtime(&t); // Преобразую в локальное время

    // Записываем дату и время в файл
    logFile <<put_time(now, "%Y-%m-%d %H:%M:%S") << " - "; // Форматирую и записываем дату и время

    logFile << data << endl; // Записываю данные в файл
    logFile.close(); // Закрываю файл
    return 0; 
}

//Функция для чтения из файлов и проверки значений
VectorData readDataFromFile(const string& filepath) {
    string line;
    VectorData vectorData;
    ifstream dataFile(filepath); // Открываем файл в режиме чтения
    if (!dataFile) {
        logAll("Ошибка открытия файла");
        return vectorData; // Возвращаем пустой вектор
    }

    while (getline(dataFile, line)) {
        logAll(line);
        if (line == "vector") {
            logAll("В файле обнаружено значение vector");
            // Читаем размер вектора
            if (getline(dataFile, line)) {
                vectorData.size = stoi(line);
                vectorData.values.resize(vectorData.size);
                // Читаем значения вектора
                if (getline(dataFile, line)) {
                    /*Istringstream - это строковой поток ввода. Конструктор istringstream () со строковым аргументом прикрепляет создаваемый объект потока к указанной строке. То есть теперь информация будет считываться из стандартной строки точно таким же образом, как и из cin, объекта класса потока ввода istream.*/
                    istringstream iss(line);
                    for (int i = 0; i < vectorData.size; ++i) {
                        iss >> vectorData.values[i];
                    }
                }
            }
        }
    }
    dataFile.close(); // Закрываем файл
    return vectorData; 
}

// Функция для сложения двух векторов
VectorData Calck_vv_sum(const VectorData& vec1, const VectorData& vec2) {
    // Проверка на равенство размерностей
    if (vec1.size != vec2.size) {
        logAll("Ошибка! Размерность векторов не совпадает");
        return VectorData();
    }

    VectorData result; // Создаем объект для хранения результата сложения векторов
    result.size = vec1.size; // Устанавливаем размер результирующего вектора равным размеру первого вектора
    result.values.resize(result.size); // Изменяем размер массива значений результирующего вектора

    // Сложение векторов
    for (int i = 0; i < result.size; ++i) {
        result.values[i] = vec1.values[i] + vec2.values[i];
    }

    return result;
}

int Export(const ExportConfig& config, const CalcResult& calcResult) {
    // Создаю файл и открываю его на дозапись
    logAll("Открываю " +config.path);
    ofstream dataFile(config.path, ios::app); // Открываем файл в режиме добавления
    if (!dataFile) {
        logAll("Ошибка открытия файла: " + config.path);
        return -1;
    }

    // Записываем дату и время в файл
    dataFile << "Result: "; // Форматирую и записываем дату и время

    // Записываем данные в файл
    for (const auto& value : calcResult.result.values) {
        dataFile << value << " "; // Записываем значения вектора
    }
    dataFile << endl; // Переход на новую строку
    dataFile.close(); // Закрываю файл
    return 0; 
}

int main(int argc, char* argv[]) 
{ 
    VectorData vector1, vector2;
    CalcProblemParams calcParams;
    CalcResult calcResult; // Создаем объект для хранения результата
    
    for (int i = 1; i < argc; i++) {
    if (string(argv[i]) == "--fp1") {
        if (i + 1 < argc) { // Проверка границ
            calcParams.filePath1 = argv[i + 1];
            logAll("Путь к файлу 1: " + calcParams.filePath1);
            vector1 = readDataFromFile(calcParams.filePath1);
        }
    } else if (string(argv[i]) == "--fp2") {
        if (i + 1 < argc) { // Проверка границ
            calcParams.filePath2 = argv[i + 1];
            logAll("Путь к файлу 2: " + calcParams.filePath2);
            vector2 = readDataFromFile(calcParams.filePath2);
        }
    } else if (string(argv[i]) == "--op") {
        if (i + 1 < argc) { // Проверка границ
            string operation = argv[i + 1];
            logAll("Операция: " + operation);
            if (operation == "vv_sum") {
                calcParams.op = CalcProblemParams::operations::vv_sum;
                logAll("Вызвана операция: суммирование векторов");
                // Сложение векторов
                calcResult.result = Calck_vv_sum(vector1, vector2); // Сохраняем результат
                if (calcResult.result.size > 0) {
                    cout << "Resulting vector: ";
                    for (const auto& value : calcResult.result.values) {
                        cout << value << " ";
                    }
                    cout << endl;
                }
            } else if (operation == "vv_sub") {
                calcParams.op = CalcProblemParams::operations::vv_sub;
                logAll("Вызвана операция: вычитание векторов");
            } else if (operation == "vv_scMalt") {
                calcParams.op = CalcProblemParams::operations::vv_scMalt;
                logAll("Вызвана операция: переумножение векторов");
            } else {
                logAll("Ошибка: неизвестная операция");
            }
        } else {
            logAll("Ошибка: нет аргументов после --op");
        }
    } else if (string(argv[i]) == "--exp") {
        if (i + 1 < argc) { // Проверка границ
            ExportConfig conf;
            conf.path = argv[i + 1]; // Сохраняем путь к файлу
            logAll("Путь и имя выходного файла: " + conf.path);
            // Вызов функции Export с нужными аргументами
            int exportResult = Export(conf, calcResult);
            if (exportResult != 0) {
                logAll("Ошибка при экспорте данных");
            }
        } else {
            logAll("Ошибка: нет аргументов после --exp");
        }
    }
}
    return 0;
}
//g++ 1.cpp -o app