#include <iostream>
#include <string>

using namespace std;

int find_char(const string &s, char c, int &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i)
    {
        if (s[i] == c)
        {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}

int main()
{
    string s("gsdgasiudgaiussssdgi");
    int a = 0;
    int b = find_char(s, 's', a);
    cout << b << "-----" << a << endl;
    return 0;
}