#include <iostream>

using namespace std;

int main()
{
    int r1 = 100;
    const int &y1 = r1; //允许const int& 绑定到普通int对象上，而不能反过来
    cout << y1 << endl;

    const int &y2 = 45; //非常量引用初始值必须为左值
    const int &y3 = y2 * 2;
    // int &y4 = y2 * 2;

    const double pii = 3.1415926;
    const double *ptr = &pii;
    //double *ptr1 = &pii;
    const double *const prt2 = &pii; //指向常量的常量指针

    int errNumb = 0;
    int *const curErr = &errNumb;

    //int null = 0, *p = null;

    const int i =42;
    auto j = i;
    const auto &k = i;

    cout << "hello world" << endl;
    return 0;
}