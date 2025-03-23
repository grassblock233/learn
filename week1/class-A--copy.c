#include <stdio.h>
#include <string.h>

double calculate(char *s)
{
    int n = strlen(s);
    int ops[n], top = 0;
    int sign = 1;
    ops[top++] = sign;

    double ret = 0;
    int i = 0;
    while (i < n)
    {
        if (s[i] == ' ')
        {
            i++;
        }
        else if (s[i] == '+')
        {
            sign = ops[top - 1];
            i++;
        }
        else if (s[i] == '-')
        {
            sign = -ops[top - 1];
            i++;
        }
        else if (s[i] == '(')
        {
            ops[top++] = sign;
            i++;
        }
        else if (s[i] == ')')
        {
            top--;
            i++;
        }
        else
        {
            double num = 0; // 将long改为double
            while (i < n && s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + (s[i] - '0'); // 正确转换为double
                i++;
            }
            ret += sign * num;
        }
    }
    return ret;
}

int main()
{
    char s[1024];
    double ans;
    gets(s);
    ans = calculate(s);
    printf("%lf", ans);
}