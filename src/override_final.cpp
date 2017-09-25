/**
 * override和final的使用
 */
#include <iostream>

using namespace std;

class Base
{
public:
    virtual void func();
};

class SubClass : public Base
{
public:
    virtual void func() override;   //ok
    //virtual void fun() override;    //error
};

class Base1
{
public:
    virtual void func() final;
};

class Base2 final
{

};

//error
/*class SubClass1 : public Base2
{

};*/

class SubClass2 : public Base1
{
public:
    //virtual void func();    //error
};

int main()
{
    return 0;
}
