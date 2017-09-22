/**
 * for语法用来简化循环语句
 */
#include <iostream>

using namespace std;

int main()
{
    int n[] = {1, 2, 3, 4, 5};
    // 引用遍历
    for(auto& i : n)
    {
        cout << i << ' ';
    }
    cout << endl;
    // 值遍历
    for(auto i : n)
    {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
