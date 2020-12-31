#include <iostream>

#define mal(x,y) (x*y)

int main()
{
 int i = 3;
 int a;
 char **b[5][6];
 a = mal(i++, sizeof(b) + 5);
 printf("%d\n", i);
 printf("%d\n", i++);
 printf("%d\n", sizeof(b));
 printf("%d\n", a);
 return 0;
}