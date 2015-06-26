#include <cstdio>
#include <iostream>
#define MAXN 100010
using namespace std;

int n, m, q, Rank[MAXN], Father[MAXN];

void output()
{
    for (int i = 1; i <= n; ++i)
        cout << Father[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; ++i)
        cout << Rank[i] << " ";
    cout << endl;
}

void Make_set()
{
    for (int i = 1; i <= n; ++i)
    {
        Rank[i] = 1;
        Father[i] = i;
    }
}

int Find_root(int i)
{
    if (i != Father[i])
    {
        Father[i] = Find_root(Father[i]);
    }
    return Father[i];
}

void Union(int a, int b)
{
    int a_root = Find_root(a);
    int b_root = Find_root(b);
    if (Rank[a_root] < Rank[b_root])
    {
        Rank[b_root] += Rank[a_root];
        Father[a_root] = b_root;
    }
    else
    {
        Rank[a_root] += Rank[b_root];
        Father[b_root] = a_root;
    }
}

bool Connected(int a, int b)
{
    return Find_root(a) == Find_root(b);
}

int main()
{
    int a, b;
    scanf("%d%d%d", &n, &m, &q);
    Make_set();
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &a, &b);
        Union(a, b);
        output();
    }
    for (int i = 1; i <= q; ++i)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", Connected(a,b));
    }
    return 0;
}
