# Сборник учебных проектов на C++  

## Краткое описание:  
В корне каталога ALG-1-GITHUB-REPO содержатся файлы:  
1.txt  
1.cpp  
LICENSE - файл с лицензией на ПО, данном случае MIT  
app.exe - исполняемый файл  
Данные относятся к самой первой работе, в которой мы учились работать с Git.  
1.cpp просто выводит Hello world в консоль.  

Папка Rabota_2 содержит файлы:  
1.cpp - файл с кодом  
activity-1.puml - представление алгоритма в формате UML  
app.exe - исполняемый файл  
В папке diagrams содержатся файлы диаграммы.  
В данной работе мы учились работать с условными конструкциями.  

Папка Rabota_3 содержит файлы:  
1.cpp - файл с кодом  
app.exe - исполняемый файл  
log.txt - файл с логами программы, перезаписывается при запуске программы  
mat1.txt - в данном файле находятся начальные значения для матрицы 1  
mat2.txt - в данном файле находятся начальные значения для матрицы 2  
sub_data.txt - тут находится результат вычитания векторов  
matrix_sum_res.txt - тут находится результат суммирования матриц  
sum_data.txt - тут находится результат суммирования векторов  
vec1.txt - в данном файле находятся начальные значения для вектора 1  
vec2.txt - в данном файле находятся начальные значения для вектора 2  
В папке diagrams находятся схемы UML для визуализации алгоритмов  
В данном проекте реализованы алгоритмы для сложения и вычитания векторов, а также для сложения матриц.  
Программа консольная, выбор операций осуществляется с помощью аргументов командной строки.  
Пример суммирования векторов: ```./app --fp1 vec1.txt --fp2 vec2.txt --op vv_sum --exp sum_data.txt```  
Пример вычитания векторов: ```./app --fp1 vec1.txt --fp2 vec2.txt --op vv_sub --exp sub_data.txt```  
Пример сложения матриц: ```./app --matrix_fp1 mat1.txt --matrix_fp2 mat2.txt --op mm_sum --exp matrix_sum_res.txt```  

В папке Graph содержатся файлы:  
graph.cpp - файл с кодом, в котором реализовано ООП представления графа, а также алгоритмы поиска в Глубину и Дейкстры.  
graph.exe - исполняемый файл  
vershina.txt - это файл, в котором находятся начальные значения для работы с графами. Первая строка задаёт вершину для начала обхода. Вторая строка используется для указания окончания графа, третья строка используется для алгоритма Дийкстры.  

В папке SLAU содержатся файлы:  
app.exe - исполняемый файл  
slau.cpp - файл с исходным кодом. В нем реализован алгоритм решения СЛАУ.  
tempr.txt - файл, который содержит температуру  
res.txt - хранит в себе вводимые значения  
oopslau и файлы, которые начинаются с oop - это ООП реализация алгоритма.  

В папке Thread содержатся файлы:  
app.exe - исполняемый файл  
thread.cpp - это файл с кодом с примерами реализации многопоточности.   
thread_task.cpp - задача расчёта множества векторов используя многопоточность  

В папке Pointers находятся два файла:  
app.exe - исполняемый файл
Pointers.cpp - файл с кодом  
Это дополнительный проект для изучения указателей.  

В папке out находятся диаграммы UML; данная папка создаётся автоматически при сохранении диаграмм из PlantUML в различные форматы, например SVG.  

В папке FFT содержатся файлы:  
FFT.cpp - файл с кодом, в котором реализованы алгоритмы быстрого преобразования Фурье и функция вычисления модуля спектра.  
app.exe - исполняемый файл  
Быстрое преобразование Фурье (БПФ, FFT) — алгоритм вычисления дискретного преобразования Фурье (ДПФ). То есть, алгоритм вычисления за количество действий, меньшее чем 𝑂(𝑁^2), требуемых для прямого (по формуле) вычисления ДПФ. Иногда под БПФ понимается один из быстрых алгоритмов, называемый алгоритмом прореживания по частоте/времени или алгоритмом по основанию 2, имеющий сложность𝑂(𝑁log⁡(𝑁)).  

## Использование:  
1. Скачать компилятор g++: https://github.com/brechtsanders/winlibs_mingw/releases/download/14.2.0posix-18.1.8-12.0.0-ucrt-r1/winlibs-x86_64-posix-seh-gcc-14.2.0-llvm-18.1.8-mingw-w64ucrt-12.0.0-r1.zip
2. Распаковать архив в корень любого логического диска и и добавить исполняемые файлы в системную переменную PATH, пример: C:\mingw64\bin.  
3. Проверить установку можно командой: ```g++ --version``` в CMD. Если выводится текст:  
g++ (MinGW-W64 x86_64-ucrt-posix-seh, built by Brecht Sanders, r1) 14.2.0  
Copyright (C) 2024 Free Software Foundation, Inc.  
This is free software; see the source for copying conditions.  There is NO  
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
Значит установка прошла успешно и можно начинать работу.
4. Установить редактор кода MS Visual Studio Code: https://code.visualstudio.com/Download
5. Клонировать репозиторий: ```git clone https://github.com/IgorPISH/alg-1-github-repo.git```  
6. Открыть папку alg-1-github-repo в Visual Studio Code и перейти к интересующей работе.  
7. Для получения обновлений из удалённого репозитория используется команда: ```git pull```  

## Компиляция и запуск программы  
1. Перейти в нужную директорию командой ```cd``` пример: ```cd Rabota_3```  
2. Создание исполняемого файла осуществляется командой: ```g++ 1.cpp -o app```.  
Первый аргумент: название файл с кодом (в данном случае 1.cpp);  
Второй аргумент ```-o``` - указывает компилятору, что нужно создать 1 испоняемый файл;  
Третий аргумент ```app``` - задаёт название исполняемого файла (в данном случае app);  
3. Запуск программы осуществляется командой: ```./app``` для PowerShell или ```app``` в CMD  