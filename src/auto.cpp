/**
 * auto�ؼ��������Զ���Ӧ�������ͣ�ע��auto�����ں���������ʹ��
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
