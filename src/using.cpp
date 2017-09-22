/**
 * using可以用来定义类型，比typedef更直观
 */
#include <iostream>

using namespace std;

int test(int* p)
{
    if(p == nullptr)
    {
        return 0;
    }
    else
    {
        return *p;
    }
}

int main()
{
    using func = int(*)(int*);
    func f = &test;
    int a = 5;
    cout << "f(a) : " << f(&a) << ", f(nullptr) : " << f(nullptr) << endl;
    return 0;
}
