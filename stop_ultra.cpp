#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    int dp(int target, int maxNum)
    {
        if (target <= 0)
            return 1;
        if (maxNum <= 0)
            return 0;
        int sum = 0, cnt = 0;
        int i;
        stack<int> sk;
        while (true)
        {
            if (sum <= target)
            {
                ++cnt;
                while (sum <= target)
                {
                    sk.push(1);
                    ++sum;
                }
            }
            sum -= sk.top();
            sk.pop();
            //if (sum == target) printPath(sk);
            while (!sk.empty() && sk.top() == maxNum)
            {
                sum -= sk.top();
                sk.pop();
            }
            if (!sk.empty())
            {
                i = sk.top() + 1;
                sum -= sk.top();
                sk.pop();
                sk.push(i);
                sum += i;
            }
            else
            {
                return cnt;
            }
        }
    }

private:
    void printPath(stack<int> &sk)
    {
        stack outsk(sk);
        cout << "path: ";
        while (!outsk.empty())
        {
            cout << outsk.top() << "    ";
            outsk.pop();
        }
        cout << endl;
    }
};

int main()
{
    int target, maxNum, mustAbove;
    cin >> target >> maxNum >> mustAbove;
    Solution fun;
    int ans = 0;
    // if (mustAbove > 1)
    //     ans = (fun.dp(target, maxNum) - fun.dp(target, mustAbove - 1)) % 998244353;
    // else
    //     ans = fun.dp(target, maxNum) % 998244353;
    // cout << ans << endl;
    cout << fun.dp(target, maxNum) << endl;
    // cout << fun.dp(target, mustAbove - 1) << endl;
    return 0;
}
