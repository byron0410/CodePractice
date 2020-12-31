#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, pEnd = nums1.size() -1;
        while(p1 >= 0 && p2 >= 0)
        {
            if(nums1[p1] > nums2[p2])
                nums1[pEnd--] = nums1[p1--];
            else
                nums1[pEnd--] = nums2[p2--];
        }
        while(p2 >= 0)
        {
            nums1[pEnd--] = nums2[p2--];
        }
    }
};

int main()
{

    vector<int> nums1({0}), nums2({1});
    Solution solu;
    solu.merge(nums1, 1, nums2, 1);
    for (size_t i = 0; i < nums1.size(); ++i)
        cout << nums1[i] << endl;
}

