#include <iostream>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() < 2)
            return s;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            auto [left1, right1] = maxPalindromeBoundary(s, i, i);
            auto [left2, right2] = maxPalindromeBoundary(s, i, i + 1);
            if (right1 - left1 > end - start)
            {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start)
            {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }

private:
    pair<int, int> maxPalindromeBoundary(const string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }
};

int main()
{
    Solution solu;
    string s;
    cin >> s;
    string a = solu.longestPalindrome(s);
    cout << a << endl;
}