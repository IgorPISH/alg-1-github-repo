#include <thread> // Для работы с патоками
#include <iostream>
#include <vector>
#include <mutex> //Для работы с блокировками (для предотвращения состояния гонки)

using namespace std;

mutex coutMutex; // Глобальный объект блокировки


void print_hello()
{
    coutMutex.lock();
    cout<<"Hello from thread 2"<<endl;
    coutMutex.unlock();
}

//Версия кода с блокировками
int main()
{
    vector<thread> threads;
    for (int i=0; i<8; i++)
    {
        threads.push_back(thread(print_hello));
    }
    cout <<"MAAAAAAAAAAAAAAAAAAAAAAIN"<<endl;
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