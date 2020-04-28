// 1,5,10,25元构成v元的方案数量
// f(i,v) 前i种构成面值v 的方案数量
// f(i,v) = f(i-1, v) + f(i, v-ci)
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    const int a[4] = {25, 10, 5, 1};

public:
    int waysToChange(int n)
    {
        vector<long> f(n + 1);
        f[0] = 1;
        for (int c = 0; c < 4; ++c)
        {
            int coin = a[c];
            for (int i = coin; i <= n; ++i)
                f[i] = (f[i] + f[i - coin]) % 1000000007;
        }
        return f[n];
    }
};

int main()
{
    Solution solution;
    cout << solution.waysToChange(30) << endl;
}