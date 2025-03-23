#include <stdio.h>
#include <string.h>
int main()
{
    char s[100], t[100], p[100], a[100], b[100];
    gets(s);
    gets(t);
    gets(p);
    // 输入
    int i, yz = 0;
    for (i = 0; t[i] != '\0'; i++)
        ;
    int z;
    for (z = 0; p[z] != '\0'; z++)
        ;
    int n = 0;
    for (int j = 0; s[j] != 0; j++)
    {
        if (t[n] == s[j])
            n = n + 1;
        else
            n = 0; // 判断是否是字串
        if (n == (i - 1))
        {
            strcpy(a, s + (j + 1) - (i - 1));
            strcpy(p + z, a + i);
            strcpy(s + (j + 1) - (i - 1), p); // 删除字串并替换字串
            yz++;
            n = 0;
        }
    }
    if (yz == 0)
        printf("NO");
    else
        printf("%s", s); // 输出
    return 0;
}