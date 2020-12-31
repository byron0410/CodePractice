#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    char c;
    int n = 0;
    getline(cin, s);
    cin >> c;
    for (auto i = s.begin(); i < s.end(); ++i) {
        if (toupper(c) == toupper(*i)) {
            ++n;
        }
    }
    cout << n << endl;
}
