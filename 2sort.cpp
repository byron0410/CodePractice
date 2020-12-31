#include <iostream>
#include <vector>

using namespace std                                                                     ;

class Solution                                                                          {
public:                                                                              
    vector<int> shuffle(vector<int>& nums, int n)                                       {
        vector<int> ans(nums)                                                           ;
        int j = 0                                                                       ;
        for (int i = 0; i < 2 * n; i = i + 2)                                           {
            ans[i] = nums[j]                                                            ;
            ++j                                                                         ;}
        j = n                                                                           ;
        for (int i = 1; i < 2 * n; i = i + 2)                                           {
            ans[i] = nums[j]                                                            ;
            ++j                                                                         ;}
        return ans                                                                      ;}};

int main()                                                                              {
    vector<int> a{2,5,1,3,4,7}                                                          ;
    Solution solu                                                                       ;
    vector<int> b                                                                       ;
    b = solu.shuffle(a, 3)                                                              ;
    for (size_t i = 0; i < b.size(); ++i)
        cout << b[i] << endl                                                            ;}