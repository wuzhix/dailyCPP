/**
 * 四个线程t1,t2,t3,t4,向4个文件中写入数据，t1只能写入1，t2只能写入2，t3只能写入3，t4只能写入4，对4个文件A，B，C，D写入如下内容:
 * A:123412341234.....
 * B:234123412341....
 * C:341234123412....
 * D:412341234123....
 * 怎么实现同步可以让线程并行工作？
 * g++ -g thread.cpp -o thread -pthread -std=c++1y
 */
#include <fstream>
#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <ctime>
#include <sstream>
#include <chrono>

using namespace std;
using namespace chrono;

const int num = 4;

mutex mtx[num];

void func(shared_ptr<ofstream> os, int start)
{
    int id = start;
    int count = 0;
    while(true)
    {
        int cur;
        if (start == 1)
        {
            cur = num-1;
        }
        else
        {
            cur = start-1;
        }
        mtx[cur].lock();
        cout << "thread " << id << " : " << start << "\n";
        *os << start;
        mtx[cur].unlock();
        if (start == num)
        {
            start = 1;
        }
        else
        {
            start++;
        }
        if (++count > 100)
        {
            break;
        }
    }
}

int main()
{
    shared_ptr<ofstream> f[num];
    shared_ptr<thread> t[num];
    for (int i = 0; i < num; ++i)
    {
        ostringstream oss;
        oss << i+1 << ".txt";
        auto filename = oss.str();
        f[i] = make_shared<ofstream>(filename);
    }
    auto s1 = system_clock::now();;
    for (int i = 0; i < num; ++i)
    {
        t[i] = make_shared<thread>(func, f[i], i+1);
        //t[i]->join();
        //f[i]->close();
    }
    for (int i = 0; i < num; ++i)
    {
        t[i]->join();
        f[i]->close();
    }
    auto e1 = system_clock::now();
    auto duration = duration_cast<microseconds>(e1 - s1);
    cout << "mutex time : " << double(duration.count()) * microseconds::period::num / microseconds::period::den << endl;
    return 0;
}
