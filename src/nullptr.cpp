/**
 * �еı������ὫNULL����Ϊ(void*)0���еĻᶨ��Ϊ0��nullptr�������ֿ�ָ���0
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
    foo(NULL);  //��������
    foo(nullptr);
    /**
    ���
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
