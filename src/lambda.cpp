/**
 * lambda语法 ：[捕获列表](参数列表) mutable(可选) 异常属性 -> 返回类型 {//函数体}
 * 捕获选项
 * []        //未定义变量.试图在Lambda内使用任何外部变量都是错误的.
 * [x, &y]   //x 按值捕获, y 按引用捕获.
 * [&]       //用到的任何外部变量都隐式按引用捕获
 * [=]       //用到的任何外部变量都隐式按值捕获
 * [&, x]    //x显式地按值捕获. 其它变量按引用捕获
 * [=, &z]   //z按引用捕获. 其它变量按值捕获
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[] = {1,3,2,9,5,8,4,7};
    sort(a, a+sizeof(a)/sizeof(a[0]), [](auto v1, auto v2){return v1 < v2;});
    for(auto v : a)
    {
        cout << v << " ";
    }
    return 0;
}
