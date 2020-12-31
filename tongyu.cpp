
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

class A
{
public:
    A() { cout << "123\n"; }
    ~A() { cout << "456\n"; }
};

int main()
{
    A *a = new A[5];
    delete a;
    return 0;
}