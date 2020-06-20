#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> numbers{5, 46, -5, -6, 23, 17};
    vector<int> numbers2(numbers);
    for (uint16_t i = 0; i < numbers2.size(); ++i)
    {
        cout << "numbers2[" << i << "]: " << numbers2[i] << "   ";
    }
    cout << endl;

    vector<int> numbers3(3, 88);
    for (uint16_t i = 0; i < numbers3.size(); ++i)
    {
        cout << "numbers3[" << i << "]: " << numbers3[i] << "   ";
    }
    cout << endl;

    vector<int> numbers4(4);
    for (uint16_t i = 0; i < numbers4.size(); ++i)
    {
        cout << "numbers4[" << i << "]: " << numbers4[i] << "   ";
    }
    cout << endl;

    vector<string> svec(5, "hi!");
    for (uint16_t i = 0; i < svec.size(); ++i)
    {
        cout << "svec[" << i << "]: " << svec[i] << "   ";
    }
    cout << endl;
    //string d("byron");
    svec.push_back("byron1");
    for (uint16_t i = 0; i < svec.size(); ++i)
    {
        cout << "svec[" << i << "]: " << svec[i] << "   ";
    }

    vector<int> copyConstructor1(10);
    //vector<int> copyConstructor2 = 10;
    
    return 0;
}