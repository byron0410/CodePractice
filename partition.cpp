#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool mycomp(int i)
{
    return i != 0;
}

class Solution {
public:
    void shuffle(vector<int>& nums)
    {
        stable_partition(nums.begin(), nums.end(), mycomp);
    }
    void moveZeroes(vector<int>& nums)
    {
        stable_partition(nums.begin(), nums.end(), [](int a) {return a!= 0;});
    }
};


int main()
{
    vector<int> a{ 2, 5, 1, 0, 3, 4, 7 };
    vector<int> b(a);
    Solution solu;
    solu.shuffle(a);
    for (size_t i = 0; i < a.size(); ++i)
        cout << a[i] << "    ";
    solu.moveZeroes(b);
    for (size_t i = 0; i < b.size(); ++i)
        cout << b[i] << "    ";
}