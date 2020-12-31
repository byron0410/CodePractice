#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
    vector<string> workStatus;
    int maxnum = 0;
    int pos = -1;
    cin >> maxnum;
    //独立处理 n 行
    while (maxnum--)
    {
        string s;
        getline(cin, s);
        cout << "停不下来啊" << endl;
        stringstream ss(s);
        //处理输入
        string tmp;
        while (ss >> tmp)
        {
            workStatus.push_back(tmp);
            ++pos;
            if (pos >= 1 && (workStatus[pos] == "late" || workStatus[pos] == "leaveearly") && (workStatus[pos - 1] == "late" || workStatus[pos - 1] == "leaveearly"))
            {
                cout << "false" << " ";
                break;
            }
        }

        if (count(workStatus.begin(), workStatus.end(), "absent") > 1)
        {
            cout << "false" << " ";
            break;
        }
        auto left = workStatus.begin();
        if (workStatus.size() >= 7)
        {
            while (left + 6 != workStatus.end())
            {
                if (count(left, left + 6, "present") < 4)
                {
                    cout << "false" << " ";
                    break;
                }
                ++left;
            }
        }
        else
        {
            if (count(workStatus.begin(), workStatus.end(), "present") < 4)
            {
                cout << "false" << " ";
                break;
            }
        }
        cout << "true" << " ";
        break;
    }
}