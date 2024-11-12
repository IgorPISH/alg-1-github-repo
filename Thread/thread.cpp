#include <thread>
#include <iostream>
#include <vector>

using namespace std;

void print_hello()
{
    cout<<"Hello from thread 2"<<endl;
}

int main()
{
    cout <<"MAAAAAAAAAAAAAAAAAAAAAAIN"<<endl;
    vector<thread> threads;
    for (int i=0; i<8; i++)
    {
        threads.push_back(thread(print_hello));
    }

    return 0;
}

//Создание потока

// int main()
// {
//     cout <<"MAAAAAAAAAAAAAAAAAAAAAAIN"<<endl;
//     thread thread2(print_hello);
//     thread2.join();
//     return 0;
// }