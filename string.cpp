#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string s1;
    //s1 = "hhhh";
    cin >> s1;
    cout << s1 << endl;
    string s2(s1);
    cout << s2 << endl;
    string s3("this is a string");
    cout << s3 << endl;
    string s4(6, '8');
    cout << s4 << endl;

    string s5, s6;
    cin >> s5 >> s6;
    cout << s5 << s6 << endl;

    cout << s1 + s2 + s3 + s4 + s5 + s6 << endl;

    string line;
    getline(cin, line); //getline可以保留空格
    cout << line << endl;

    while (getline(cin, line))
    {
        if (!line.empty())
            cout << line.size() << ": " << line << endl;
    }

    string someThing("some things 123 !!!");
    uint16_t countOfPunctuation = 0;
    for (auto c : someThing)
    {
        cout << c << endl;
        if (ispunct(c))
            countOfPunctuation++;
    }
    cout << countOfPunctuation << endl;
    for (auto &c : someThing)
    {
        c = toupper(c);
    }
    cout << someThing << endl;
    string aaa("hahaha hohoho eieiei");
    for (decltype(aaa.size()) index = 0; index < aaa.size() && !isspace(aaa[index]); ++index)
    {
        aaa[index] = toupper(aaa[index]);
    }
    cout << aaa << endl;

    string voidstring;
    cout << voidstring.size() << endl;

    cout << "hello world" << endl;
    return 0;
}