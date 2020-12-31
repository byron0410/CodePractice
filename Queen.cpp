#include <iostream>
using namespace std;
int ans[10], sum = 0;
bool row[9], line1[20], line2[9];
void print()
{
    sum ++;
    for (int i=1; i<=8; i++)
        cout << ans[i] << " ";
    cout << endl;
}
 
void f(int step)
{
    for (int i=1; i<=8; i++)
    {
        if (row[i] == false && line1[step+i] == false && line2[8+step-i] == false)
        {
            ans[step] = i;
            if (step == 8)
                print();
            row[i] = true;
            line1[step+i] = true;
            line2[8+step-i] = true;
            f(step + 1);
            row[i] = false;
            line1[step+i] = false;
            line2[8+step-i] = false;
        }
    }
}
 
int main()
{
    f(1);
    cout << sum << endl;
    return 0;
}