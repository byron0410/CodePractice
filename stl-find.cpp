#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> numbers{5, 46, -5, -6, 23, 17, 5, 9, 6, 5};
    int value=17;
    auto iter = find(begin(numbers), end(numbers), value);
    if (iter != end(numbers))
    {
        cout << value << " was found" << endl;
        auto index1 = distance(begin(numbers), iter);
        auto index2 = iter - begin(numbers);
        cout << index1 << " is the index of " << value << endl;
        cout << index2 << " is the index of " << value << endl;
    }
    else
    {
        cout << "not position" << endl;
    }

    string s = "Alice Bob Charlie";
    size_t position = 0;
    position = s.find('B');
    if (position != string::npos)
        cout << "Found! position is : " << position << endl;
    else
        cout << "Not found!" << endl;

    size_t count{};
    int five{5};
    auto start_iter = begin(numbers);
    auto end_iter = end(numbers);
    while ((start_iter = find(start_iter, end_iter, five)) != end_iter)
    {
        ++count;
        ++start_iter;
    }
    cout << five << " was found " << count << " times." << endl;

    return 0;
}
