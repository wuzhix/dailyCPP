/**
 * function�������庯����������
 */
#include <functional>
#include <iostream>

using namespace std;

int add(int x, int y)
{
    return x + y;
}

int main()
{
    function<int(int, int)> func = add;
    cout << func(1, 2) << endl;
    return 0;
}
