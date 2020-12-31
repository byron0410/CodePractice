#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1, area = 0;
        while (l < r)
        {
            area = max(min(height[l], height[r]) * (r - l), area);
            if (height[l] > height[r])
                --r;
            else
                ++l;
        }
        return area;
    }
};

int main()
{
    vector<int> nums({15, 48, 4, 4, 4, 4, 4, 4, 4, 88, 0, 0, 9, 8, 7, 6});
    int ret;
    Solution solu;
    ret = solu.maxArea(nums);
    //for (size_t i = 0; i < nums.size(); ++i)
    cout << ret << endl;
}
