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
        vector<int> f(n + 1);
        f[0] = 1;
        for (int c = 0; c < 4; ++c)
        {
            int coin = a[c];
            for (int i = coin; i <= n; ++i)
                f[i] = (f[i] + f[i - coin]) % 1000000007;
        }
        return f[n];
    }

    int waysToChange2(int n)
    {
        vector<vector<int>> f(sizeof(a) / sizeof(a[0]) + 1, vector<int>(n + 1));
        f[0][0] = 1;
        for (int i = 1; i <= 4; ++i)
            for (int j = 0; j <= n; ++j)
            {
                if (j >= a[i - 1])
                    f[i][j] = f[i - 1][j] + f[i][j - a[i - 1]];
                else
                    f[i][j] = f[i - 1][j];
            }
        return f[sizeof(a) / sizeof(a[0])][n];
    }

    int waysToChange3(int n)
    {
        vector<vector<int>> f(sizeof(a) / sizeof(a[0]) + 1, vector<int>(n + 1));
        f[0][0] = 1;
        for (int i = 1; i <= 4; ++i)
            for (int j = 0; j <= n; ++j)
                for (int k = 0; k <= j / a[i - 1]; ++k)
                    f[i][j] += f[i - 1][j - k * a[i - 1]];
        return f[sizeof(a) / sizeof(a[0])][n];
    }
};

int main()
{
    Solution solution;
    int num;
    cin >> num;
    cout << solution.waysToChange(num) << endl;
    cout << solution.waysToChange2(num) << endl;
    cout << solution.waysToChange3(num) << endl;
}