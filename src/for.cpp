/**
 * for�﷨������ѭ�����
 */
#include <iostream>

using namespace std;

int main()
{
    int n[] = {1, 2, 3, 4, 5};
    // ���ñ���
    for(auto& i : n)
    {
        cout << i << ' ';
    }
    cout << endl;
    // ֵ����
    for(auto i : n)
    {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
