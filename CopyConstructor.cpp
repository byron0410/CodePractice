#include <iostream>
using namespace std;

class numbered
{
private:
    static int seq;

public:
    numbered()
    {
        cout << "调用了默认构造函数" << endl;
        mysn = seq++;
    }
    numbered(const numbered &s)
    {
        cout << "调用了拷贝构造函数" << endl;
        mysn = seq++;
    }
    int mysn;
};

int numbered::seq = 0;

// 在函数调用中，非引用参数要进行拷贝初始化
//void f(numbered s)
void f(numbered &s)
{
    cout << s.mysn << endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}