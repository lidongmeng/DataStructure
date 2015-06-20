#include <cstdio>
#include <cstring>
#define MAXN 50010

int n, num[MAXN];

int lowbit(int x)
{
    return x&(-x);
}

void update(int i, int val)
{
    while (i <= n)
    {
        num[i] += val;
        i += lowbit(i);
    }
}

int query(int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += num[i];
        i -= lowbit(i);
    }
    return sum;
}

int main()
{
    int t, val, a, b, cnt = 1;
    char str[10];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        memset(num, 0, sizeof(num));
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &val);
            update(i, val);
        }
        printf("Case %d:\n", cnt++);
        while (1)
        {
            str[0] = '\0';
            scanf("%s", str);
            if (strcmp(str, "End") == 0)
                break;
            scanf("%d%d", &a, &b);
            if (strcmp(str, "Add") == 0)
                update(a, b);
            if (strcmp(str, "Sub") == 0)
                update(a, -b);
            if (strcmp(str, "Query") == 0)
               printf("%d\n", query(b)-query(a+-1));
        }
    }
    return 0;
}
