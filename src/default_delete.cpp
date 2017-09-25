/**
 * default和delete的使用
 */
#include <iostream>

using namespace std;

class Magic
{
public:
    Magic() = default;
    Magic& operator=(const Magic&) = delete;
    Magic(int v);
};

Magic::Magic(int v)
{

}

int main()
{
    Magic a;
    Magic b(10);
    Magic c(a);
    //c = b;    //error
    return 0;
}
