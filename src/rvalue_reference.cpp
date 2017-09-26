/**
 * ��ֵ����
 */
#include <iostream>

using namespace std;

class A
{
public:
    A():pointer(new int(1))
    {
        cout << "����" << pointer << endl;
    }
    A(A& a):pointer(new int(*(a.pointer)))
    {
        cout << "����" << pointer << endl;
    }
    A(A&& a):pointer(a.pointer)
    {
        /**
         �����������ֵΪnullptr���ƶ�������ɺ󣬻����A��������������Ϊa.pointer���ƶ�������pointer��ͬһ�����������󶼻ᱻ������
         ��ֵΪnullptr���ƶ�������ɺ󣬵���A��������������ʱa.pointerΪnullptr��������delete�ƶ���Ķ���
         */
        a.pointer = nullptr;
        cout << "�ƶ�" << endl;
    }
    ~A()
    {
        if (pointer != nullptr)
        {
            cout << "����" << pointer << endl;
            delete pointer;
            pointer = nullptr;
        }
    }
    fun() {cout << *pointer << endl;}
private:
    int* pointer;
};

A return_rvalue(bool test)
{
    A a, b;
    if (test)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void refer(int& v)
{
    cout << "��ֵ" << v << endl;
}

void refer(int&& v)
{
    cout << "��ֵ" << v << endl;
}

// ����ô������ڵģ��ǲ���������
template<typename T>
void pass(T&& v)
{
    refer(v);
    refer(move(v));
    refer(forward<T>(v));
}

int main()
{
    int v = 1;
    pass(v);
    pass(1);

    A a;
    A obj1 = a;
    A obj2 = move(a);
    A obj3 = return_rvalue(false);
    return 0;
}
