#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution
{
private:
    void backTrack(vector<int> nums, list<int> track)
    {

    }
public:
    list<list<int>> permute(vector<int> nums)
    {

    }
};

int main()
{
    Solution ways;
    vector<int> nums;
    int element;
    while (cin >> element)
        nums.push_back(element);

    list<list<int>> ans;
    ans = ways.permute(nums);

    return 0;
}

