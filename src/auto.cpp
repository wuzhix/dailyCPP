/**
 * auto关键字用来自动适应变量类型，注意auto不能在函数参数中使用
 */
#include <iostream>
#include <vector>

using namespace std;

template<typename T, typename U>
auto add(T x, U y)
{
    return x + y;
}

int main()
{
    int n[] = {1, 2, 3, 4, 5};
    vector<int> a(n, n+5);
    for(auto iter = a.begin(); iter != a.end(); ++iter)
    {
        cout << *iter << endl;
    }
    cout << "add(1, 2.3) = " << add(1, 2.3) << endl;
    return 0;
}
