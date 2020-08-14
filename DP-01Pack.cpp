#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int w[5] = {0, 2, 3, 4, 5}; //商品的体积2、3、4、5
    int v[5] = {0, 3, 4, 5, 6}; //商品的价值3、4、5、6
    int bagV = 8;               //背包大小
    int dp[9] = {0}, a;    //动态规划表

    for (int i = 1; i <= 4; i++)
        {
            for (int j = bagV; j >= w[i]; j--)
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

            for (int j = 0; j < 9; j++)
                cout << dp[j] << "    ";
            cout << endl;
        }
    cout << dp[bagV] << endl;
    //动态规划表的输出
    //for (int i = 0; i < 5; i++)
        for (int j = 0; j < 9; j++)
            cout << dp[j] << ' ';
        cout << endl;
    return 0;
}
