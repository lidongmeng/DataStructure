#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#define MAXN 10010
#define MAXE 20
using namespace std;
int n, q;
int to[100010];

void pre_log()
{
    int i;
    to[0] = to[1] = 0;
    for(i = 1; i*2 < 10010; i++)
        to[i*2] = to[i*2+1] = to[i] + 1;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

struct RMQ_ST
{
    int p[MAXN][MAXE];
    int (*cmp)(int , int);
    void build(int a[], int (*f)(int, int))
    {
        cmp = f;
        for (int i = 1; i <= n; ++i)
            p[i][0] = a[i];
        for (int j = 1; (1<<j) <= n; ++j)
        {
            for (int i = 1; i+(1<<j)-1 <= n; ++i)
                {
                    p[i][j] = f(p[i][j-1], p[i+(1<<(j-1))][j-1]);
                }
        }
    }
    int get(int l, int r)
    {
        //int k = log(r-l+1.0)/log(2.0);
        int k = to[r-l];
        return cmp(p[l][k], p[r-(1<<k)+1][k]);
    }
};

RMQ_ST st1, st2, st3;
int nums[MAXN];
int pre[MAXN];

int main()
{
    int cnt = 1, k, result;
    map<int, int> mp;
    map<int, int>::iterator iter;
    memset(pre, 0, sizeof(pre));
    memset(nums, 0, sizeof(nums));
    while (scanf("%d%d", &n, &q) != EOF)
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &nums[i]);
            iter = mp.find(nums[i]);
            if (iter != mp.end())
                pre[i] = iter->second;
            mp[nums[i]] = i;
        }
        pre_log();
        st1.build(nums, max);
        st2.build(nums, min);
        st3.build(pre, max);
        printf("Case #%d:\n", cnt++);
        for (int i = 1; i <= q; ++i)
        {
            result = 0;
            scanf("%d", &k);
            for (int i = 1; i+k-1 <= n; ++i)
            {
                int Max = st1.get(i, i+k-1);
                int Min = st2.get(i, i+k-1);
                int maxIndex = st3.get(i, i+k-1);
                //cout << "i: " << i << "  " << "max: " << Max << "  min: " << Min << "  index: " << maxIndex << endl;
                if (Max != Min+k-1 || maxIndex >= i)
                    continue;
                result++;
            }
            printf("%d\n", result);
        }
    }
    return 0;
}
