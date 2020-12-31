/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MountainArray
{
public:
    int get(int index);
    int length();
};

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int len = 0;
        len = mountainArr.length();
        vector<int> arr, arr2;
        for (int i = 0; i < len; ++i)
        {
            arr.push_back(mountainArr.get(i));
            if (i >= 1)
                if (arr[i] < arr[i - 1])
                    break;
        }
        for (int i = 0; i < arr.size(); ++i)
        {
            if (arr[i] == target)
                arr2.push_back(i);
        }
        vector<int>::iterator min = min_element(arr2.begin(), arr2.end());
        if (arr2.size() == 0)
            return -1;
        else
            return *min;
    }
};