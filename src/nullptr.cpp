/**
 * 有的编译器会将NULL定义为(void*)0，有的会定义为0，nullptr用来区分空指针和0
 */
#include <iostream>

using namespace std;

void foo(char*);
void foo(int);
int main()
{
    if(NULL == (void*)0)
    {
        cout << "NULL == 0" << endl;
    }
    else
    {
        cout << "NULL != 0" << endl;
    }

    foo(0);
    foo(NULL);  //产生警告
    foo(nullptr);
    /**
    输出
    NULL == 0
    call foo)(int)
    call foo)(int)
    call foo(char*)
     */

    return 0;
}

void foo(char* ch)
{
    cout << "call foo(char*)" << endl;
}

void foo(int i)
{
    cout << "call foo)(int)" << endl;
}
