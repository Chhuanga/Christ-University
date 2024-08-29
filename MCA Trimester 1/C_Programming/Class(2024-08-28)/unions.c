#include <stdio.h>
#include <string.h>

union UnionName{
    int a;
    float b;
    char c[20];
};
int main()
{
    union UnionName u;
    u.a = 10;
    printf("Size of Union: %d\n", sizeof(u));
    printf("Value of a: %d\n", u.a);
    u.b = 20.5;
    printf("Value of b: %f\n", u.b);
    strcpy(u.c, "Hello");
    printf("Value of c: %s\n", u.c);
    return 0;
}