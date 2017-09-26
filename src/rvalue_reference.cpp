/**
 * 右值引用
 */
#include <iostream>

using namespace std;

class A
{
public:
    A():pointer(new int(1))
    {
        cout << "构造" << pointer << endl;
    }
    A(A& a):pointer(new int(*(a.pointer)))
    {
        cout << "拷贝" << pointer << endl;
    }
    A(A&& a):pointer(a.pointer)
    {
        /**
         这里如果不赋值为nullptr，移动构造完成后，会调用A的析构函数，因为a.pointer和移动后对象的pointer是同一个，两个对象都会被析构。
         赋值为nullptr，移动构造完成后，调用A的析构函数，此时a.pointer为nullptr，并不会delete移动后的对象
         */
        a.pointer = nullptr;
        cout << "移动" << endl;
    }
    ~A()
    {
        if (pointer != nullptr)
        {
            cout << "析构" << pointer << endl;
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
    cout << "左值" << v << endl;
}

void refer(int&& v)
{
    cout << "右值" << v << endl;
}

// 搞这么花里胡哨的，是不是作死？
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
