#include <cstdio>
#include <iostream>
#define MAXN 1000010
using namespace std;

int num[MAXN];
int n, m, q;
void output()
{
    for (int i = 1; i <= n; ++i)
        cout << num[i] << " ";
    cout << endl;
}

int Find(int i)
{
    while (i != num[i])
        i = num[i];
    return i;
}

void Union(int p, int q)
{
    int p_root = Find(p);
    int q_root = Find(q);
    num[p_root] = q_root;
}

bool Connected(int p, int q)
{
    return (Find(p) == Find(q));
}

int main()
{
    int a, b;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i)
        num[i] = i;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &a, &b);
        Union(a, b);
        output();
    }
    for (int i = 1; i <= q; ++i)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", Connected(a, b));
    }
    return 0;
}
