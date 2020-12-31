#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; ++i)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            int k = size - 1;
            int target = -nums[i];
            for (int j = i + 1; j < size; ++j)
            {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                while (k > j && nums[j] + nums[k] > target)
                    --k;
                if (k == j)
                    break;
                if (nums[j] + nums[k] == target)
                    res.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums({-4,-3,-1,0,0,0,1,3,4});
    vector<vector<int>> ans;
    Solution solu;
    ans = solu.threeSum(nums);
    for (size_t i = 0; i < ans.size(); ++i)
    {
        for (size_t j = 0; j < ans[0].size(); ++j)
            cout << ans[i][j] << "     ";
        cout << endl;
    }
}