#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int seq = 0, flag = 1;
        long ans = 0;
        while(str[seq] == ' ')
            ++seq;
        if(str[seq] == '-')
            flag = -1;
        if(str[seq] == '-' || str[seq] == '+')
            ++seq;
        for( ; seq < str.size() && isdigit(str[seq]); ++seq)
        {
            ans = ans * 10 + (str[seq] - '0');
            if(ans > INT_MAX && flag == 1)
                return INT_MAX;
            if(ans > INT_MAX && flag == -1)
                return INT_MIN;
        }
        return flag * ans;
    }
};

int main()
{
    Solution solu;
    cout << solu.myAtoi("   -42") << endl;
}