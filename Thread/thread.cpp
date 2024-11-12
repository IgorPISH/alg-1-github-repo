#include <thread> // Для работы с патоками
#include <iostream>
#include <vector>
#include <mutex> //Для работы с блокировками (для предотвращения состояния гонки)

using namespace std;

mutex coutMutex; // Глобальный объект блокировки

//Все параметры, передаваемые в конструктор копируются
void print_hello(double a)
{
    //Добавил блокировку
    coutMutex.lock();
    //Выводим ID потока
    auto id=std::this_thread::get_id();
    a += static_cast<int>(hash<thread::id>()(id));
    cout<<"Thread: "<<id<<" a: "<<a<<endl;
    coutMutex.unlock();
}

//Версия кода с блокировками
int main()
{
    double sum =0;
    cout <<"MAAAAAAAAAAAAAAAAAAAAAAIN"<<endl;
    vector<thread> threads;
    for (int i=0; i<8; i++)
    {
        threads.push_back(thread(print_hello, sum));
    }
    //Ожидаем присоединения потока
    for (auto& th: threads)
    {
        if (th.joinable())
        {
            th.join();
        }
    }

    return 0;
}

//Создаем массив потоков
// Потоки будут в состоянии гонки, поэтому текст будет выводиться не одинаково, возможно даже будет так: Hello from thread 2Hello from thread 2
// int main()
// {
//     vector<thread> threads;
//     for (int i=0; i<8; i++)
//     {
//         threads.push_back(thread(print_hello));
//     }
//     cout <<"MAAAAAAAAAAAAAAAAAAAAAAIN"<<endl;
//     //Ожидаем присоединения потока
//     for (auto& th: threads)
//     {
//         if (th.joinable())
//         {
//             th.join();
//         }
//     }

//     return 0;
// }

//Создание потока

// int main()
// {
//     cout <<"MAAAAAAAAAAAAAAAAAAAAAAIN"<<endl;
//     thread thread2(print_hello);
//     thread2.join();
//     return 0;
// }