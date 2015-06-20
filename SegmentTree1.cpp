#include <cstdio>
#include <cstring>

struct Node
{
    int left, right, sum;
};

int a[50005], n, t, cnt, index, value;
char str[20];
Node nodes[200010];

void buildTree(int i, int left, int right)
{
    nodes[i].left = left;
    nodes[i].right = right;
    if (left == right)
        nodes[i].sum = a[left];
    else
    {
        int mid = (left+right)>>1;
        buildTree(i<<1, left, mid);
        buildTree(i<<1|1, mid+1, right);
        nodes[i].sum = nodes[i<<1].sum + nodes[i<<1|1].sum;
    }
}

void updateTree(int i, int left, int v, int flag)
{
    nodes[i].sum += v*flag;
    if (nodes[i].left == nodes[i].right)
        return ;
    else
    {
        int mid = (nodes[i].left + nodes[i].right)>>1;
        if (left <= mid)
            updateTree(i<<1, left, v, flag);
        else
            updateTree(i<<1|1, left, v, flag);
    }
}

int queryTree(int i, int left, int right)
{
    int mid = (nodes[i].left+nodes[i].right)>>1;
    if (nodes[i].left == left && nodes[i].right == right)
        return nodes[i].sum;
    if (right <= mid)
        return queryTree(i<<1, left, right);
    if (left >= mid+1)
        return queryTree(i<<1|1, left, right);
    if (left <= mid && right >= mid+1)
        return queryTree(i<<1, left, mid) + queryTree(i<<1|1, mid+1, right);
}

int main()
{
    scanf("%d", &t);
    cnt = 0;
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        printf("Case %d:\n", (++cnt));
        buildTree(1, 1, n);
        while (1)
        {
            str[0] = '\0';
            scanf("%s", str);
            if (strcmp(str, "End") == 0)
                break;
            scanf("%d%d", &index, &value);
            if (strcmp(str, "Add") == 0)
                updateTree(1, index, value, 1);
            if (strcmp(str, "Sub") == 0)
                updateTree(1, index, value, -1);
            if (strcmp(str, "Query") == 0)
               printf("%d\n", queryTree(1, index, value));
        }
    }
    return 0;
}
