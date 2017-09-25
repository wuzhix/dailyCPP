/**
 * 模板变长参数
 */
#include <iostream>

using namespace std;

template<typename... Args>
void func(Args... args)
{
    cout << sizeof...(args) << endl;
}

template<typename T>
void print(T v)
{
    cout << v << endl;
}

template<typename T, typename... Args>
void print(T v, Args... args)
{
    cout << v << ' ';
    print(args...);
}

int main()
{
    func();
    func(1);
    func(1, "");
    func(1, "", false);
    print(1, "-", false, 1.3);
    return 0;
}
